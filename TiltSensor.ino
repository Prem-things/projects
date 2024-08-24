// Define the sensor and LED pin numbers
const int sensor = 3;
const int GreenLED = 6;
const int RedLED = 7;

void setup() {
  pinMode(sensor, INPUT);    // Set the sensor pin as input
  pinMode(GreenLED, OUTPUT); // Set the green LED pin as output
  pinMode(RedLED, OUTPUT);   // Set the red LED pin as output
}

void loop() {
  // Turn on the green LED and turn off the red LED
  if (digitalRead(sensor) == HIGH) {
    digitalWrite(GreenLED, HIGH);
    digitalWrite(RedLED, LOW);
  } else {
    // Turn off the green LED and turn on the red LED
    digitalWrite(GreenLED, LOW);
    digitalWrite(RedLED, HIGH);
  }
}