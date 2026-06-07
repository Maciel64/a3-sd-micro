#include "led_controller.h"
#include <Arduino.h>

LedController::LedController(int greenPin, int redPin)
    : _greenPin(greenPin), _redPin(redPin), _openState(false), _greenState(false), _lastToggle(0), _blinkInterval(500) {}

void LedController::begin()
{
    pinMode(_greenPin, OUTPUT);
    pinMode(_redPin, OUTPUT);

    digitalWrite(_greenPin, LOW);
    digitalWrite(_redPin, LOW);
    _lastToggle = millis();
}

void LedController::loop()
{
    if (millis() - _lastToggle <= 2000)
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
    else
    {
        digitalWrite(_greenPin, LOW);
        digitalWrite(_redPin, LOW);
    }
}

void LedController::setOpen(bool open)
{
    
    _openState = open;
    _lastToggle = millis();
}

bool LedController::status() const
{
    return _openState;
}