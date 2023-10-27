#include "Output.h"

Output::Output() {}

Output::Output(int p, bool s, bool i) : _pin(p) { this->setPin(p, s, i); }

void Output::setPin(int p, bool s, bool i)
{
    this->_pin = p;
    pinMode(_pin, OUTPUT);
    s = (s == HIGH) ? HIGH : LOW;
    this->_invert = i;

    digitalWrite(_pin, (s ^ i));
}


void Output::set(bool s)
{
    this->_state = (s == HIGH) ? HIGH : LOW;
    digitalWrite(_pin, (this->_state ^ this->_invert));
}

void Output::toggle() { this->set(!this->_state); }

int Output::getState() { return (this->_state); }

int Output::checkState()
{
    this->_state = digitalRead(_pin);
    return (this->_state ^ this->_invert);
}

void Output::on(void) { this->set(true); }
void Output::open(void) { return this->on(); }

void Output::off(void) { this->set(false); }
void Output::close(void) { return this->off(); }
