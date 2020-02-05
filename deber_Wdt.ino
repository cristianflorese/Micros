/*
 * Deber Wdt
*/
#include <avr/wdt.h>
#include <EEPROM.h>
#include <TimerOne.h>
String letra;
int numero=0;
int contador=0;
int encendido=0;
int valor=0;
void setup() {
  Serial.begin(9600);
  attachInterrupt(0,menu,LOW);
  attachInterrupt(1,submenu,LOW);
  Timer1.stop();
}

void loop() {
  if (encendido == 1) {
    if (Serial.available() > 0 ) {
      letra=Serial.readString();
      Timer1.initialize(1000000);
      Timer1.attachInterrupt(conteo);
    }
  }
}

void menu() {
  switch (encendido) {
    case 0:
      Serial.println("Letra/Tiempo:");
      encendido++;
      break;
    case 1:
      Serial.println(' ');
      encendido=0;
      break;
  }
}
void conteo() {
  contador++;
 if(valor==1){
    if(letra=='A'){
     Serial.println(String(2-contador));
    }
    if(letra=='B'){
     Serial.println(String(3-contador));
    }
    if(letra=='C'){
     Serial.println(String(5-contador));
    }
    if(letra=='D'){
     Serial.println(String(9-contador));
    }
 }
}
void submenu() {

  if (letra=='A'&&valor==1) {
    Serial.println("WDTO_1S");
    wdt_enable(WDTO_1S);
  }
  if (letra=='B'&&valor==1) {
    Serial.println("WDTO_2S");
    wdt_enable(WDTO_2S);
  }
  if (letra=='C'&&valor==1) {
    Serial.println("WDTO_4S");
    wdt_enable(WDTO_4S);
  }
  if (letra=='D'&&valor==1) {
    Serial.println("WDTO_8S");
    wdt_enable(WDTO_8S);
  }
}
