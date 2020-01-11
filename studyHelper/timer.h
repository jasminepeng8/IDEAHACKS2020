#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer
{
  public:
    Timer();
	  void start(double minutes);
	  double getTimeLeft();
	  bool isTimerDone();
    void restart();
  private:
	  double startTime, endTime;
    int restartCount;
    double duration;
};

#endif
