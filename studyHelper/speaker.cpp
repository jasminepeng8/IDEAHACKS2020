#include "speaker.h"

Speaker::Speaker()
{
  currentNote = 0;
}

void Speaker::on()
{
  tone(SPEAKER_PORT, notes[currentNote]);
}

void Speaker::off()
{
  noTone(SPEAKER_PORT);
}

void Speaker::increaseNote()
{
  off();
  currentNote++;
  if(currentNote > 7)
    currentNote = 7;
  on();
}

void Speaker::decreaseNote()
{
  off();
  currentNote--;
  if(currentNote < 0)
    currentNote = 0;
  on();
}
