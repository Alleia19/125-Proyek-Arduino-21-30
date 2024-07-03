/*************************************
 * Program : Project 29. Interfacing Arduino dengan Sensor PIR
 * Input   : Sensor PIR HC-SR501
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
            
int PIR=  7;              
int flag_PIR = LOW;            

void setup() {
    pinMode(PIR, INPUT);     
    Serial.begin(9600);    
    Serial.println("Tes Sensor PIR HC-SR501..");
    delay(30000);
}
 
void loop(){ 
  if((digitalRead(PIR)==HIGH)&&(flag_PIR==LOW)){      
      Serial.println("Ada gerakan terdeteksi PIR...");     
      flag_PIR = HIGH;
    }
  else if ((digitalRead(PIR)==LOW)&&(flag_PIR == HIGH)){     
      Serial.println("Tidak ada gerakan ...");    
      flag_PIR = LOW;    
  }
}
