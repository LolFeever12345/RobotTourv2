// #ifndef MOTOR_H
// #define MOTOR_H
// #include <Arduino.h>
// #include <Encoder.h>

// class Motor {
//     private:
//         // Motor control pins
//         int IN1;
//         int IN2;
//         int ENA;

//         //PID constants
//         float Kp;
//         float Ki; 
//         float Kd;

        
//         //Encodler
//         Encoder myEncoder;

//         //Timing for PID
//         unsigned long prevTime = 0;
//         float prevError = 0.0;
//         float prevDistance = 0.0;

//         //PID variables
//         float integral = 0;
//         float prevDerivative = 0.0;

//                 //Encoder data
//         const int CPR = 900;
//         const float wheelDiameter = 40; // in mm
//         const float CPM = (PI*wheelDiameter)/(CPR*1.0); // mm per count

//     public:
//         Motor(int in1, int in2, int ena, float kp, float ki, float kd, Encoder encoder){   
//                 this->IN1 = in1;
//                 this->IN2 = in2;
//                 this->ENA = ena;
//                 this->myEncoder = encoder;
//                 this->Kp = kp;
//                 this->Ki = ki;
//                 this->Kd = kd;
//                 //Set pin modes
//                 pinMode(IN1, OUTPUT);
//                 pinMode(IN2, OUTPUT);
//                 pinMode(ENA, OUTPUT);
//         }
//         void forward(int speed);
//         void backward(int speed);
//         void stop();
//         void resetEncoder();
//         float distance();
//         float rpm(float dt);
//         long encoderCount();
//         void movePID(long speed);

// };
    


// #endif