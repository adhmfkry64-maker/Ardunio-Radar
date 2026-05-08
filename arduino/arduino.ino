// Includes the Servo library
#include <Servo.h>.
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 12;
const int echoPin = 13;
const int buzzer = 4;

const int RED = A2;
const int GREEN = A0;
const int YELLOW = A1;
// Variables for the duration and the distance
long duration;
int distance;
Servo myServo;  // Creates a servo object for controlling the servo motor
void setup() {
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);   // Sets the buzzer as an Output

  pinMode(RED, OUTPUT);     // Sets the buzzer as an Output
  pinMode(GREEN, OUTPUT);   // Sets the buzzer as an Output
  pinMode(YELLOW, OUTPUT);  // Sets the buzzer as an Output

  Serial.begin(9600);
  myServo.attach(11);  // Defines on which pin is the servo motor attached
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for (int i = 15; i <= 165; i++) {
    myServo.write(i);

    distance = calculateDistance();  // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree

   if (distance < 40) {
      digitalWrite(buzzer, HIGH);
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, LOW);


    } else if (distance > 80)  {
      digitalWrite(buzzer, LOW);
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, HIGH);
      digitalWrite(YELLOW, LOW);
    }

    else if(distance > 60)  {
      digitalWrite(buzzer, LOW);
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, HIGH);
    }
 
    Serial.print(i);         // Sends the current degree into the Serial Port
    Serial.print(",");       // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print(distance);  // Sends the distance value into the Serial Port
    Serial.print(".");       // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    delay(15);
  }
  // Repeats the previous lines from 165 to 15 degrees
  for (int i = 165; i > 15; i--) {
    myServo.write(i);

    distance = calculateDistance();

     if (distance < 40) {
      digitalWrite(buzzer, HIGH);
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, LOW);


    } else if (distance > 80)  {
      digitalWrite(buzzer, LOW);
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, HIGH);
      digitalWrite(YELLOW, LOW);
    }

    else if(distance > 60)  {
      digitalWrite(buzzer, LOW);
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, HIGH);
    }
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    delay(25);
  }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2;

  return distance;
}
