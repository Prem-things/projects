// Define the sensor and LED pin numbers
const int SENSOR = 2;
const int LED = 3;

void setup() {
  // Setup the sensor pin as input and the LED pin as output
  pinMode(SENSOR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Continuously check the sensor reading and control the LED accordingly
  if (digitalRead(SENSOR) == HIGH) {
    digitalWrite(LED, HIGH);  // Turn on the LED
    Serial.println("Bright");
  } else {
    digitalWrite(LED, LOW);   // Turn off the LED
    Serial.println("Off");
  }
}