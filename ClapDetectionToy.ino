#include <Servo.h>

// Define the analog input pin for the sound sensor
const int soundSensorPin = A2;

// Define the digital pin for the servo motor
const int servoPin = 7;

// Create a Servo object named myServo
Servo myServo;

void setup() {
  // Start serial communication at a baud rate of 9600
  Serial.begin(9600);

  // Attach the servo motor to the specified pin
  myServo.attach(servoPin);

  // Set the sound sensor pin as an input
  pinMode(soundSensorPin, INPUT);
}

void loop() {
  // Read the analog value from the sound sensor
  int soundValue = analogRead(soundSensorPin);

  // Check if the sound value is above a threshold (500)
  if (soundValue > 500) {
    // Rotate the servo motor three times
    for (int i = 0; i < 3; i++) {
      // Move the servo motor from 0 to 45 degrees
      for (int angle = 0; angle <= 45; angle++) {
        myServo.write(angle);
        delay(15);
      }

      // Move the servo motor from 45 to 0 degrees
      for (int angle = 45; angle >= 0; angle--) {
        myServo.write(angle);
        delay(15);
      }
    }
  }
}
