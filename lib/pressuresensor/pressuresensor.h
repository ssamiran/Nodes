/*!
   \file "IrrigationCycle.h"
   \brief "Execute irrigationcycle and store sensor data"
   \author "Spandan"
   \date "06"/"Nov"/"2018"
*/


#ifndef pressuresensor_h
#define pressuresensor_h

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

class PressureSensor{
public:
    float read();
    float convertToAmountUsed();
};



#endif
