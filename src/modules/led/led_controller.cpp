#include "led_controller.h"
#include <Arduino.h>

LedController::LedController(int greenPin, int redPin)
    : _greenPin(greenPin), _redPin(redPin), _openState(false), _greenState(false), _lastToggle(0), _blinkInterval(500) {}

void LedController::begin()
{
    pinMode(_greenPin, OUTPUT);
    pinMode(_redPin, OUTPUT);

    digitalWrite(_greenPin, HIGH);
    digitalWrite(_redPin, HIGH);
}

void LedController::loop()
{
    if (_openState)
    {
        digitalWrite(_greenPin, HIGH);
        digitalWrite(_redPin, LOW);
    }
    else
    {
        digitalWrite(_greenPin, LOW);
        digitalWrite(_redPin, HIGH);
    }
}

void LedController::setOpen(bool open)
{
    _openState = open;
}

bool LedController::status() const
{
    return _openState;
}