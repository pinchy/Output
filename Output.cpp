#include "Output.h"
#include <Arduino.h>

Output::Output(int p) : _pin(p)
{
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

Output::Output(int p, int s) : _pin(p)
{
    pinMode(_pin, OUTPUT);
    s = (s == HIGH) ? HIGH : LOW;
    digitalWrite(_pin, s);
}

void Output::set(int s)
{
    this->_state = (s == HIGH) ? HIGH : LOW;
    digitalWrite(_pin, _state);
}

void Output::toggle()
{
    this->set(!this->_state);
}

int Output::getState()
{
    return this->_state;
}

int Output::checkState()
{
    this->_state = digitalRead(_pin);
    return this->_state;
}

void Output::on(void)
{
    this->set(HIGH);
}

void Output::off(void)
{
    this->set(LOW);
}
