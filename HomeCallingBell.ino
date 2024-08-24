// Define the pin for the touch sensor
const int touch_sensor = 3;

// Define the pin for the LED
const int led = 6;

void setup() {
  // Set the touch sensor pin as an input
  pinMode(touch_sensor, INPUT); 
  
  // Set the LED pin as an output
  pinMode(led, OUTPUT); 
}

void loop() {
  // Check if the touch sensor reads HIGH (touched)
  if (digitalRead(touch_sensor) == HIGH) {
    // If the touch sensor is HIGH (touched), turn on the LED
    digitalWrite(led, HIGH); 
  } else {
    // If the touch sensor is LOW (not touched), turn off the LED
    digitalWrite(led, LOW); 
  }
}
