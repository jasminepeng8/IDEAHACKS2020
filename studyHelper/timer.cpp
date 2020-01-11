
#include "timer.h"
#include <Arduino.h>

Timer::Timer() 
{
  restartCount = 0;
  startTime = 0;
  endTime = 0;
  duration = 0;
}

void Timer::start(double minutes)
{
    startTime = millis();
    duration = minutes * 60 * 1000;
    endTime = startTime + duration;
}

double Timer::getTimeLeft()
{   
    double timeleft = endTime - millis(); 
    if (timeleft <= 0)
        return 0;
    else
        return timeleft;
}

bool Timer::isTimerDone()
{
    double currentTime = millis();
    if (currentTime >= endTime)
    {
      return true;   
    }
    return false;
}

void Timer::restart()
{
    startTime = millis();
    endTime = 0.0;
}
