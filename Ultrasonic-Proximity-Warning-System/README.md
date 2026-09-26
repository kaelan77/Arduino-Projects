# Ultrasonic Proximity Warning System

## Phase 1 – Distance Measurement and Visual Warning System

### Project Overview

The aim of this project was to design and build an ultrasonic proximity warning system using an Arduino Uno and HC-SR04 ultrasonic sensor. The system measures the distance to nearby objects and provides visual feedback using three LEDs.

The project was completed as the first stage of a larger obstacle detection system that will later incorporate an audible buzzer and servo-controlled scanning mechanism.

---

## Objectives

- Measure object distance using ultrasonic sensing.
- Process sensor data using Arduino.
- Implement a three-stage visual warning system.
- Develop practical circuit design and breadboard wiring skills.
- Gain experience debugging hardware and software faults.

---

## Components Used

| Component | Purpose |
|------------|------------|
| Arduino Uno R3 | Main microcontroller |
| HC-SR04 Ultrasonic Sensor | Distance measurement |
| Red LED | Close-range warning |
| Yellow LED | Medium-range warning |
| Green LED | Safe distance indication |
| 330 Ω Resistors | Current limiting |
| Breadboard | Circuit prototyping |
| Jumper Wires | Electrical connections |

---

## System Operation

The Arduino sends a 10 µs trigger pulse to the HC-SR04 sensor.

The sensor emits an ultrasonic sound wave and listens for the reflected echo. The time taken for the sound wave to return is measured using the `pulseIn()` function.

Distance is then calculated using:

Distance = (Time × Speed of Sound) / 2

The measured distance determines which LED is illuminated:

| Distance | Indicator |
|------------|------------|
| Greater than 20 cm | Green LED |
| 10–20 cm | Yellow LED |
| Less than 10 cm | Red LED |

---

## Hardware Implementation

### Breadboard Circuit

![Breadboard Circuit](Images/p1_breadboard_led_circuit.jpeg)

The circuit was constructed on a breadboard using three LEDs connected through 330 Ω current-limiting resistors.

---

### HC-SR04 Sensor Connections

![Sensor Connections](Images/p1_sensor_connections.jpeg)

The HC-SR04 sensor was connected using:

- VCC → 5V
- GND → Ground
- TRIG → Arduino Digital Output
- ECHO → Arduino Digital Input

---

### Arduino Pin Assignments

![Arduino Connections](Images/p1_arduino_pin_assignments.jpeg)

The LEDs were connected to dedicated digital output pins while the ultrasonic sensor used separate TRIG and ECHO connections.

---

## Software Implementation

The Arduino program continuously:

1. Triggers the ultrasonic sensor.
2. Measures echo return time.
3. Calculates distance.
4. Determines the warning level.
5. Activates the appropriate LED.

The code can be found in the `Code` directory.

---

## Challenges and Solutions

### Breadboard Wiring

**Issue**

The LEDs initially failed to illuminate despite the program compiling successfully.

**Investigation**

The fault was traced to an incorrect understanding of breadboard row connectivity and power rail distribution.

**Solution**

The circuit was rebuilt after reviewing breadboard internal connections.

**Outcome**

Improved understanding of circuit construction and troubleshooting.

---

### LED and Resistor Configuration

**Issue**

Incorrect LED and resistor placement prevented current from flowing through the circuit.

**Solution**

The circuit was redesigned to ensure a complete path from the Arduino output pin through the resistor and LED to ground.

**Outcome**

Developed a stronger understanding of current flow and component placement.

---

## Engineering Skills Developed

- Breadboard prototyping
- Circuit debugging
- Sensor integration
- Embedded programming
- Digital I/O control
- Distance measurement systems
- Hardware fault diagnosis
- Engineering documentation

---

## Real-World Applications

- Vehicle parking assistance systems
- Mobile robotics
- Warehouse safety monitoring
- Intruder detection systems
- Industrial safety zones
- Smart building automation

---

## Future Development

### Phase 2

- Add audible warning buzzer.
- Integrate servo motor scanning.
- Improve obstacle awareness.

### Phase 3

- Add OLED/LCD display.
- Display live distance measurements.
- Implement enhanced warning logic.

---

## Key Learning Outcomes

This project provided practical experience in combining electronics and software to create a functioning embedded system.

I developed a deeper understanding of ultrasonic sensing, digital electronics, circuit construction, Arduino programming, and systematic engineering problem-solving. The project also strengthened my ability to identify faults, test solutions, and incrementally improve a design through multiple development stages.
