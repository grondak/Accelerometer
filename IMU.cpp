#include "Accelerometer.h"
#include "IMU.h"
// printf("*** Raw format '$accelx,accely,accelz,gyrox,gyroy,gyroz,magx,magy,magz#\n\r");
IMU::IMU()
{
  XAccel = 0;
  YAccel = 0;
  ZAccel = 0;
  XGyro = 0;
  YGyro = 0;
  ZGyro = 0;
  XMag = 0;
  YMag = 0;
  ZMag = 0;
}

void IMU::initialize()
{
  Serial2.begin(default_IMU_baud);

}

void IMU::readCurrent()
{
  
  if((serialByteCount = Serial2.available())>0)
  {
    Serial2.readBytesUntil('\n', serialBuffer, serialByteCount);
    // From Razor IMU debug code: printf("*** Raw format '$accelx,accely,accelz,gyrox,gyroy,gyroz,magx,magy,magz#\n\r");
    // sample from Accelerometer Terminal Program: $9,-7,250,8,-20,0,74,-143,-160#
    sscanf(serialBuffer,"$%d,%d,%d,%d,%d,%d,%d,%d,%d#",    
      &XAccel, &YAccel, &ZAccel, &XGyro, &YGyro, &ZGyro, &XMag, &YMag, &ZMag);

  }
}

int IMU::getValsRead()
{
  return valsRead;
}

 int IMU::getXAccel()
 {
   return XAccel;
 }
 
  int IMU::getYAccel()
  {
    return YAccel;
  }
  
  int IMU::getZAccel()
  {
    return ZAccel;
  }
  
  int IMU::getXGyro()
  {
    return XGyro;
  }
  
  int IMU::getYGyro()
  {
    return YGyro;
  }
  
  int IMU::getZGyro()
  {
    return ZGyro;
  }
  
  int IMU::getXMag()
  {
    return XMag;
  }
  
  int IMU::getYMag()
  {
    return YMag;
  }
  
  int IMU::getZMag()
  {
    return ZMag;
  }
  



