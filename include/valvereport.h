/*!
   \file "valvereport.h"
   \brief "Execute irrigationcycle and store sensor data"
   \author "Spandan"
   \date "02"/"Nov"/"2018"
*/


#ifndef valvereport_h
#define valvereport_h

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

struct{
  int flowrate;
  float amoountUsed;
  double elapsedTime;
  int waterPressure;

}valvereport;


#endif
