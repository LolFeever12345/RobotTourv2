#include "Motor.h"
#include <Arduino.h>
#include <Encoder.h>


void Motor::forward(int speed) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speed);
}

void Motor::backward(int speed) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, speed);
}

void Motor::stop() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);
}

float Motor::distance() {
    return encoder.read() * CPM;
}

void Motor::resetEncoder() {
    encoder.write(0);
}

float Motor::rpm(float dt) {
    return (encoder.read()/CPR)/(dt/60.0);
}
