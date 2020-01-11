
#include "timer.h"
#include <Arduino.h>

void Timer::start(int minutes)
{
    startTime = (millis() / 1000) * 60;
    endTime = startTime + minutes;
}

int Timer::getTimeLeft()
{
    int timeleft = endTime - ((millis() / 1000) * 60);
    if (timeleft > 0)
        return timeleft;
    else
        return 0;
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
