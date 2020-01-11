#include "motionDetect.h"

MotionDetect::MotionDetect()
{
   pinMode(SENSOR_PORT, INPUT); 
   PIRValue = 0; 
}
//PIR: Passive Infrared 
int MotionDetect::PIRSensor()
{
  if(digitalRead(SENSOR_PORT) == HIGH) 
  {
      PIRValue = 1;  
      Serial.println("Motion detected.");
  }
  if(digitalRead(SENSOR_PORT) == LOW) 
  {
      PIRValue = 0; 
      Serial.println("Motion ended."); 
  }
  return PIRValue; 
}
