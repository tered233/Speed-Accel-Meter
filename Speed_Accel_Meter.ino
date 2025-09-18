#include <LiquidCrystal.h>

// LCD pins: RS=12, EN=11, D4=5, D5=4, D6=3, D7=2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Sensors connected to analog pins
const int sensor[3] = {A0, A1, A2};

// Distances between sensors (in meters)
const float distance[2] = {0.08, 0.08}; // distance sensor1->2 and sensor2->3
const float totalDistance = distance[0] + distance[1]; // total track distance

// Timestamps when object passes each sensor
unsigned long triggerTime[3] = {0, 0, 0};

// Sensor status flags
bool triggered[3] = {false, false, false};

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Speed Detector");
  lcd.setCursor(0,1);
  lcd.print("Powered by Mahdi");

  // Set sensor pins as input
  for (int i = 0; i < 3; i++) {
    pinMode(sensor[i], INPUT);
  }

  delay(2000);
  resetSystem();
}

void loop() {
  // Check sensors for object passing
  for (int i = 0; i < 3; i++) {
    int val = digitalRead(sensor[i]);
    if (val == LOW && !triggered[i]) {
      triggerTime[i] = millis(); // record time in ms
      triggered[i] = true;
    }
  }

  // When object has passed all sensors -> calculate speed & acceleration
  if (triggered[2]) {
    // Average speed over the full distance (m/s and km/h)
    float totalTime = (triggerTime[2] - triggerTime[0]) / 1000.0;
    float avgSpeedMS = totalDistance / totalTime;
    float avgSpeedKmh = avgSpeedMS * 3.6;

    // Instant speeds between sensor1->2 and sensor2->3
    float speed1 = distance[0] / ((triggerTime[1] - triggerTime[0]) / 1000.0);
    float speed2 = distance[1] / ((triggerTime[2] - triggerTime[1]) / 1000.0);

    // Acceleration (m/s^2), can be positive or negative
    float timeInterval = (triggerTime[2] - triggerTime[0]) / 1000.0;
    float acceleration = (speed2 - speed1) / timeInterval;

    // Show results on LCD
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Avg:");
    lcd.print(avgSpeedKmh,1);
    lcd.print(" km/h");

    lcd.setCursor(0,1);
    lcd.print("Acc:");
    lcd.print(acceleration,2);
    lcd.print(" m/s2");

    delay(3000); // Display results for 3 seconds
    resetSystem();
  }
}

void resetSystem() {
  // Reset sensors state and timers
  for (int i = 0; i < 3; i++) {
    triggered[i] = false;
    triggerTime[i] = 0;
  }

  // Display idle message
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ready...");
  lcd.setCursor(0,1);
  lcd.print("Powered by Mahdi");
}
