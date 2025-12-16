#include <Arduino.h>
#include "MotorData.h"
#include "Motor.h"

MotorData::MotorData(Motor& m) : motor(m) {}

void MotorData::speedData() {
    motor.resetEncoder();
    for(int i = 0; i<=117;i++){
        long currentPWM = i+138; // PWM values from 51 to 255
        motor.forward(currentPWM);
        delay(5000); // Run motor for 5 seconds
        motor.stop();
        Serial.print("PWM: "); Serial.print(currentPWM);
        Serial.print(" Speed: "); Serial.println(motor.rpm(5.0));
        motor.resetEncoder();
        delay(1000);
    }
}