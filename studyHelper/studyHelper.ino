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
  Serial.begin(9600);
  oled.startup();
}

void loop() {
  // put your main code here, to run repeatedly:
  t.start(0.25);             // in minutes
  while(!t.isTimerDone())
  {
    if(md.PIRSensor())      // alert if the PIR sensor goes off
    {
       s.on();
       int distance = d.measureDistance();
    }
    else
    {
       s.off();
    }
     timeLeft = t.getTimeLeft();
     Serial.print(timeLeft);
     Serial.print("\n");
     oled.show(timeLeft);    // Draw number of tries and timer
     delay(1000);
  }
  oled.endMessage();
}

/*
void loop() {
  // put your main code here, to run repeatedly:
  
  t.start(0.1);
  Serial.print("time beginning: ");
  Serial.print(millis());
  Serial.print("\n");
  while(!t.isTimerDone())
  {
    Serial.print("current time: ");
    Serial.print(millis());
    Serial.print("\n");
    timeLeft = t.getTimeLeft();
    Serial.print("time left: ");
    Serial.print(timeLeft);
    Serial.print("\n");
    t.start(0.1);
    Serial.print("time left after start: ");
    Serial.print(timeLeft);
    Serial.print("\n");
  }
  t.restart(0.1);
  Serial.print("time at restart: ");
  Serial.print(t.getTimeLeft());
  Serial.print("\n");
}
*/
