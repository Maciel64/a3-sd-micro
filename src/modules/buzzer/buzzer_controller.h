#pragma once

#include <stddef.h>

class BuzzerController
{
public:
  explicit BuzzerController(int pin);
  void begin();
  // Play a list of notes (frequencies in Hz). duration is per-note ms.
  void play(const int *notes, size_t length, int duration = 150);

private:
  int _pin;
};
