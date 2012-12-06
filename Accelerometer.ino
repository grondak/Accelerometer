#include "Accelerometer.h"
#include "ReferenceMaintainer.h"
#include "SerialLCD.h"

ReferenceMaintainer rm;
int printBufferLength;
char printBuffer[200];
int loopCount = 0;

void setup()
{
  rm.initialize();
  Serial.begin(57600);
  Serial2.begin(57600);
}


void loop()
{
  rm.myIMU.readCurrent();
  if(loopCount++ > 10)
  {
    rm.myLCD.updateDisplay(rm.myIMU);
    loopCount = 0;
  }
  delay(30);
}
