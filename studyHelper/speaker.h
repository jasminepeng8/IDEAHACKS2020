#ifndef SPEAKER_H
#define SPEAKER_H

#define SPEAKER_PORT 8;

#include <Arduino.h>

class Speaker
{
  public:
    Speaker();
    void on();
    void off();
    //void increaseVolume();  Not yet sure how to implement
    //void decreaseVolume();
  private:
};

#endif
