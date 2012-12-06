#ifndef SerialLCD_h
#define SerialLCD_h
#include "Accelerometer.h"
#include "IMU.h"

// makes use of the Mega's Serial1 port
class SerialLCD
{
  public:
    SerialLCD();
    void initialize();
    void clear();
    void updateDisplay(IMU inIMU);
    

  private:
     enum line_number_t {line_accel = 0, line_gyro = 1, line_compass = 2, line_mode = 3};
     void formatAccels(IMU inIMU);
     void formatGyros(IMU inIMU);
     void formatCompass(IMU inIMU);
     void printline(line_number_t lineNumber);
     static const char ESC = 0xFE; 
     static const int numLines = 4; // how many lines in the serial display
     static const int numCols = 20 ; // how many columns in the serial display
     static const int LCDDelay = 20; // thanks Amazon.com guy
     char lineData[numLines][numCols]; // 4 lines of 20 characters each
 
};

#endif

