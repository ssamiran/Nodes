/*!
   \file "IrrigationSchedule.h"
   \brief "Execute irrigationcycle and store sensor data"
   \author "Spandan"
   \date "02"/"Nov"/"2018"
*/


#ifndef IrrigationSchedule_h
#define IrrigationSchedule_h

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif
#include <irrigationschedule.h>


class IrrigationSchedule{
public:
  bool activeSchedule;


  void getSchedule();
  void setSchedule();
  void updateSchedule();
  void startSchedule();
  void stopSchedule();
  // void reset();
};

#endif
