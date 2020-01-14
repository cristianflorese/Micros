#include <MsTimer2.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
String palaserial;
String frase;
int i=0;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()>0) {
    palaserial=Serial.readString();
    lcd.setCursor(0, 0);
    lcd.print("                ");
    for(;i<palaserial.length()-1; i++) {
      palabra=palabra+palaserial.substring(i, i+1);
    }
    lcd.print(palabra);
    delay(20x00);
    for (;i<palabra.length();i++) {
      lcd.scrollDisplayLeft();
      delay(1000);
    }
    for (;i<=15+palabra.length();i++) {
      lcd.scrollDisplayRight();
      delay(1000);
    }
    for (;i<=15;i++) {
      lcd.scrollDisplayLeft();
      delay(1000);
    }
  }
  lcd.setCursor(0, 0);
  lcd.print("Ingrese frase: ");
  palaserial=" ";
  palabra=" ";
  lcd.print("                ");
}
