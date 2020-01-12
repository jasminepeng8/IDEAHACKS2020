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
    void pause();
    void play();
  private:
	  double startTime, endTime, duration, pauseTime;
    int restartCount;
    bool paused;
    void restart(double minutes);
};

#endif
