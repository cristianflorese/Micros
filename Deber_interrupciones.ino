String numero;
String num;
int i;
int modos;
int vec;
int ordenar;
  
void setup() {
attachInterrupt(0,on,LOW);
Serial.begin(9600);
}

void loop() {
if (modos==2){
    if(Serial.available()>0){
      numero=Serial.readString();
      }
  }
  else{
    if (modos==2){
      int vector[numero.length()];
       for(;i<numero.length();i++){   
       num= numero.substring(i,(i+1));    
       vector[i]=num.toInt(); 
      }
      }
}

do{                                   
   ordenar=0;
   for (;i<numero.length();i++) { 
    if (vector[i]>vector[i+1]){         
    ordenar = 1;
    vec = vector[i];
    vector[i] = vector[i+1];
    vec =vector[i+1];
        }
      }
    }
while(ordenar);
   for (;i<numero.length();i++){
   Serial.println(vector[i]);
   }
   Serial.println(" ");
   numero = " ";
  }

void on() {
  switch (modos) {
    case 0:
      Serial.println("Ingrese el numero para ordenar");
      modos++;
      break;

    case 1:
      Serial.println("Ordenar numero");
      modos ++;
      break;
    default:
      modos = 0;
      break;
  }
}
