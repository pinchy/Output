/*
 * Wrapper class for standard output pin functions.
 * @author: Sebastien Eckersley-Maslin
 * @date: 8 Sep 2019
 */
#ifndef OUTPUT_H
#define OUTPUT_H

#define ON HIGH
#define OFF LOW

class Output
{
    private:
        int _pin;
        int _state;
        int _active;
        int _invert;

    public:
        /*
         * Constructor, initaite the Output object on Pin p and set the state to
         * s and invert the output
         */
        Output(int p, int s = false, bool i = false);
        Output();

        /*
         * Set the pin, initaite the Output object on Pin p and set the state to
         * s and invert the output
         */
        void setPin(int p, int s = false, bool i = false);

        /*
         * Set the output to the passed variable (ON or OFF) and update
         * the internal value
         */
        void set(int s);

        /*
         * Toggle (flip) the state of the pin and update the intenral variable
         */
        void toggle(void);

        /*
         * get the state (as represented by the internal variable)
         * Note: This could be different to the pin if another service has
         * affected the pin directly.
         */
        int getState(void);

        /*
         * check the state against the actual pin, update the internal
         * variable and return this state
         */
        int checkState(void);

        /*
         * Set the state on
         */
        void on(void);
        void open(void);

        /*
         * Set the state off
         */
        void off(void);
        void close(void);
};

#endif