const int irPin = 2; // IR sensor connected to pin 2
volatile int count = 0;

void setup() {
  pinMode(irPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(irPin), countObject, FALLING);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Objects counted: ");
  Serial.println(count);
  delay(1000); // Print count every second
}

void countObject() {
  count++;
}
