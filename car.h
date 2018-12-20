#include <Arduino.h>
#include <Makeblock.h>
#include <SoftwareSerial.h>

MeDCMotor MotorL(M1);
MeDCMotor MotorR(M2);

class Car
{
public:
  uint8_t moveSpeed = 250;
  double lineDirIndex = 10;
  double dist;

  //methods
  void forward()
  {
    MotorL.run(moveSpeed);
    MotorR.run(moveSpeed);
  }
  void backward()
  {
    MotorL.run(moveSpeed);
    MotorR.run(-moveSpeed);
  }
  void turnLeft()
  {
    MotorL.run(-moveSpeed / 10);
    MotorR.run(moveSpeed);
  }
  void turnRight()
  {
    MotorL.run(-moveSpeed);
    MotorR.run(moveSpeed / 10);
  }
  void stop()
  {
    MotorL.run(0);
    MotorR.run(0);
  }
};
