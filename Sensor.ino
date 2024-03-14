#include <Wire.h>
#include <rgb_lcd.h>

rgb_lcd lcd;

const int moistureSensorPin = A0;

void setup() {
  // Initialize the LCD
  lcd.begin(16, 2);

  // Set up serial communication
  Serial.begin(9600);
}

void loop() {
  // Read moisture sensor
  int sensorValue = analogRead(moistureSensorPin);
  
  // Convert analog value to percentage (adjust the mapping according to your sensor)
  int moisturePercentage = map(sensorValue, 0, 1023, 0, 100);
  
  // Print moisture level to serial monitor
  Serial.print("Moisture Level: ");
  Serial.print(moisturePercentage);
  Serial.println("%");
  
  // Display moisture level on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moisture:");
  lcd.setCursor(0, 1);
  lcd.print(moisturePercentage);
  lcd.print("%");
  
  delay(1000); // Wait for 1 second before reading again
}
