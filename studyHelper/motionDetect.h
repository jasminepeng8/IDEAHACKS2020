#ifndef MOTION_DETECT_H 
#define MOTION_DETECT_H 
#define Sensor 7 
#include <Arduino.h> 
 
class MotionDetect 
{ 
  public: 
  static int PIRSensor(); 
  private:
  int PIRValue = 0; 
}; 
 
#endif 




