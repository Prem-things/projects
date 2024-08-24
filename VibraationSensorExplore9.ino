// Pin assignment
int sensorPin = A0;   // Select the input pin for the vibration sensor
int ledPin = 3;      // Select the pin for the LED

// Variable to store the sensor's analog value
int sensorValue = 0;

void setup() {
  // Declare the LED pin as an OUTPUT
  pinMode(ledPin, OUTPUT);

  // Begin serial communication at 9600 bps
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the vibration sensor
  sensorValue = analogRead(sensorPin);

  // Output the sensor value to the Serial Monitor for plotting
  Serial.println(sensorValue);

  // Threshold for turning the LED on
  int threshold = 500; // Adjust this based on the sensor and environment

  // If the sensor value exceeds the threshold, turn on the LED
  if (sensorValue > threshold) {
    digitalWrite(ledPin, HIGH); // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);  // Otherwise, turn off the LED
  }

  // Delay to prevent excessive reading frequency
  delay(100); // Adjust as needed for smoother plotting
}
