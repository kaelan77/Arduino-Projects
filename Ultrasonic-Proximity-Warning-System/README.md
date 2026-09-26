# Ultrasonic Proximity Warning System

## Project Overview

This project uses an HC-SR04 ultrasonic sensor and an Arduino Uno to measure the distance between the sensor and nearby objects. Visual feedback is provided through a three-stage LED warning system, allowing users to quickly identify how close an object is to the sensor.

---

# Phase 1 - Distance Measurement and LED Indicators

## Objective

The objective of Phase 1 was to develop a basic proximity warning system capable of measuring distance and displaying the result using coloured LEDs.

### Components Used

- Arduino Uno R3
- HC-SR04 Ultrasonic Sensor
- Breadboard
- Jumper Wires
- 3 LEDs (Green, Yellow and Red)
- 3 × 330 Ω Resistors

---

## Breadboard Circuit

<img src="Images/p1breadboard_led_circuit.jpeg" width="600">

The circuit was assembled on a breadboard using three LEDs connected through 330 Ω current-limiting resistors. The LEDs provide visual feedback depending on the measured distance.

---

## HC-SR04 Sensor Connections

<img src="Images/p1hc_sr04_pinout.jpeg" width="500">

The HC-SR04 ultrasonic sensor was connected to the Arduino Uno using four connections:

- VCC → 5V
- GND → Ground
- TRIG → Digital Output Pin
- ECHO → Digital Input Pin

The sensor measures distance by transmitting an ultrasonic pulse and calculating the time taken for the echo to return.

---

## Arduino Pin Assignments

<img src="Images/p1arduino_connections.jpeg" width="500">

The Arduino Uno was configured to control the LEDs and communicate with the HC-SR04 sensor.

### Pin Mapping

| Component | Arduino Pin |
|------------|------------|
| Green LED | D7 |
| Yellow LED | D6 |
| Red LED | D5 |
| Trigger Pin | D9 |
| Echo Pin | D10 |

---

## System Logic

- Green LED activates when the object is far away.
- Yellow LED activates when the object enters a warning range.
- Red LED activates when the object is very close.
- Distance measurements are continuously updated using ultrasonic pulse timing.

---

## Challenges Encountered

- Understanding breadboard power rail connections.
- Correctly wiring the HC-SR04 Trigger and Echo pins.
- Debugging LED polarity issues.
- Selecting suitable resistor values for LED protection.

---

## Skills Demonstrated

- Embedded Systems Programming
- Arduino Development
- Electronic Circuit Construction
- Sensor Integration
- Fault Finding and Debugging
- Hardware Documentation

---

## Outcome

Phase 1 successfully demonstrated accurate distance measurement and visual proximity indication using LEDs. This provided the foundation for future development involving servo motor scanning and audible alerts.
