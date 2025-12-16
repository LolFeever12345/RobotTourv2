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
        const int CPR = 1200;
        const float wheelDiameter = 40; // in mm
        const float CPM = (PI*wheelDiameter)/(CPR*1.0); // mm per count
    public:
        Motor(int in1, int in2, int ena, int encA, int encB):
            IN1(in1), IN2(in2), ENA(ena), 
            encoder(encA, encB) 
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
};
    


#endif