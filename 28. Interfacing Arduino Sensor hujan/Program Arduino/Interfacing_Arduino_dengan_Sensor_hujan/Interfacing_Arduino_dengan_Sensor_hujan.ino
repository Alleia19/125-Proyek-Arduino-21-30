/*************************************
 * Program : Project 28. Interfacing Arduino Sensor hujan
 * Input   : Sensor Hujan
 * Output  : LCD 2x16
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup(){
  pinMode(8, INPUT);
  digitalWrite(8, HIGH);
  lcd.begin(16, 2);
  lcd.print("   Interface");
  lcd.setCursor(0, 1);
  lcd.print("Raindrop Sensor");
  delay(2000);
  lcd.clear();
  lcd.print("Sensor Hujan");
  lcd.setCursor(0, 1);
  lcd.print("Status:");
}

void loop(){
  if (digitalRead(8)==0){    
    lcd.setCursor(7,1);
    lcd.print("Hujan");
  }
  else {    
    lcd.setCursor(7,1);
    lcd.print("Cerah");
  }
}
