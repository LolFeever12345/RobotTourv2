#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>
#include <Encoder.h>

class Motor {
    private:
        // Motor control pins
        int IN1;
        int IN2;
        int ENA;

        //Encoder data
        const int CPR = 900;
        const float wheelDiameter = 40; // in mm
        const float CPM = (PI*wheelDiameter)/(CPR*1.0); // mm per count

        //PID constants
        float Kp;
        float Ki; 
        float Kd;

        //Timing for PID
        unsigned long prevTime = 0;
        float prevError = 0;
        float prevDistance = 0.0;
        float dt;

        //PID variables
        float integral = 0;
        float prevDerivative = 0.0;

    public:
        Motor(int in1, int in2, int ena, int encA, int encB, float kp, float ki, float kd):
            IN1(in1), IN2(in2), ENA(ena), 
            encoder(encA, encB),
            Kp(kp), Ki(ki), Kd(kd)
            {
                pinMode(IN1, OUTPUT);
                pinMode(IN2, OUTPUT);
                pinMode(ENA, OUTPUT);
            }
        Encoder encoder;
        void forward(int speed);
        void backward(int speed);
        void stop();
        void resetEncoder();
        float distance();
        float rpm(float dt);
        long encoderCount();
        void movePID(long speed);

};
    


#endif