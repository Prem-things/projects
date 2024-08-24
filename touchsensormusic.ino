#include <Tone.h>

const int touchPin = 2; // Touch sensor connected to pin 2
const int buzzerPin = 8; // Buzzer connected to pin 8

int melody[] = {262, 294, 330, 349, 392, 440, 494, 523}; // Example melody notes
int noteDuration = 500; // Duration of each note in milliseconds

void setup() {
  pinMode(touchPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (digitalRead(touchPin) == HIGH) {
    for (int i = 0; i < 8; i++) {
      tone(buzzerPin, melody[i], noteDuration);
      delay(noteDuration * 1.5); // Pause between notes
    }
    delay(1000); // Pause after completing melody
  }
}
