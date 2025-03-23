# Line Follower Robot with Object Detection & Payload Unloading

## Overview

This is a Line Follower Robot that follows a black line using IR sensors and unloads its carried object at specific points. The robot only starts moving when an object is detected in its payload carrier.

---

![Line Follower Robot](./assets/robot.png)

## Features

- **Line Following**: Uses 5 IR sensors to follow a black line path.
- **Object Detection**: Uses an ultrasonic sensor to check if an object is present in the payload carrier.
- **Payload Unloading**: Uses a servo motor to unload the carried object when certain conditions are met.
- **Auto Start**: The robot begins moving only when an object is detected.

---

## Hardware Components

- Arduino Board
- 5x IR Sensors
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- 2 DC Motors + Motor Driver
- Power Supply/Battery

---

## How It Works

1. **Object Detection**:  
   The ultrasonic sensor checks if there's an object within 10 cm. The robot waits until an object is placed in its carrier.

2. **Line Following**:  
   Once the object is detected, the robot starts moving and follows the black line using the 5 IR sensors.

3. **Payload Unloading**:  
   When all IR sensors detect black (stop condition), the robot stops. The servo motor rotates to unload the payload.

4. **Repetition**:  
   The robot repeats the process until it reaches the stop condition 4 times, after which it halts permanently.

---

## Pin Configuration

| Component         | Arduino Pin   |
|-------------------|---------------|
| Motor 1 Enable    | 10            |
| Motor 1 Direction | 5, 4          |
| Motor 2 Enable    | 9             |
| Motor 2 Direction | 2, 3          |
| IR Sensors        | A0 - A4       |
| Ultrasonic Trig   | 7             |
| Ultrasonic Echo   | 6             |
| Servo Motor       | 12            |


