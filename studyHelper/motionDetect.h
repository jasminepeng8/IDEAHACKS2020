#ifndef MOTION_DETECT_H 
#define MOTION_DETECT_H 
#define SENSOR_PORT 6
#define LED 13
#include <Arduino.h> 
 
class MotionDetect 
{ 
  public: 
  MotionDetect(); 
  int PIRSensor(); 
  void PIRSensorTrial(); 
  void SensorTest(); 
  private:
  int PIRValue; 
 long unsigned int lowIn;
 long unsigned int pause = 5000;
 bool lockLow = true;
 bool takeLowTime;
}; 
 
#endif 
