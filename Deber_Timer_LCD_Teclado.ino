 #include <MsTimer2.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal lcd(13, 12, A0, A1, A2, A3); 
const byte filas = 4;
const byte columnas = 4;
char keys[filas][columnas]={
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}};
  
const byte pinfil[filas]={11,10,9,8};
const byte pincol[columnas]={7,6,5,4};
Keypad teclado = Keypad(makeKeymap(keys), pinFil, pinCol, fil, col);
char teclado;
String valor ;
int numero = 0;
int aux = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 1);
  lcd.print("Ingrese #: ");
  MsTimer2::set(1000, conteo);
  MsTimer2::start();
}

void loop() {
  tecla = teclado.getKey();
  if (teclado) {
    if (teclado=='A'){
      aux = 1 - aux;
      lcd.setCursor(0, 0);
      lcd.print("     ");
      lcd.setCursor(0, 0);
      lcd.print("Contar");
    }
    else if (tecla == 'B'){
      lcd.setCursor(0, 0);
      lcd.print("       ");
      lcd.setCursor(0, 0);
      lcd.print("Reiniciar");
      delay(2000);
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("Ingrese #: ");
      lcd.setCursor(0,1);
      teclado = ' ';
      valor=" ";
      numero = 0;
    }
    else {
      lcd.print(teclado);
      valor=valor+teclado;
    }
    numero=valor.toInt();
  }
}

void conteo() {
  if (aux == 1 ) {
    if (numero > 0) {
      lcd.setCursor(0, 1);
      lcd.print("           ");
      lcd.setCursor(0, 1);
      lcd.print(numero);
      numero--;
    }
    else if (numero == 0) {
      lcd.setCursor(0, 1);
      lcd.print("    ");
      lcd.setCursor(0, 1);
      lcd.print(num);
      lcd.setCursor(0, 0);
      lcd.print("                ");
    }
  }
}
