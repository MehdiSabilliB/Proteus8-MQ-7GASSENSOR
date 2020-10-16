#include <LiquidCrystal.h>
LiquidCrystal lcd( 13, 12, 11, 10, 9, 8);
int MQ7GASSENSOR =3;
int LEDRED =5;
int LEDYELLOW =4;
void setup() {
  pinMode(MQ7GASSENSOR, INPUT_PULLUP);
  pinMode(LEDRED, OUTPUT);
  pinMode(LEDYELLOW, OUTPUT);
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("SISTEM PENDETEKSI");
  lcd.setCursor(0,1);
  lcd.print("ALKOHOL");
  lcd.setCursor(0,2);
  lcd.print("TELKOMUNIKASI PNJ");
  delay(2000);
}

void loop() {
  int MQ7GASSENSOR_READ = digitalRead(MQ7GASSENSOR);
if (MQ7GASSENSOR_READ == LOW){
  lcd.clear();
  lcd.setCursor(0,3);
  lcd.print("ALKOHOL NOT DETECTED");
   digitalWrite(LEDRED, HIGH);
  digitalWrite(LEDYELLOW, LOW);
  delay(20);
}
else {
  lcd.clear();
  lcd.setCursor(0,3);
  lcd.print("ALKOHOL DETECTED");
  digitalWrite(LEDYELLOW, HIGH);
  digitalWrite(LEDRED, LOW);
  delay(20);
}
}
