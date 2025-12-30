// #include "DualMotorData.h"
// #include <Arduino.h>

// void DualMotorData::dualMotorSpeed() {
//     LeftMotor.resetEncoder();
//     RightMotor.resetEncoder();
//     for(int i = 1; i<=5;i++){
//         long currentPWM = i*51; // PWM values from 51 to 255
//         LeftMotor.forward(currentPWM);
//         RightMotor.forward(currentPWM);
//         delay(5000); // Run motor for 5 seconds
//         LeftMotor.stop();
//         RightMotor.stop();
//         Serial.print("PWM: "); Serial.print(currentPWM);
//         Serial.print(" Speed: "); Serial.print(LeftMotor.distance()/5.0);Serial.print(",");Serial.println(RightMotor.distance()/5.0);
//         LeftMotor.resetEncoder();
//         RightMotor.resetEncoder();
//         delay(1000);
//     }
// }