const int triggerpin = 11; 
const int echopin = 12;
int distance = 0;
 
#ifndef  DISTANCE_H
#define DISTANCE_H

#include <Arduino.h>

class Distance
{
public:
void setup(); 
getDistance(); 
private:
void setuptriggerpin(); 
int measure(); 
};

#endif
