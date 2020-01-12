
#include "timer.h"
#include <Arduino.h>

Timer::Timer() 
{
  restartCount = 0;
  startTime = 0;
  endTime = 0;
  duration = 0;
  pauseTime = 0;
  paused = false;
}

void Timer::start(double minutes)
{
    if (isTimerDone())
    {
      startTime = millis();
      duration = minutes * 60 * 1000;
      endTime = startTime + duration;
    }
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

void Timer::restart(double minutes)
{
    startTime = millis();
    duration = pauseTime;
    endTime = startTime + duration;
}

void Timer::pause()
{
    startTime = millis();
    if (!paused)
      pauseTime = endTime - startTime;
    endTime = startTime + pauseTime;
    paused = true;
}

void Timer::play()
{
  if (paused)
  {
    duration = pauseTime;
    restart(duration);
    pauseTime = 0;
    paused = false;
  }
}
