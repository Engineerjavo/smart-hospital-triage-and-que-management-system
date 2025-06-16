
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD (I2C address 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buttonPin = 2;
const int buzzerPin = 8;

int queueNumber = 0;
bool buttonPressed = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Button input
  pinMode(buzzerPin, OUTPUT);       // Buzzer output

  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Queue System");
  lcd.setCursor(0, 1);
  lcd.print("Number: ");
}

void loop() {
  if (digitalRead(buttonPin) == LOW && !buttonPressed) {
    buttonPressed = true;
    queueNumber++;

    // Display queue number
    lcd.setCursor(8, 1);
    lcd.print("     "); // Clear previous number
    lcd.setCursor(8, 1);
    lcd.print(queueNumber);

    // Sound the buzzer
    tone(buzzerPin, 1000, 300); // 1kHz for 300ms
    delay(1000); // Debounce + wait

  } else if (digitalRead(buttonPin) == HIGH) {
    buttonPressed = false;
  }
}