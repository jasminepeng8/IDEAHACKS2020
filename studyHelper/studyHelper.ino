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

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(md.PIRSensor())
  {
    s.on();
    int distance = d.measureDistance();
  }
  else
  {
    s.off();
  }
}
