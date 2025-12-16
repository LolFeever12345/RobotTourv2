#include <Arduino.h>
#include "PID.h"

PID::PID(Motor& motor, double p, double i, double d) : motor(motor) {
    kp = p;
    ki = i;
    kd = d;
}

long PID::update(float dt, float targetSpeed) {
    long diffDistance = motor.distance() - prevDistance;
    prevDistance = motor.distance();
    float speed = diffDistance / dt; // speed in mm/s
    float error = targetSpeed - speed;

    // Proportional term
    float Pout = kp * error;

    // Integral term
    integral += error * dt;
    float Iout = ki * integral;

    // Derivative term
    float derivative = (error - prevError) / dt;
    float Dout = kd * derivative;
    prevError = error; 

    return Pout + Iout + Dout;
}