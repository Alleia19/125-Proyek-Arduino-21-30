/*************************************
 * Program : Project 23. Digital voltmeter tampil LCD maksimal 5Vdc
 * Input   : Sensor Fingerprint, DS1307 
 * Output  : LCD 2x16, BUZZER
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup(){ 
  pinMode(8,INPUT);
  digitalWrite(8,HIGH);  
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("DigitalVoltmeter");
  lcd.setCursor(0,1);
  lcd.print(" Vin mak 5Volt");  
  delay(3000);
  lcd.clear();
}

void loop(){
  int adc=(analogRead(A0));
  float vin = adc * (5.0 / 1023.0);
  lcd.setCursor(0,0);
  lcd.print("Vin:");
  lcd.print(vin);
  lcd.print("V    ");
  if (digitalRead(8)==0){
    byte hold=1;
    lcd.setCursor(0,1);
    lcd.print("hold on");
    delay(1000);
    do{
      if (digitalRead(8)==0){
        lcd.setCursor(0,1);
        lcd.print("          ");
        delay(1000);
        hold=0;
      }
    }
    while(hold);
  }
  delay(500);
}


