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
}
//measure distance function
int Distance::measure()
{
  float duration; 
  duration = pulseIn(_echopin, HIGH); //in seconds (but that's overall time)
  /*echoPin = digitalRead(echopin); 
  if (echoPin == HIGH)
  {
    time =   
  }
  else 
  {
    
  }*/
  int distance = 0; 
  if (duration != 0) 
  {
    distance = (duration*.0343)/2; 
    Serial.print("Distance found is "); 
    Serial.print(distance); 
  }
  /*
  return distance; 
   Serial.print(distance);
   Serial.print("in"); 
   */
   return distance;
}
  
