#Ultrasonic Proximity Warning System

## Phase 1 - Distance Measurement and LED Indicators

### Breadboard Circuit

<img src="Images/Phase1/breadboard_led_circuit.jpeg" width="500">

Three LEDs were connected using 330 Ω current-limiting resistors to provide visual feedback based on measured distance.

### HC-SR04 Sensor Connections

<img src="Images/Phase1/hc_sr04_pinout.jpeg" width="400">

The HC-SR04 ultrasonic sensor was connected to the Arduino Uno using VCC, GND, TRIG and ECHO pins.

### Arduino Pin Assignments

<img src="Images/Phase1/arduino_connections.jpeg" width="400">

The LEDs were connected to digital output pins while the ultrasonic sensor used dedicated TRIG and ECHO pins.
