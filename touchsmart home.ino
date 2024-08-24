const int touchPin = 2; // Touch sensor connected to pin 2
const int relayPin = 7; // Relay module connected to pin 7

bool applianceState = false;
int lastTouchValue = 0;

void setup() {
  pinMode(touchPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Appliance off initially
}

void loop() {
  int touchValue = digitalRead(touchPin);
  
  if (touchValue != lastTouchValue) {
    if (touchValue == HIGH) {
      applianceState = !applianceState; // Toggle state
      digitalWrite(relayPin, applianceState ? HIGH : LOW);
    }
    delay(200); // Debounce delay
  }
  
  lastTouchValue = touchValue;
}
