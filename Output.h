/*
 * Wrapper class for standard output pin functions.
 * @author: Sebastien Eckersley-Maslin
 * @date: 8 Sep 2019
 */
#ifndef OUTPUT_H
#define OUTPUT_H

#include <Arduino.h>

#define ON HIGH
#define OFF LOW

class Output
{
    private:
        int _pin;
        bool _state;
        bool _active;
        bool _invert;

    public:
        /**
         * @brief Initaite the Output object on Pin p and set the state to
         * s and invert the output
         *
         * @param p the target pin
         * @param s the initial state (default LOW)
         * @param i invert the output (default false)
         */
        Output(int p, bool s = false, bool i = false);

        /**
         * @brief Initialise the output object. Need to call setPin() prior to use
         *
         */
        Output();

        /**
         * @brief Set the pin, initial state and inverse state
         * @param p the target pin
         * @param s the initial state (default LOW)
         * @param i invert the output (default false)
         */
        void setPin(int p, bool s = false, bool i = false);

        /**
         * @brief get the pin number
         * @return (int) the pin number
         */
        int getPin(void) { return this->_pin; }


        /*
         * Set the output to the passed variable (ON or OFF) and update
         * the internal value
         */

        /**
         * @brief Set the output to the passed state
         * @param s the state to set the output to
         */
        void set(bool s);

        /**
         * @brief Toggle (flip) the state of the pin
         */
        void toggle(void);

        /**
         * @brief get the state (as represented by the internal variable)
         * Note: This could be different to the pin if another service has
         * affected the pin directly.
         * @return (int) the internal state
         */
        int getState(void);

        /**
         * @brief check the state against the actual pin, update the internal
         * variable and return this state
         * @return (int) the pin state
         */
        int checkState(void);

        /*
         * Set the state on
         */

        /**
         * @brief Set the pin to ON/HIGH
         *
         */
        void on(void);
        void open(void);

        /**
         * @brief Set the pin to OFF/LOW
         *
         */
        void off(void);
        void close(void);
};

#endif