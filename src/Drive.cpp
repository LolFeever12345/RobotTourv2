#include <Arduino.h>
#include <Encoder.h>
#include "PID.h"   
#include "Drive.h"
#include "Motor.h"

Drive::Drive(Motor left, Motor right) : leftMotor(left), rightMotor(right) {}

void Drive::forward(int speed, int distance) {
    leftMotor.resetEncoder();
    rightMotor.resetEncoder();
    leftMotor.forward(speed);
    rightMotor.forward(speed);
    while (leftMotor.distance() < distance && rightMotor.distance() < distance) {
        // Wait until the desired distance is reached
        delay(10);
    }
    stop();
}
