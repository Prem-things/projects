#include <Servo.h>

const int irPin = 2;
const int servoPin = 7;
const int GreenLED = 3;
const int RedLED = 4;
Servo myservo;

void setup() {
  myservo.attach(servoPin);
  pinMode(irPin, INPUT);
  myservo.write(0);
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
}

void loop() {
  int irValue = digitalRead(irPin);

  if (irValue == HIGH) {
    myservo.write(100);
    digitalWrite(GreenLED, HIGH);
    digitalWrite(RedLED, LOW);
    delay(3000);
  } else {
    myservo.write(0);
    digitalWrite(GreenLED, LOW);
    digitalWrite(RedLED, HIGH);
    delay(3000);
  }
}
