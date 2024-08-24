#include <TM1637Display.h>

// Define the CLK and DIO pins for the TM1637 display module
#define CLK 9
#define DIO 8

// Define the delay time
#define delaytime 10

// Define the pin for the sensor
int sensor = 4;

// Initialize a variable to keep count
int count = 0;

// Create a TM1637Display object named 'display' with CLK and DIO pins
TM1637Display display(CLK, DIO);

void setup()
{
  // Start serial communication at a baud rate of 115200
  Serial.begin(115200);

  // Set the brightness of the display to full brightness
  display.setBrightness(0x0F);
  
  // Clear the display
  display.clear();
}

void loop()
{
  // Show the current count on the TM1637 display
  display.showNumberDec(count, true);
  
  // Check if the sensor reads LOW (assuming the sensor is a push button)
  if (digitalRead(sensor) == LOW)
  {
    // Increment the count
    count++;

    // Show the updated count on the TM1637 display
    display.showNumberDec(count, true);

    // Print the count value to the serial monitor
    Serial.println("Count Value: " + String(count));

    // Wait for the sensor to be released (assuming the sensor is a push button)
    while (digitalRead(sensor) == LOW) {}
  }
}
