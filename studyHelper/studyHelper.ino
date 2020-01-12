#include "motionDetect.h"
#include "speaker.h"
#include "timer.h"
#include "Distance.h"
#include "oledDisplay.h"

MotionDetect md;
Speaker s;
Timer t;
Distance d;
oledDisplay oled;

int setDistanceUpper;
int setDistanceLower;
int distanceTolerance = 3;
bool triggered;
int numberTriggered = 0;

void setup() {
  // put your setup code here, to run once:
  
  setDistanceUpper = d.measure() + distanceTolerance;
  setDistanceLower = d.measure() - distanceTolerance;
  triggered = false;
  oled.startup();
  t.start(1);
  pinMode(7, INPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
   d.setuptriggerpin();
  float dist = d.measure();
  
  if(triggered)
  {
    if(dist > setDistanceUpper || dist < setDistanceLower)
    {
      s.off();
      triggered = false;
      t.play();
    }
  }
  else if(dist > 1000)
    oled.show(t.getTimeLeft());
  else
  {
    if(digitalRead(7) == HIGH)
    {
      // Use a tolerance to compensate for sensor drift
      float startDis = dist;  
      setDistanceUpper = startDis + distanceTolerance;
      setDistanceLower = startDis - distanceTolerance;
    }
    
    if(!t.isTimerDone())
    {
      Serial.println(dist);
      //Serial.println(setDistanceUpper); 
      //Serial.println(setDistanceLower); 
      oled.show(t.getTimeLeft());
      if(dist > setDistanceUpper || dist < setDistanceLower)
      { 
        s.on();
        triggered = true;
        t.pause();
        numberTriggered += 1;
        oled.updateNumTrigger(numberTriggered);
      }
    }
    else
    {
      oled.endMessage();
    }
  }
  Serial.println();
  //delayMicroseconds(50);
}
