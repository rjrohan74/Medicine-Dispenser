#include<time.h>
#include<TimeAlarms.h>
#include<Stepper.h>
const int stepPin = 5; 
const int dir = 6; 
 
void setup() {
  pinMode(stepPin,OUTPUT); 
  pinMode(dir,OUTPUT);
  Serial.begin(9600);
  setTime(17,30,0,8,20,18); //can be changed currently set at 5:30pm august 20 2018
  Alarm.alarmRepeat(18,15,0,GiveMedicine); //call function GiveMedicine() at 8:15 pm everyday
}
void loop() {
  digitalWrite(dir,HIGH); 
  Clock();  //displays time
  Alarm.delay(3000);
}
void GiveMedicine() {
  for(int x=1; x<=33; x++) {  //turn the stepper through 60 degrees
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  
  }
}
void Clock() {
  Serial.print(hour());
  printdig(minute());
  printdig(second());
  Serial.println();
}
void printdig(int dig) {
  Serial.print(":");
  if(dig<10)
  Serial.print('0');
  Serial.print(dig);
}

