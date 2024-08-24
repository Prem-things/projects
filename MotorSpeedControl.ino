const int pot = A2;
const int Motor = 3;

int value, mappedValue;

void setup() {
  pinMode(Motor, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(pot);
  mappedValue = map(value, 0, 1023, 0, 255);
  Serial.println(value);
  analogWrite(Motor, mappedValue);
}