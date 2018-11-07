/*!
   \file "rtc.h"
   \brief "Execute irrigationcycle and store sensor data"
   \author "Spandan"
   \date "06"/"Nov"/"2018"
*/


#ifndef rtc_h
#define rtc_h

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

class rtc{
public:
  char getTime();
  void setTime();
  char getElapsedTime();
};

#endif
