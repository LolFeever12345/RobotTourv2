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

long Motor::encoderCount() {
    return encoder.read();
}

void Motor::movePID(long speed) {
    //Delta Time Computation
    unsigned long currentTime = millis();
    dt = (currentTime - prevTime)/1000.0; // in seconds
    if(dt < 0.008) return; // prevent division by zero
    prevTime = currentTime;

    // Compute Actual Speed
    float currentDistance = distance();
    float deltaDistance = currentDistance - prevDistance;
    prevDistance = currentDistance;

    float currentSpeed = deltaDistance / dt; // in mm/s

    // Compute PID
    float error = speed - currentSpeed;
    integral += error * dt;
    integral = constrain(integral, -255.0f, 255.0f); // Anti-windup

    float derivative = (error - prevError) / dt;
    derivative = 0.9*prevDerivative + 0.1*derivative; // Low-pass filter
    prevDerivative = derivative;
    prevError = error; 

    float output = Kp * error + Ki * integral + Kd * derivative;
    output = constrain(output, -255.0f, 255.0f);

    //Compute PWM and direction from sign

    if(output >= 0) {
        output = constrain(output, 30.0f, 255.0f); // Minimum PWM to overcome static friction
        forward((int)output);
    } else {
        output = constrain(output, -255.0f, -30.0f); // Minimum PWM to overcome static friction
        backward((int)(-output));
    }
    // Serial.print("Current Speed: ");Serial.print(currentSpeed);Serial.print(" , ");Serial.println(output);
    // Serial.print("Target Speed: ");Serial.print(speed);Serial.print(" Error: ");Serial.println(error);
    Serial.print(currentTime);Serial.print(",");Serial.println(currentSpeed);


}
