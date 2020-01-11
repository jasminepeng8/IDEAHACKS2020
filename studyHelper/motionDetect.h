#ifndef MOTION_DETECT_H 
#define MOTION_DETECT_H 
#define SENSOR_PORT 6
#include <Arduino.h> 
 
class MotionDetect 
{ 
  public: 
  MotionDetect(); 
  int PIRSensor(); 
  private:
  int PIRValue; 
}; 
 
#endif 
