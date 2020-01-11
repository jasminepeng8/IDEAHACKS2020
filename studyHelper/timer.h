#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer
{
  public:
	  void start(int minutes);
	  int getTimeLeft();
	  bool isTimerDone();
    void restart();
  private:
	  int startTime, endTime;
	  int duration;
};

#endif
