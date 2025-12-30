#include <Arduino.h>
#include <Encoder.h>


Encoder myEnc(3,5);
//Motor rightMotor(8, 9, 11, myEnc, 1.0, 0.0, 0.0);

unsigned long current = 0.0;
unsigned long previous = 0.0;
const long interval = 15.0;
long tSpeed = 500.0; //mm /s 
float CPM = (40.0*PI)/900.0; //mm / cnt

float current_dist = 0.0;
float prev_dist = 0.0;
float delta_dist = 0.0;

float dt = 0.0;
float cum_err = 0.0;

float Kp = 1.0;
float Ki = 1.75;

void setup() {
  Serial.begin(9600);
  Serial.println("Sanity Check/I want Ice Cream");
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  

  // long newPosition = myEnc.read();
  // long oldPosition = newPosition;

  // if (newPosition != oldPosition){
  //   oldPosition = newPosition;
  //   Serial.println(newPosition);
  // }
  current = millis();
  if (current - previous >= interval && current < 200.0*interval){
    current_dist = myEnc.read() * CPM;
    delta_dist =  current_dist - prev_dist;
    prev_dist =  current_dist;

    dt = current - previous;
    float cSpeed = delta_dist/(dt/1000);
    float error = tSpeed - cSpeed;
    cum_err += error*(dt/1000);
    int output =  Kp*error + Ki*cum_err;
    output = constrain(output, 0, 255);
    analogWrite(11,output);
    Serial.print(current);Serial.print(",");Serial.print(cSpeed);Serial.print(",");Serial.println(output);
    previous = current; //update time
  } 

  if (current > 202.0*interval){
    analogWrite(11,0);
    Serial.println("Over");
    while (true){ }

  }
} 
