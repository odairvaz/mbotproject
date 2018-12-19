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