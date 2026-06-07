#include "buzzer_controller.h"
#include <Arduino.h>

BuzzerController::BuzzerController(int pin)
    : _pin(pin) {}

void BuzzerController::begin()
{
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
}

void BuzzerController::play(const int *notes, size_t length, int duration)
{
  for (size_t i = 0; i < length; ++i)
  {
    int freq = notes[i];
    if (freq <= 0)
    {
      delay(duration);
      continue;
    }
    tone(_pin, freq, duration);
    delay((int)(duration * 1.25));
    noTone(_pin);
  }
}
