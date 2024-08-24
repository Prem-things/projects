const int touchPin = 2; // Touch sensor connected to pin 2
const int ledPin = 9; // LED connected to PWM pin 9

int touchValue = 0;
int brightness = 0;
int lastTouchValue = 0;

void setup() {
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  analogWrite(ledPin, brightness);
}

void loop() {
  touchValue = digitalRead(touchPin);
  
  if (touchValue != lastTouchValue) {
    if (touchValue == HIGH) {
      brightness += 25; // Increase brightness
      if (brightness > 255) brightness = 0; // Reset brightness
      analogWrite(ledPin, brightness);
    }
    delay(100); // Debounce delay
  }
  
  lastTouchValue = touchValue;
}
