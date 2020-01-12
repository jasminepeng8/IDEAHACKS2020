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
  t.start(.5);
  oled.startup();
  pinMode(5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(5) == HIGH)
  {
    t.pause();
  }
  
  else if(!t.isTimerDone())
  {
    oled.show(t.getTimeLeft());
    t.play();
  }
  else
  {
    oled.endMessage();
  }
}
  /*if(md.PIRSensor())
  {
    s.on();
    int distance = d.measureDistance();
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
    s.off();
  }
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
