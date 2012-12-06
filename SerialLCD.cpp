
#include "SerialLCD.h"

// SerialLCD knows how to print things that are relevant to Reinforcements
// It has one line for general messages

SerialLCD:: SerialLCD()
{

}

void SerialLCD::initialize()
{
  Serial1.begin(9600);
  Serial1.write(ESC); 
  Serial1.write(0x41); 
  Serial1.write(ESC); 
  Serial1.write(0x51); // Set Contrast 
  Serial1.write(ESC); 
  Serial1.write(0x52); 
  Serial1.write(40); // Set Backlight
  Serial1.write(ESC); 
  Serial1.write(0x53); 
  Serial1.write(8);
  delay(LCDDelay); // slow down processing because the LCD is slower than the Arduino
  for( int x; x< numLines; x++) // zero out our string holder
  {
    memset(lineData[x],0, 1);
  }
  Serial1.print("Accelerometer");
}

void SerialLCD::clear()
{
  Serial1.write(0xFE); //command flag
  Serial1.write(0x51); //clear command.
  delay(LCDDelay); // slow down processing because the LCD is slower than the Arduino
}

void SerialLCD::updateDisplay(IMU inIMU)
{
  clear();
  formatAccels(inIMU);
  formatGyros(inIMU);
  formatCompass(inIMU);
  printline(line_accel);
  printline(line_gyro);
  printline(line_compass);
  strcpy(lineData[line_mode], "Raw Data");
  printline(line_mode);
}

void SerialLCD::formatAccels(IMU inIMU)
{
  sprintf(lineData[line_accel], "X:%d|Y:%d|Z:%d", inIMU.getXAccel(), inIMU.getYAccel(), inIMU.getZAccel());
}

void SerialLCD::formatGyros(IMU inIMU)
{
  sprintf(lineData[line_gyro], "X:%d|Y:%d|Z:%d", inIMU.getXGyro(), inIMU.getYGyro(), inIMU.getZGyro());  
}

void SerialLCD::formatCompass(IMU inIMU)
{
  sprintf(lineData[line_compass], "X:%d|Y:%d|Z:%d", inIMU.getXMag(), inIMU.getYMag(), inIMU.getZMag());
}



void SerialLCD::printline(line_number_t lineNumber)
{
  Serial1.write(ESC);  // set up the ESC Char
  Serial1.write(0x45); // send the address-cursor line cmd
  char switchToLineChar = 0;
  // based on the line number, we select a cursor position code
  switch(lineNumber) // use from the Longtech LCD manual p.8
  { // line_accel = 0, line_gyro = 1, line_compass = 2, line_mode = 3
  case line_accel:
    switchToLineChar = 0;
    break;
  case line_gyro:
    switchToLineChar = 0x40;
    break;
  case line_compass:
    switchToLineChar = 0x14;
    break;
  case line_mode:
    switchToLineChar = 0x54;
    break;
  default:
    switchToLineChar = 0;
  }
  Serial1.write(switchToLineChar); // send the code
  Serial1.print(lineData[lineNumber]); // now print the data
  delay(LCDDelay); // slow down processing because the LCD is slower than the Arduino
}



