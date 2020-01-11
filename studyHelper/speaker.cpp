#include "speaker.h"

Speaker::Speaker()
{
  
}

void Speaker::on()
{
  tone(SPEAKER_PORT, 262);
}

void Speaker::off()
{
  noTone(SPEAKER_PORT);
}

/*void Speaker::increaseVolume()
{
  
}

void Speaker::decreaseVolume()
{
  
}*/
