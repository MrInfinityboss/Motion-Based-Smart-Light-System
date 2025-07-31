#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 8, 9, 2);

int pirPin = 12;
int buzzerPin = 4;
int led1 = 3;
int motion = 0;

void setup() {
  lcd.begin(16, 2);        
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(led1, OUTPUT);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  motion = digitalRead(pirPin);

  if (motion == HIGH) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(led1, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Motion Detected ");
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(led1, LOW);
    lcd.setCursor(0, 0);
    lcd.print("No Motion       ");
  }

  delay(500);
}