#ifndef SPEAKER_H
#define SPEAKER_H

#define SPEAKER_PORT 8

#include <Arduino.h>
#include "pitches.h"

class Speaker
{
  public:
    Speaker();
    void on();
    void off();
    void increaseNote();
    void decreaseNote();
  private:
    // notes in increasing pitch
    int notes[8] = {
      NOTE_C3, NOTE_F3, NOTE_C4, NOTE_G4, NOTE_E5, NOTE_E6
    };
    int currentNote;
};

#endif
