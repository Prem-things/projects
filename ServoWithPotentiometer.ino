#include <Servo.h>

// Create a Servo object to control the servo motor
Servo myServo;

// Define the analog pin where the potentiometer is connected
const int potPin = A0;

// Set the initial servo pin
const int servoPin = 3;

void setup() {
  // Attach the servo to the defined pin
  myServo.attach(servoPin);
}

void loop() {
  // Read the analog value from the potentiometer
  int potValue = analogRead(potPin);

  // Map the potentiometer value to the servo's angle range (0 to 180 degrees)
  int servoAngle = map(potValue, 0, 1023, 0, 180);

  // Set the servo to the calculated angle
  myServo.write(servoAngle);

  // Small delay to avoid excessive servo movement
  delay(15);
}