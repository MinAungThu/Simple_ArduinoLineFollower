# Simple_ArduinoLineFollower

Overview

This is a Line Follower Robot that follows a black line using IR sensors and unloads its carried object at specific points. The robot only starts moving when an object is detected in its payload carrier.

Features:

Line Following: Uses 5 IR sensors to follow a black line path.

Object Detection: Uses an ultrasonic sensor to check if an object is present in the payload carrier.

Payload Unloading: Uses a servo motor to unload the carried object when certain conditions are met.

Auto Start: The robot begins moving only when an object is detected.

![Alt text](assets/Screen Shot 2025-03-23 at 18.41.57.png)


Hardware Components

Arduino Board

5x IR Sensors

Ultrasonic Sensor (HC-SR04)

Servo Motor

2 DC Motors + Motor Driver

Power Supply/Battery

How It Works

Object Detection:The ultrasonic sensor checks if there's an object within 10 cm. The robot waits until an object is placed in its carrier.

Line Following:Once the object is detected, the robot starts moving and follows the black line using the 5 IR sensors.

Payload Unloading:When all IR sensors detect black (stop condition), the robot stops. The servo motor rotates to unload the payload.

Repetition:The robot repeats the process until it reaches the stop condition 4 times, after which it halts permanently.

Pin Configuration

Component

Arduino Pin

Motor 1 Enable

10

Motor 1 Direction

5, 4

Motor 2 Enable

9

Motor 2 Direction

2, 3

IR Sensors

A0 - A4

Ultrasonic Trig

7

Ultrasonic Echo

6

Servo Motor

12

Usage

Upload the code to your Arduino.

Place the robot on the black line track.

Put an object in the payload carrier.

The robot will start following the line and unload the object automatically at specific conditions.

Future Improvements

Add obstacle avoidance.

Use PID control for smoother line following.

Enhance payload unloading mechanism.

License:This project is open-source under the MIT License.

