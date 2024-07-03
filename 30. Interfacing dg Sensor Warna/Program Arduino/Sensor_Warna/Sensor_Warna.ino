/*************************************
 * Program : Project 30. Interfacing dg Sensor Warna
 * Input   : Sensor warna TCS3200
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
 
#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define sensorOut 7
int frequency = 0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() {
  // RED filtered 
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW); 
  Serial.print("R= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(100);
  // Green filtered 
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(100);
  // Blue filtered 
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  Serial.print("B= ");
  Serial.print(frequency);
  Serial.println("  ");
  delay(800);
}
