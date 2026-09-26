#include <Servo.h>

// Variables used to store ultrasonic sensor measurements
long duration;
int distance;

// Pin assignments
const int trigPin = 10;
const int echoPin = 11;
const int greenPin = 7;
const int yellowPin = 6;
const int redPin = 5;
const int buzzer = 2;

// Create servo object
Servo myServo;

void setup() {

  // Configure sensor and output devices
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Start serial communication for radar UI
  Serial.begin(115200);

  // Attach servo signal wire to pin 3
  myServo.attach(3);
}

void loop() {

  // Sweep ultrasonic sensor from left to right
  for (int angle = 30; angle <= 150; angle += 2) {

    // Move servo to current angle
    myServo.write(angle);
    delay(20);

    // Generate ultrasonic trigger pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure echo return time
    duration = pulseIn(echoPin, HIGH);

    // Convert time into distance (cm)
    distance = duration * 0.034 / 2;

    // Send data to Processing radar
    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");

    // Warning system logic
    if (distance > 20) {

      // Safe distance - green LED only
      digitalWrite(greenPin, HIGH);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(buzzer, LOW);

    }
    else if (distance > 10) {

      // Caution zone - yellow LED and short buzzer pulse
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(redPin, LOW);

      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);

    }
    else {

      // Danger zone - red LED and rapid buzzer warning
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, HIGH);

      digitalWrite(buzzer, HIGH);
      delay(75);
      digitalWrite(buzzer, LOW);
      delay(75);
    }
  }

  // Sweep ultrasonic sensor from right to left
  for (int angle = 150; angle >= 30; angle -= 2) {

    // Move servo to current angle
    myServo.write(angle);
    delay(20);

    // Generate ultrasonic trigger pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure echo return time
    duration = pulseIn(echoPin, HIGH);

    // Convert time into distance (cm)
    distance = duration * 0.034 / 2;

    // Send data to Processing radar
    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");

    // Warning system logic
    if (distance > 20) {

      // Safe distance
      digitalWrite(greenPin, HIGH);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(buzzer, LOW);

    }
    else if (distance > 10) {

      // Caution zone
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(redPin, LOW);

      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);

    }
    else {

      // Danger zone
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, HIGH);

      digitalWrite(buzzer, HIGH);
      delay(75);
      digitalWrite(buzzer, LOW);
      delay(75);
    }
  }
}
