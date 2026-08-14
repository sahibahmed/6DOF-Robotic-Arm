# 6DOF-Robotic-Arm

![6-DOF Robotic Arm](docs/images/robotic-arm.jpg)

A 6-degree-of-freedom robotic arm developed using an Arduino UNO R3,
PCA9685 PWM servo driver, and dual joystick control.

## Documentation

[View Full Project Documentation](docs/documentation/6DOF-Robotic-Arm-Documentation.pdf)

## Current Features
- 6-DOF servo-based robotic arm
- Dual-joystick manual control
- Velocity-style joint movement
- I2C communication with PCA9685
- Joint angle constraints
- Push-button gripper control
- Defined startup/home position

## Demo Videos

- [Manual Pick-and-Place Demo 1](docs/videos/manual-pick-and-place-demo-1.mp4)
- [Manual Pick-and-Place Demo 2](docs/videos/manual-pick-and-place-demo-2.mp4)

## Hardware
- Arduino UNO R3
- PCA9685 16-channel PWM servo driver
- 2× MG996R servos
- DS3225 high-torque servo
- 3× MG90S servos
- 2× KY-023 joystick modules
- External servo power supply

## Software
The firmware is written in C++ using PlatformIO. The Arduino reads
the joystick inputs and communicates with the PCA9685 through I2C.
Servo positions are incremented while a joystick is held and remain
at their last position when the joystick returns to center.

## Project Documentation
Detailed documentation covering the design process, hardware,
software development, testing, debugging, and future improvements
is included in this repository.

## Future Improvements
- Inverse kinematics
- Vision-assisted pick-and-place
- Play-and-record movement
- Improved joint speed control
- Weighted electronics/base enclosure

## Credits
The original mechanical design is based on the open-source robotic
arm by How To Mechatronics.