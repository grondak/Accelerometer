#ifndef IMU_h
#define IMU_h


class IMU
{
  public:
  IMU();
  void initialize();
  void readCurrent();
  int getXAccel();
  int getYAccel();
  int getZAccel();
  int getXGyro();
  int getYGyro();
  int getZGyro();
  int getXMag();
  int getYMag();
  int getZMag();
  int getValsRead();
  
  private:
  static const int default_IMU_baud = 57600;
  int XAccel, YAccel, ZAccel;
  int XGyro, YGyro, ZGyro;
  int XMag, YMag, ZMag;
  int serialByteCount;
  char serialBuffer[];
  int valsRead;
};


#endif

