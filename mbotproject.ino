#include "car.h"
MeLineFollower lineFollower(PORT_2);
MeUltrasonicSensor ultraSensor(PORT_3);
Car bentley_gt;

void setup() {}

void loop()
{
  bentley_gt.dist = ultraSensor.distanceCm();
  if (bentley_gt.dist < 9 && bentley_gt.dist > 1)
  {
    obstacleAvoidance();
  }
  else
  {
    lineFollow();
  }
}
void lineFollow()
{
  int sensorStateCenter = lineFollower.readSensors();
  if (bentley_gt.moveSpeed > 230)
  {
    bentley_gt.moveSpeed = 230;
  }
  switch (sensorStateCenter)
  {
  case S1_IN_S2_IN:
    bentley_gt.forward();
    bentley_gt.lineDirIndex = 10;
    break;
  case S1_IN_S2_OUT:
    bentley_gt.forward();
    if (bentley_gt.lineDirIndex > 1)
    {
      bentley_gt.lineDirIndex--;
    }
    break;
  case S1_OUT_S2_IN:
    bentley_gt.forward();
    if (bentley_gt.lineDirIndex < 20)
    {
      bentley_gt.lineDirIndex++;
    }
    break;
  case S1_OUT_S2_OUT:
    if (bentley_gt.lineDirIndex == 10)
    {
      bentley_gt.backward();
    }
    if (bentley_gt.lineDirIndex == 10.5)
    {
      MotorL.run(-bentley_gt.moveSpeed);
      MotorR.run(bentley_gt.moveSpeed / 1.8);
    }
    if (bentley_gt.lineDirIndex < 10)
    {
      bentley_gt.turnLeft();
    }
    if (bentley_gt.lineDirIndex > 10.5)
    {
      bentley_gt.turnRight();
    }
    break;
  }
}

void obstacleAvoidance()
{
  MotorL.run(bentley_gt.moveSpeed); // Turn left
  MotorR.run(bentley_gt.moveSpeed);
  delay(450);
  bentley_gt.lineDirIndex = 10.5;
}
