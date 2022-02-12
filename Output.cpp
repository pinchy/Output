#include "Output.h"
#include <Arduino.h>

Output::Output(int p, int s, bool i) : _pin(p)
{
    pinMode(_pin, OUTPUT);
    s = (s == HIGH) ? HIGH : LOW;
    this->_invert = i;

    digitalWrite(_pin, (s ^ i));
}

void Output::set(int s)
{
    this->_state = (s == HIGH) ? HIGH : LOW;
    digitalWrite(_pin, (this->_state ^ this->_invert) );
}

void Output::toggle()
{
    this->set(!this->_state);
}

int Output::getState()
{
    return (this->_state ^ this->_invert);
}

int Output::checkState()
{
    this->_state = digitalRead(_pin);
    return (this->_state ^ this->_invert);
}

void Output::on(void)
{
    this->set(true);
}

void Output::open(void)
{
    return this->on();
}

void Output::off(void)
{
    this->set(false);
}

void Output::close(void)
{
    return this->off();
}
