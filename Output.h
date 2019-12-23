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

    public:
        /* 
         * Constructor, initaite the Output object on Pin p and set the state to 0 (OFF) 
         */
        Output(int p);

        /* 
         * Constructor, initiate the Output object on Pin p and set the state to s 
         */
        Output(int p, int s);

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

        /*
         * Set the state off
         */
        void off(void);
}; 

#endif