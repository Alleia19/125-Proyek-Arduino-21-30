/*************************************
 * Program : Project 22. Digital voltmeter 7 segment max 5VDC
 * Input   : Sensor Fingerprint, DS1307 
 * Output  : LCD 2x16, BUZZER
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
word miliVolt;
byte seven_seg_digits[10][7] = { { 0,0,0,0,0,0,1 },  // = 0
                                 { 1,0,0,1,1,1,1 },  // = 1
                                 { 0,0,1,0,0,1,0 },  // = 2
                                 { 0,0,0,0,1,1,0 },  // = 3
                                 { 1,0,0,1,1,0,0 },  // = 4
                                 { 0,1,0,0,1,0,0 },  // = 5
                                 { 0,1,0,0,0,0,0 },  // = 6
                                 { 0,0,0,1,1,1,1 },  // = 7
                                 { 0,0,0,0,0,0,0 },  // = 8
                                 { 0,0,0,0,1,0,0 }   // = 9
                               };
void setup(){ 
  for(char i=2; i<13; i++){
    pinMode(i,OUTPUT);
  }
  pinMode(13,INPUT);
  digitalWrite(13,HIGH);  
}

void loop(){
  int adc=(analogRead(A0));
  float vin = adc * (5.0 / 1023.0);
  miliVolt = vin*100;
  displaySeg();
  if (digitalRead(13)==0){
    byte hold=1;
    do{
      displaySeg();
      if (digitalRead(13)==1){
        hold=0;
      }
    }
    while(hold);
  }
}

void displaySeg(){
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(9,0);
  sevenSegWrite(miliVolt/100);
  delay(7);
  digitalWrite(9,1);
  
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  sevenSegWrite((miliVolt%100)/10);
  delay(7);  
  
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
  sevenSegWrite((miliVolt%100)%10);
  delay(7);
}

void sevenSegWrite(byte segment) {
  byte pin = 2;
  for (byte segCount = 0; segCount < 7; ++segCount) {
    digitalWrite(pin, seven_seg_digits[segment][segCount]);
    ++pin;
  }
}


