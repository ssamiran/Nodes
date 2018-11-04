/*!
   \file "Valve.h"
   \brief "Execute irrigationcycle and store sensor data"
   \author "Spandan"
   \date "02"/"Nov"/"2018"
*/


#ifndef Valve_h
#define Valve_h

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif



class Valve{
public:
  bool isOpen;
  bool isIrrigated;


  void open();
  void close();
  void reset();

};

#endif
