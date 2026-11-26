long duration; // time for the echo to return, in microseconds
int distance;

const int trigPin = 10; // pin assignment
const int echoPin = 11;
const int greenPin = 7;
const int yellowPin = 6;
const int redPin = 5;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);

  Serial.begin(115200); // Open a communication channel with my computer.
}

void loop() {
  // Ensure trigger starts LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure how long the echo takes to return
  duration = pulseIn(echoPin, HIGH);

  // Convert time to distance
  // Speed of sound ≈ 0.034 cm per microsecond
  // Divide by 2 because sound travels there and back
  distance = duration * 0.034 / 2; 

  // Print result to Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  delay(100);

  if (distance > 20) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, LOW);
  }
  else if (distance > 10) {
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, LOW);
  }
  else {
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
  }
}

