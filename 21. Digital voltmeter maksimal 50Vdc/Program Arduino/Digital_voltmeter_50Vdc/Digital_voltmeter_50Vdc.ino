/*************************************
 * Program : Project 21. Digital voltmeter maksimal 50Vdc
 * Input   : Sensor Voltage devider, Tombol Push ON 
 * Output  : LCD 2x16
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int hold,koma;

void setup(){ 
  pinMode(8,INPUT);
  digitalWrite(8,HIGH);  
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("DigitalVoltmeter");
  lcd.setCursor(0,1);
  lcd.print(" Vin mak 50Volt");  
  delay(3000);
  lcd.clear();
}

void loop(){
  int vin=(analogRead(A0));
  float voltage = vin * (5.0 / 1023.0);
  voltage=voltage/0.091;
  lcd.setCursor(0,0);
  lcd.print("Vin:");
  lcd.print(voltage);
  lcd.print("V    ");
  if (digitalRead(8)==0){
    hold=1;
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


