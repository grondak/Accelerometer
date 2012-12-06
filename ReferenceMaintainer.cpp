#include "ReferenceMaintainer.h"

  ReferenceMaintainer::ReferenceMaintainer()
  {

  }

  void ReferenceMaintainer::initialize()
  {
    myLCD.initialize();
    myIMU.initialize();
  }


