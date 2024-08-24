// Define the analog input pin for the potentiometer
const int pot = A2;

// Define the digital output pin for the LED
const int LED = 3;

// Initialize variables to store values
int value, mappedValue;

void setup() {
  // Set the LED pin as an output
  pinMode(LED, OUTPUT);
  
  // Initialize serial communication at a baud rate of 9600
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the potentiometer
  value = analogRead(pot);

  // Map the analog value to a range of 0-255 (for PWM)
  mappedValue = map(value, 0, 1023, 0, 255);

  // Print the raw analog value to the serial monitor
  Serial.println(value);

  // Set the LED brightness using PWM based on the mapped value
  analogWrite(LED, mappedValue);
}
