#include <Arduino.h>
#define MeMCore_H
#include <Makeblock.h>
#include <SoftwareSerial.h>

MeDCMotor MotorL(M1);
MeDCMotor MotorR(M2);
#define MeMCore_H

class Car
{
public:
  uint8_t moveSpeed = 250;
  double lineDirIndex = 10;
  double dist;

  //methods
  void forward();
  void backward();
  void turnLeft();
  void turnRight();
  void stop();
};
