/*
   Deber#1: Contador binario con 6 leds
*/

int leds[6]={8, 9, 10, 11, 12, 13};
int boton=5;
int numero=0;
int contador= 0;
int i=0;

void setup() {
  for (; i < 6; i++){
    pinMode(leds[i],OUTPUT);
  }
  pinMode(boton,INPUT);
    }
    
void loop() {
  if(digitalRead(boton)==HIGH){
    numero++;
  if (numero>0&&numero<=63){
    contador = numero;
   for (int i=0;i<6;i++){
     if ((contador%2)==1){
     digitalWrite(leds[i],HIGH);
     }
     else 
     {
     digitalWrite(leds[i],LOW);
      }
      contador=(contador/2);
      }
    }
    else 
    {
    for (i=0;i <= 5;i++) {
     digitalWrite(leds[i], LOW);
     }numero=0;
    }
    delay(400);
    }
        }
