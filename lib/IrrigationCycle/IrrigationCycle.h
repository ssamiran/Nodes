/*!
   \file "IrrigationCycle.h"
   \brief "Execute irrigationcycle and store sensor data"
   \author "Spandan"
   \date "02"/"Nov"/"2018"
*/


#ifndef IrrigationCycle_h
#define IrrigationCycle_h

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif
#include <valvereport.h>


class IrrigationCycle{
public:
  void startIrrigation(struct valvereport, int startTime, float waterAmount);

protected:
  void stopIrrigation(float waterAmount);
  void readSensor(struct valve);
  bool isDone();
  bool reset();
};

#endif
