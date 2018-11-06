/*!
   \file "IrrigationCycle.h"
   \brief "Execute irrigationcycle and store sensor data"
   \author "Spandan"
   \date "06"/"Nov"/"2018"
*/


#ifndef flowratesensor_h
#define flowratesensor_h

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

class FlowRateSensor{
public:
    float read();
    float convertToPascal();
};



#endif
