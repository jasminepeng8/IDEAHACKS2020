#define Sensor 7 
#include "motionDetect.h"
 
//PIR: Passive Infrared 
int MotionDetect::PIRSensor()
{
  if(digitalRead(Sensor) == HIGH) 
  {
      PIRValue = 1;  
      Serial.println("Motion detected.");
  }
  if(digitalRead(Sensor) == LOW) 
  {
      PIRValue = 0; 
      Serial.println("Motion ended."); 
  }
  return PIRValue; 
}
