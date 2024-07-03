/*************************************
 * Program : Project 24. Early warning sistem via SMS (banjir)
 * Input   : Sensor Ultrasonic HC-SR04, Modem SMS Getway
 * Output  : LCD 2x16
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
 
LiquidCrystal lcd(2,3, 4, 5, 6, 7);

const int rxpin = 8; 
const int txpin = 9;  
SoftwareSerial gsm(rxpin, txpin); 

const int TRIGPIN = 10; 
const int ECHOPIN = 11;

String inString="";
//--------------ganti nomor penerima dengan nomor Anda
String noPenerima="085xxxxxxxxx";

unsigned int jarak, timer, Status;
char f1,f2,f3;
char str,f;

void setup(){  
  gsm.begin(9600);    
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT); 
  lcd.begin(16, 2);
  lcd.print("Tes Koneksi...");
  delay(1000);  
  do{
  gsm.println("AT");
  getmodem();
  }
  while(inString == "OK");
  lcd.clear();
  lcd.print(" Koneksi OK ");
  delay(1000);    
  lcd.clear();
  lcd.print("Early Warning");
  lcd.setCursor(0,1);
  lcd.print("System banjir"); 
  delay(2000);    
}

//====================program utama
void loop(){
  baca_sensor();
  delay(10);
  baca_sensor();
  lcd.setCursor(0,0);
  lcd.print("Jarak air:");  
  lcd.setCursor(0,1);
  lcd.print("Status=");  
  lcd.setCursor(10,0);
  lcd.print(jarak);
  lcd.print("cm  ");
  if (jarak > 100) {
     lcd.setCursor(7,1);
     lcd.print("Aman    ");
     Status=1;
     if (f1==1){
       kirim_sms();
       f1=0;
       f2=0;
       f3=0;
     }
  }
  else if ((jarak < 90) && (jarak > 75)){
  lcd.setCursor(7,1);
  lcd.print("Waspada ");
    if (f1==0){
      Status=2;
      kirim_sms();
    }
  f1=1;  
  f2=0;
  f3=0;
  }
  else if ((jarak < 65) && (jarak > 50)){
  lcd.setCursor(7,1);
  lcd.print("Awas!   ");  
    if (f2==0){
      Status=3;
      kirim_sms();
    }
  f1=0;
  f2=1;
  f3=0;
  }       
  else if (jarak < 40){
  lcd.setCursor(7,1);
  lcd.print("Bahaya!!");  
    if (f3==0){
      Status=4;
      kirim_sms();
    } 
  f1=0;
  f2=0;
  f3=1;
  }
  delay(4000);
}
//====================================baca data serial
void getmodem(){ 
 f=1; 
 inString="";
 while(f){
   if(gsm.available()){
       str=gsm.read();               
       switch (str){
           case '\r': break;
           case '\n':f=0; break;
           default:inString+=(char)str;
         }        
     }
 }
} 
//===================================baca sensor 1
void baca_sensor(){   
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   
  timer = pulseIn(ECHOPIN, HIGH);        
  jarak= timer/58; 
}

//====================================kirim SMS
void kirim_sms(){
    gsm.print("AT+CMGS=");   
    gsm.println(noPenerima);
    delay(1000);    
    gsm.print("Jarak:");
    gsm.print(jarak);
    switch (Status){
    case 1: gsm.print("cm, Status= Aman");break;
    case 2: gsm.print("cm, Status= Waspada");break;
    case 3: gsm.print("cm, Status= Awas!");break;
         case 4: gsm.print("cm, Status= Bahaya!!");break;
    }
    gsm.write((byte)26);
    gsm.println(); 
    lcd.clear();
    lcd.print("Kirim SMS....");
    delay(2000);
}
