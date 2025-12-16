#ifndef DRIVE_H
#define DRIVE_H 
#include <Arduino.h>
#include "Motor.h"

class Drive {
    private:
        Motor leftMotor;
        Motor rightMotor;
    public:
        Drive(Motor left, Motor right);
        void forward(int speed, int distance);
        void backward(int speed, int distance);
        void stop();
        void turn(int degree, int speed);
        void pivotTurn(int degree, int speed);
};


#endif 