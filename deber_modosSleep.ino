
/*
   Deber Modos Sleep
*/
#include <MsTimer2.h>
#include<avr/sleep.h>
#include<EEPROM.h>
int contador = 0;
int estado;

void setup() {
  Serial.begin(9600);
   attachInterrupt(0,wakeup,LOW);
  //estado = EEPROM.read(0);
  //EEPROM.write(0, 1);
  MsTimer2::set(1000,conteo);
  MsTimer2::start();
  set_sleep_mode(SLEEP_MODE_PWR_SAVE);
}

void loop() {
  if (contador==2 ) {
    Serial.println("Despierto");
    EEPROM.write(0, 1);
    Serial.println(estado);
  }
  if (contador==12) {
    Serial.println("Dormido");
    EEPROM.update(0, 0);
    sleep_enable();
    sleep_mode();
    sleep_disable();
  }
}

void conteo() {
  contador++;
}

void wakeup() {
  Serial.println("Reinicio");
   sleep_disable();
    contador = 0;
}
