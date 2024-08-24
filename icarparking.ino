#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust address if needed

const int totalSpaces = 5;
int carCount[totalSpaces] = {0}; // Array to count cars in each space
int irPins[totalSpaces] = {2, 3, 4, 5, 6}; // Connect IR sensors to these pins
bool lastState[totalSpaces] = {HIGH, HIGH, HIGH, HIGH, HIGH}; // Last state of IR sensors

void setup() {
  lcd.begin();
  lcd.backlight();
  for (int i = 0; i < totalSpaces; i++) {
    pinMode(irPins[i], INPUT);
  }
  updateDisplay();
}

void loop() {
  for (int i = 0; i < totalSpaces; i++) {
    bool currentState = digitalRead(irPins[i]);
    if (currentState == LOW && lastState[i] == HIGH) { // Detect falling edge (car entering)
      carCount[i]++;
      delay(200); // Debounce delay
    }
    lastState[i] = currentState;
  }
  updateDisplay();
  delay(500); // Update display every half second
}

void updateDisplay() {
  lcd.clear();
  int totalCars = 0;
  for (int i = 0; i < totalSpaces; i++) {
    totalCars += carCount[i];
  }
  lcd.setCursor(0, 0);
  lcd.print("Space 1: ");
  lcd.print(carCount[0]);
  lcd.print(" Cars");
  lcd.setCursor(0, 1);
  lcd.print("Total Cars: ");
  lcd.print(totalCars);
}
