#ifndef PID_H
#define PID_H
#include <Arduino.h>
#include <Encoder.h>
#include "Motor.h"

class PID {
    private:
        Motor& motor;
        double kp;
        double ki;
        double kd;
        long prevDistance = 0;
        float integral = 0;
        float prevError = 0;
    public:
        PID(Motor& motor, double p, double i, double d);
        long update(float dt, float targetSpeed);
};


#endif