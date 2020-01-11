
#include "timer.h"
#include <Arduino.h>

void Timer::start(int minutes)
{
    startTime = (millis() / 1000) * 60;
    endTime = startTime + minutes;
}

int Timer::getTimeLeft()
{
    return (millis() / 1000) * 60;
}

bool Timer::isTimerDone()
{
    int currentTime = (millis() / 1000) * 60;
    if (currentTime >= endTime)
    {
      return true;   
    }
    return false;
}

void Timer::restart()
{
    startTime = 0;
    endTime = 0;
}
