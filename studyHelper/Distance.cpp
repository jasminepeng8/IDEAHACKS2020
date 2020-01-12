#include "Arduino.h"
#include "Distance.h" 

//initial set up for the distance sensor 
/*
void Distance::setup()
{
pinMode(trigPin, OUTPUT); 
pinMode(echopin, INPUT);
}
*/

Distance::Distance()
{
pinMode(trig, OUTPUT); 
_trigpin = trig; 
pinMode(echo, INPUT);
_echopin = echo;  
}

//trigger pin set up to read 
void Distance::setuptriggerpin()
{
  digitalWrite(_trigpin, LOW);
  delayMicroseconds(5);
  digitalWrite(_trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigpin, LOW);
  delayMicroseconds(5);
}
//measure distance function
float Distance::measure()
{
  float duration; 
  duration = pulseIn(_echopin, HIGH); //in seconds (but that's overall time)

  float distance = 0; 
  if (duration != 0) 
  {
    distance = (duration*.0343)/2; 
    //Serial.print("\n Distance found is "); 
   //Serial.print(distance); 
  }
  else 
  {
   
    Serial.println("No distance"); 
  }
  /*
  return distance; 
   Serial.print(distance);
   Serial.print("in"); 
   */
   
   return distance;
}
  
