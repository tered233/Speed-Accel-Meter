## Speed Accel Meter 🚀

An Arduino-based project that measures both average speed and acceleration of a moving object using 3 IR sensors and a 16x2 LCD display.
This project is designed for students, hobbyists, and makers who want to combine physics and electronics in a fun and practical way.

## ⚙️ Features

Measures average speed (km/h) across the full track.

Calculates acceleration (m/s²) between the first and last sensor.

Displays results in real-time on a 16x2 LCD.

Handles both positive and negative acceleration (deceleration).

Compact, easy-to-build, and fully open-source.

## 🔌 Hardware Required

Arduino Uno (or compatible board)

LCD 16x2 Display (connected via pins 12, 11, 5, 4, 3, 2)

3x IR line-tracking sensors (digital output)

Breadboard and jumper wires

## 🛠️ Wiring Guide

LCD (16x2):

RS -> Pin 12  
EN -> Pin 11  
D4 -> Pin 5  
D5 -> Pin 4  
D6 -> Pin 3  
D7 -> Pin 2  


Sensors:

OUT1 -> A0  
OUT2 -> A1  
OUT3 -> A2  
VCC  -> 5V  
GND  -> GND  

## 📐 How It Works

When an object passes each sensor, the time is recorded.

Using the known distance (8 cm between each sensor), the program calculates:

Average speed across the full path.

## 🎯 Applications

Physics experiments (kinematics).

Robotics projects.

Speed and acceleration measurement for small objects.

Learning project for beginners with Arduino.

## 📸 video

https://github.com/user-attachments/assets/ec49ed80-8040-4761-80b9-43c51f07203b

## telegram

https://t.me/CodeHub3363
