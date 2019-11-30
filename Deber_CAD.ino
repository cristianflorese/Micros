/*
 * Deber Conversor análogo digital
 */
String ingreso;
int v=0;
int c;
int a;

void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese el valor maximo");
  pinMode(13, OUTPUT);
  pinMode(A1, INPUT);
}

void loop () {
  if(Serial.available()>0){
  ingreso=Serial.readStringUntil("\n");
  v=ingreso.toInt();
  }
  if (v>0 && v <=1024){
    c=analogRead(A1);
    Serial.println(c);
  }
   if(c>a){
      digitalWrite(13,HIGH);
  }
  else {
    digitalWrite(13,LOW);
}
}
