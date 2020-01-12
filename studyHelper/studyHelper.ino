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
int distanceTolerance = 2;
bool triggered;

void setup() {
  // put your setup code here, to run once:
  setDistanceUpper = 0;
  setDistanceLower = 0;
  d.setuptriggerpin();
  triggered = false;
  oled.startup();
  t.start(1);
  pinMode(7, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(triggered)
  {
    if(d.measure() > setDistanceUpper || d.measure() < setDistanceUpper)
    {
      s.off();
      triggered = false;
    }
  }
  else
  {
    if(digitalRead(7) == HIGH)
    {
      // Use a tolerance to compensate for sensor drift
      setDistanceUpper = d.measure() + distanceTolerance;
      setDistanceLower = d.measure() - distanceTolerance;
    }
    
    if(!t.isTimerDone())
    {
      oled.show(t.getTimeLeft());
      if(d.measure() > setDistanceUpper || d.measure() < setDistanceUpper)
      {
        s.on();
        triggered = true;
        t.pause();
      }
    }
    else
    {
      oled.endMessage();
    }
  }
}
