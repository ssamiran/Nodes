/*!
   \file "IrrigationCycle.cpp"
   \brief "Start and stop Irrigation Cycle"
   \author "Spandan"
   \date "DD"/"Month"/"Year"
*/

#include "IrrigationCycle.h"
#include "valvereport.h"
#include "Valve.h"
#include "pressuresensor.h"
#include "flowratesensor.h"

Valve valve;
#define FLOWRATE_SENSOR 9
#define PRESSURE_SENSOR 10

bool IrrigationCycle::startIrrigation(struct valvereport ValveReport , int startTime, float expectedWaterUse){

      bool return_value = false;

      if (!valve.isOpen){
          valve.open();
          valve.isOpen = true;
          isIrrigating = true;
          do {
                ValveReport.startTime = startTime;
                readSensor(&ValveReport);
          } while((ValveReport.amountUsed <= expectedWaterUse) && (valve.isOpen));
          valve.close();
          valve.isOpen = false;
          isIrrigating = false;
          // update irrigationschedule array
          // task_code -> irrigated:true

          return_value = true;
          return return_value;
      }
      else{
          return return_value;
      }

}

void IrrigationCycle::stopIrrigation(float waterAmount){
      if (isIrrigating){
        valve.isOpen = false;
        valve.close();
        isIrrigating = false;
      }
}

void IrrigationCycle::readSensor(struct valvereport *Valve){

}

bool IrrigationCycle::isDone(){
  return true;
}

bool IrrigationCycle::reset(){
  return true;
}

void IrrigationCycle::tick(){

}
