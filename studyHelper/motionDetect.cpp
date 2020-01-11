#ifndef MOTION_DETECT_H 
#define MOTION_DETECT_H 
#define Sensor 7 
#include <Arduino.h> 
 
class MotionDetect 
{ 
//PIR: Passive Infrared 
  static int PIRSensor()
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
}; 
#endif 



