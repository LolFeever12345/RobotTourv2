#include <Arduino.h>
#include <Encoder.h>
#include "Motor.h"
#include "MotorData.h"
#include "DualMotorData.h"


Motor rightMotor(8, 9, 11, 3, 5, 1.2, 0.8, 0.02);
Motor leftMotor(6, 7, 10, 2, 4, 1.2, 0.0, 0.0);
MotorData rightMotorData(rightMotor);
MotorData leftMotorData(leftMotor);
DualMotorData dualMotorData(rightMotor, leftMotor);




void setup() {
  Serial.begin(9600);
}

void loop() {
  long now = millis();
  if(now < 10000){
    rightMotor.movePID(200);
  }
  rightMotor.stop();
} 
