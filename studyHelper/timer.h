#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer
{
  public:
	  void start(int minutes);
	  double getTimeLeft();
	  bool isTimerDone();
    void restart();
  private:
	  double startTime, endTime;
};

#endif
