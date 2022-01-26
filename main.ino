#include "SevSeg.h"
SevSeg sevseg; 
int buz = 13;
void setup(){
    Serial.begin(9600);
    pinMode(10, OUTPUT);
    pinMode(11,INPUT);
    pinMode(buz,OUTPUT);
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};

    byte cc = COMMON_CATHODE; 
    sevseg.begin(cc, numDigits, digitPins, segmentPins, true);
    sevseg.setBrightness(90);
}

void loop(){
  long duration, distance;
  digitalWrite(10,HIGH);
  delayMicroseconds(1000);
  digitalWrite(10, LOW);
  duration=pulseIn(11, HIGH);
  distance =(duration/2)/29.1;
  delay(10);
  Serial.println(distance);
  if (distance<=9){
    digitalWrite(buz,HIGH);
    sevseg.setNumber(distance, 0);
    sevseg.refreshDisplay(); 
    delay(100);
  }
  else if (distance>9){
    digitalWrite(buz,LOW);
    sevseg.setNumber(69, 1);
    sevseg.refreshDisplay(); 
  }
}
