# Car Automation using Arduino

## Project Overview

This project focuses on creating an automatic car wiper and window system using Arduino and a rain sensor. The system detects rain and automatically activates the car wipers and closes the windows, adjusting the speed of the wipers based on the intensity of the rainfall. This automation aims to enhance driver safety and comfort by minimizing manual intervention.

## Table of Contents

1. [Introduction](#introduction)
2. [Components Required](#components-required)
3. [Project Structure](#project-structure) 
4. [Circuit Diagram](#circuit-diagram)
5. [Implementation](#implementation)
6. [Conclusion](#conclusion)

## Introduction

Driver safety is a critical concern in the automotive industry. One common issue is the lack of proper vision during heavy rainfall, often due to manual errors in adjusting the wiper speed. This project addresses this issue by proposing an automatic rain-sensing wiper and window system. The system detects rain and starts automatically, adjusting the wiper speed based on the rainfall intensity. 

## Components Required

- Arduino UNO
- Rain Sensor Module
- Servo Motors
- 16x2 LCD Module with I2C
- Breadboard
- Jumper Wires

### About the Components

1. **Arduino UNO**: A microcontroller board used for controlling hardware and electronics.
2. **Rain Sensor Module**: Senses rain droplets and sends information to Arduino.
3. **Servo Motors**: Used to move the wipers and close the windows.
4. **16x2 LCD Module with I2C**: Displays the intensity of rainfall and other information.


## Project Structure
**code/:** Contains the source code (.ino file) for Arduino UNO.<br/>
**diagrams/:** Contains the circuit diagram and block diagram of the project.<br/>
**doc_report/:** Contains detained report of this project as a PDF document.<br/>


## Circuit Diagram

![Circuit Diagram](/diagrams/circuit-diagram.jpg)

## Implementation

The rain sensing wiper system is constructed using the Rain Sensor, Servo motor, LCD module, and Arduino. The sensor detects rain and sends information to the Arduino, which processes this data and controls the servo motors accordingly. The LCD module displays the intensity of the rainfall and the speed of the wipers.

### Block Diagram

![Block Diagram](/diagrams/block-diagram.jpg)

## Conclusion
The automatic car wiper system developed in this project senses rain and activates the windshield wipers and windows accordingly. This reduces the need for driver intervention, enhancing safety and comfort. Future improvements could include replacing the rain sensors with more accurate IR sensors.