/*
   Deber: Número ingresado por serial a binario en led´s
*/

int leds[8]={13,12,11,10,9,8,7,6};
String numingresado;
int numero;
int res;
int vector=0;

void setup() {
 Serial.begin(9600);
 Serial.print("Ingrese el numero para transformar: ");
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
}
    
void loop() {
if(Serial.available()>0){
  numingresado=Serial.readStringUntil("\n");
  numero=numingresado.toInt();
}
    if(numero>0 && numero <=255){
      res=numero;
    for(;vector<=7;vector++){
      if((res%2)==1){
      digitalWrite(leds[vector],HIGH);
        }
      else{
      digitalWrite(leds[vector],LOW);
          }
        res=(res/2);
      }
    }
     else{
        for(;vector<=7;vector++){
           digitalWrite(leds[vector],LOW);
      }
       numero=0;
 }
}
