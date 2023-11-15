// code for keeping robot straigh and moving forwards

// idea for error correction, create list then calculate end difference. if different adjust speed of motors accordingly

#include "Arduino.h"
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(4);

int motor1, motor2, motor3, motor4, turn;

void setup() {
  // put your setup code here, to run once:

  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
  myMotor3->run(FORWARD);
  myMotor4->run(FORWARD);

}

void loop() {
  // put your main code here, to run repeatedly:
  Turning(turn);

  myMotor1->setSpeed(motor1);
  myMotor2->setSpeed(motor2);
  myMotor3->setSpeed(motor3);
  myMotor4->setSpeed(motor4);
  
  if (turn =! 0) {
    delay(1000);
    turn = 0;
  };

}

void Turning(int turn) {

    if (turn == 0) {      // perhaps instead of setting these speeds just minus/add to existing speed
    motor1 = 255;
    motor2 = 255;
    motor3 = 255;
    motor4 = 255;
  };

  if (turn == 1) {  // turn left
    // motor1 = 255;
    // motor2 = 255;
    motor3 -= 100;
    motor4 -= 100;    // keeps robot set to these speeds, will calc how long needed to complete turn
  };

    if (turn == 2) {    // turn right
    motor1 -= 100;
    motor2 -= 100;
    // motor3 = 255;
    // motor4 = 255;
  };

}