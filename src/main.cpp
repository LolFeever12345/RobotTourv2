#include <Arduino.h>
#include <Encoder.h>
#include "Motor.h"
#include "Drive.h"
#include "PID.h"
#include "MotorData.h"

Motor rightMotor(9, 10, 7, 2, 3);
MotorData rightMotorData(rightMotor);


void setup() {
  Serial.begin(9600);
}

void loop() {
  rightMotorData.speedData();
  while(1);
}
