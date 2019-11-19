
/*
   Deber: Validación cédula
*/
String cedula = "";

void setup() {
  Serial.begin(9600);
}
int comprobletras(String letras)
{
  int comprobar=0;
  for (int i=0;i<letras.length();i++)
  {
    char c=letras.charAt(i);
    if ((int(c)>=65)&&(int(c)<=122))
    { comprobar++;
    }
  }
      return comprobar;
}

void loop() {
  if (Serial.available()>0){
    cedula=Serial.readString();
    delay(300);
    int tam=cedula.length();
    if (tam>11&&cedula.charAt(9)!='-')
    {
      Serial.println("El # de cedula no incorrecto");
    } else if (comprobletras(cedula)>0) {
      Serial.println("Cédula no válida, contiene letras");
    }
    else if (tam==11) {
      String digito=cedula.substring(0, 2);
      int digito_region = digito.toInt();
      delay(200);
      if (digito_region>=1&& digito_region <= 24)
      {
      int  ultimo_digito=cedula.substring(10).toInt();
      int p1=(cedula.substring(1,2)).toInt();
      int p2=(cedula.substring(3,4)).toInt();
      int p3=(cedula.substring(5,6)).toInt();
      int p4=(cedula.substring(7,8)).toInt();
      int pares=p1+p2+p3+ p4;
      int numero1 =cedula.substring(0,1).toInt();
      numero1 = (numero1 *2);
      if (numero1>9){
          numero1 = (numero1-9);
        }
        int numero3 =cedula.substring(2,3).toInt();
        numero3 =(numero3*2);
        if (numero3>9){
          numero3 =(numero3-9);
        }
        int numero5 =cedula.substring(4, 5).toInt();
        numero5 =(numero5*2);
        if (numero5>9) {
          numero5 =(numero5 - 9);
        }
        int numero7 = cedula.substring(6, 7).toInt();
        numero7 =(numero7*2);
        if (numero7>9) {
          numero7= (numero7-9);
        }
        int numero9 =cedula.substring(8, 9).toInt();
        numero9 =(numero9*2);
        if (numero9 >9) {
          numero9 =(numero9-9);
        }
          int impares =numero1+numero3+numero5+numero7+numero9;
          int suma_total =pares+impares;
          int primer_digito_suma =String(suma_total).substring(0,1).toInt();
          int decena =(((primer_digito_suma)+1)*10);
          int digito_validador =(decena-suma_total);
        if (digito_validador==10){
          digito_validador=0;
        }
        if (digito_validador == ultimo_digito) {
          Serial.println("La Cédula ingresada: "+cedula+"es CORRECTA");
        } 
        else {
          Serial.println("La Cédula ingresada: "+cedula+"es INCORRECTA");
        }
           } 
      else {
        Serial.println("Esta Cédula no pertenece a ninguna región");
        }
    } 
    else {
      Serial.println("Esta Cédula tiene menos de 11 Digitos");
    }
  }
}
