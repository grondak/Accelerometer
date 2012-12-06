#ifndef ReferenceMaintainer_h
#define ReferenceMaintainer_h
#include "Accelerometer.h"
#include "SerialLCD.h"
#include "IMU.h"


class ReferenceMaintainer
{

public:
  ReferenceMaintainer();
  void initialize();

  IMU myIMU;
  SerialLCD myLCD;

};

#endif

