#include "motionDetect.h"

MotionDetect::MotionDetect()
{
   pinMode(SENSOR_PORT, INPUT); 
 //  pinMode(LED, OUTPUT); 
   PIRValue = 0; 
}
//PIR: Passive Infrared 
int MotionDetect::PIRSensor()
{
  
  if(digitalRead(SENSOR_PORT) == HIGH) 
  {
      PIRValue = 1;  
      digitalWrite(LED,HIGH); 
      Serial.println("Motion detected.");
  }
  if(digitalRead(SENSOR_PORT) == LOW) 
  {
      PIRValue = 0; 
      digitalWrite(LED, LOW); 
      Serial.println("Motion ended."); 
  }
    delay(1000); 
  return PIRValue; 
}

void MotionDetect::PIRSensorTrial()
{
  if(digitalRead(SENSOR_PORT) == HIGH) {
      if(lockLow) {
         PIRValue = 1;
         lockLow = false;
         Serial.println("Motion detected.");
         delay(50);
      }
      takeLowTime = true;
   }
   if(digitalRead(SENSOR_PORT) == LOW) {
    
      if(takeLowTime){
         lowIn = millis();
         takeLowTime = false;
         Serial.println("Low In: "); 
         Serial.println(lowIn); 
         Serial.println("\n working."); 
         delay(50); 
      }
        Serial.println("Time elapsed: "); 
         Serial.println(millis());
      if(!lockLow && millis() - lowIn > pause) {
         PIRValue = 0;
         lockLow = true;
         Serial.println("Motion ended.");
         delay(50);
      }
   }
}

void MotionDetect::SensorTest()
{
  if(digitalRead(SENSOR_PORT) == HIGH) 
  {
    Serial.println("Motion!"); 
  }
  else if(digitalRead(SENSOR_PORT) == LOW) 
  {
    Serial.println("No Motion!");
  }
  else 
  {
    Serial.println("Nothing detected."); 
  }
  delay(1000); 
}
