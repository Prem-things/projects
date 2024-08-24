const int irPin = 2; // IR sensor connected to pin 2
const int buzzerPin = 8; // Buzzer connected to pin 8

void setup() {
  pinMode(irPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int irState = digitalRead(irPin);
  
  if (irState == LOW) { // Assuming LOW means object detected
    digitalWrite(buzzerPin, HIGH); // Activate buzzer
  } else {
    digitalWrite(buzzerPin, LOW); // Deactivate buzzer
  }
}
