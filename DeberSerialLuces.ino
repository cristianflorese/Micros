/*
 * Deber: Encender 4 juegos de luces mediante comunicación Serial
 */
 
String datos;
int leds[8] = {13, 12, 11, 10, 9, 8, 7, 6};
int i;
 
void setup() {
for(i=0;i<=7;i++) {
    pinMode(leds[i], OUTPUT);
    }
    
    Serial.begin(9600);
    Serial.println("Seleccione el Juego"); 
}

void loop() {
  if(Serial.available()>0){
    datos=Serial.readString();
    
    if(datos=="ACBF"){      //JUEGO 1
    for(i=0;i<4;i++)
    {
      digitalWrite(leds[i],HIGH);
      delay(300);
    }
    for(i=0;i<4;i++)
    {
      digitalWrite(leds[i],LOW);
      delay(300);
    }
    for(i=4;i<8;i++)
    {
      digitalWrite(leds[i],HIGH);
      delay(300);
    }
    for(i=4;i<8;i++)
    {
      digitalWrite(leds[i],LOW);
      delay(300);
    }
  }
  else {
    
   if(datos=="ACGF"){     //JUEGO 2
    for(i=0;i<4;i++)
      {
        digitalWrite(leds[i],HIGH);
        delay(300);
      }
      for(i=0;i<4;i++)
      {
       digitalWrite(leds[i],LOW);
        delay(300);
      }
      for(i=4;i<8;i++)
      {
        digitalWrite(leds[i],HIGH);
        delay(300);
      }
      for(i=4;i<8;i++)
      {
        digitalWrite(leds[i],LOW);
        delay(300);
      }
    }
    else{
   if (datos=="ADBF"){     //JUEGO 3
      for(i=0;i<8;i++){
    digitalWrite(leds[i],HIGH);
    delay(250);
    digitalWrite(leds[i],LOW);
    delay(250);
    }
      }
      else{
if (datos == "ADBH"){        //JUEGO 4
for(;i<8;i++){
  if(i%2==1){
  digitalWrite(leds[i],HIGH);
  delay(300);
  }
  }
  for(;i>=0;i--)
  {
  if(i%2==1)
  {
    digitalWrite(leds[i],LOW);
  delay(300);
  }
  }
  }
  else{
  }
  }
  } 
  }
  }
}
