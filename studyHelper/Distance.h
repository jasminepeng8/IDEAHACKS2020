
#ifndef  DISTANCE_H
#define DISTANCE_H

#include <Arduino.h>
#define trig  5
#define echo  6

/*
pinMode(trigPin, OUTPUT); 
pinMode(echopin, INPUT);
float duration, distance; 
int trigPin  = 5; 
int echopin = 6;
int distance = 0;
int echoPin = 0; 
*/
class Distance
{
public:
  Distance(); 
  int measure(); 
  void setuptriggerpin(); 
  //void setup(); 
  //void getDistance(); 
private:
 // void setuptriggerpin(); 
  int _trigpin; 
  int _echopin; 
};

#endif
