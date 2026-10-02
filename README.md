# Arduino Line Follower Robot

This repository contains the code and circuit details for a basic Line Follower Robot built using an Arduino UNO.

## 🛠️ Components Used
* Arduino UNO
* L298N Motor Driver
* 2x IR Sensors
* 2x BO Motors and Wheels
* Caster Wheel
* 9V/12V Battery
* Chassis & Jumper Wires

## 🔌 Circuit Connections
* **L298N IN1, IN2, IN3, IN4** -> Arduino Pins 8, 9, 10, 11
* **Left IR Sensor OUT** -> Arduino Pin 2
* **Right IR Sensor OUT** -> Arduino Pin 3
* **Power:** 12V battery connected to L298N 12V terminal, L298N 5V to Arduino VIN. Common Ground (GND).

## 🚀 How it Works
The robot uses two IR sensors to detect a black line on a white surface. 
* White surface reflects light -> Sensor Output is LOW (0)
* Black line absorbs light -> Sensor Output is HIGH (1)
The Arduino reads these values and controls the motors via the L298N driver to keep the robot on the line.

## 📸 Images / Circuit Diagram
*(Note: Upload your images to the repo and add their links here)*
![Circuit Diagram](link_to_your_uploaded_circuit_image.jpg)
