#pragma once

class LedController
{
public:
  explicit LedController(int greenPin, int redPin);
  void begin();
  void loop();

  void setOpen(bool open);

  bool status() const; // returns open state

private:
  int _greenPin;
  int _redPin;
  bool _openState;
  bool _greenState;
  unsigned long _lastToggle;
  unsigned long _blinkInterval;
};
