#ifndef Accelerometer_h
#define Accelerometer_h
#include "Arduino.h"

void calcInput();
#ifdef __AVR_ATmega2560__ // running on the Mega, the target platform

#define CPU_TEST

#endif

#ifdef __AVR_ATmega328P__  // running on the Uno, the prototyping platform

#endif

#if not defined(CPU_TEST)
#error Hey you got the wrong CPU setup maaaaang
#endif



#endif
