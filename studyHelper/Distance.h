
#ifndef  DISTANCE_H
#define DISTANCE_H

#include <Arduino.h>
const int trigPin  = 5; 
const int echopin = 6;
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
  Distance (int trig, int echo); 
  int measure(); 
  //void setup(); 
  //void getDistance(); 
private:
  void setuptriggerpin(); 
  int _trigpin; 
  int _echopin; 
};

#endif
