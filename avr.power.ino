/*
  Deber libreria <avr.power.h>
*/
#include <avr/power.h>
#include <avr/wdt.h>
#include <EEPROM.h>
#include <TimerOne.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);
int contador = 0;
int cad;
int pos = EEPROM.read(0);

void setup() {
  lcd.begin(16, 2);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(conteo);
  power_all_enable();
  pos=0;
}

void loop() {
  Serial.println(pos);
  desactivar();
  lcd.setCursor(0, 1);
  lcd.print(String(contador));
  cad=analogRead(0);
  lcd.setCursor(0, 1);
  lcd.print(cad);
}

void conteo() {
  contador++;
}

void desactivar() {
  if (contador==5){
    pos=pos+1;
    lcd.setCursor(0, 0);
    lcd.print("CAD Off");
    power_adc_disable();
  }
  if (contador==8){
    lcd.setCursor(0, 0);
    lcd.print("                     ");
    lcd.setCursor(0, 0);
    lcd.print("ComSerial Off");
    power_spi_disable();
  }
  if (contador==12){
    lcd.setCursor(0, 0);
    lcd.print("                    ");
    lcd.setCursor(0, 0);
    lcd.print("OFF");
    power_all_disable();
  }
  if (EEPROM.read(0)>=11){
    pos=0;
    power_all_enable();
    EEPROM.write(0,pos);
    lcd.clear();
    wdt_enable(WDTO_1S);
  }
}
