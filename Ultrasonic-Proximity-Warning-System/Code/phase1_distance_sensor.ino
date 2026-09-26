long duration; // large notebook in theory as duration is measured in micro seconds
int distance;  //

const int trigPin = 10; // pin assignment
const int echoPin = 11;
const int greenPin = 7;
const int yellowPin = 6;
const int redPin = 5;
const int buzzer = 2;



void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buzzer, OUTPUT);

   Serial.begin(115200); // Open a communication channel with my computer.

}

void loop() {
  // put your main code here, to run repeatedly:
  // Ensure trigger starts LOW



    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Sends 10 microsecond pulse

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);                              
    // pulse is sent for a 10 microsecond period and then the echopin waits to receive this pulse 

    // Measure how long echo takes to return

    duration = pulseIn(echoPin, HIGH);       
    // duration is time taken between the trig pin being sent out and received by the echoPin

    // Convert time to distance
    // Speed of sound ≈ 0.034 cm per microsecond
    // Divide by 2 because sound travels there and back

    distance = duration * 0.034 / 2;  // speed of sound in cm/s

    // Print result to Serial Monitor

    Serial.print("Distance: ");
    Serial.println(distance);

    delay(100);

    if (distance > 20)
    { 
      digitalWrite(greenPin , HIGH);
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);


    }
    else if (distance > 10)
    {
      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(redPin, LOW);

      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer,LOW);
      delay(550);
    }
    else
    {
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, LOW);

      digitalWrite(buzzer, HIGH);
      delay(75);
      digitalWrite(buzzer,LOW);
      delay(75);
   
      }

}

