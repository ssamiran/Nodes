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
#include "rtc.h"

Valve valve;
flowratesensor FlowRate
pressuresensor PressureSensor
#define FLOWRATE_SENSOR 9
#define PRESSURE_SENSOR 10

bool IrrigationCycle::startIrrigation(struct valvereport ValveReport , int startTime, float expectedWaterUse, int taskCode){

      bool return_value = false;

      if (!valve.isOpen){
          valve.open();
          valve.isOpen = true;
          isIrrigating = true;
          ValveReport.taskCode = taskCode;
          ValveReport.startTime = startTime;
          ValveReport.irrigated = false;
          do {
                ValveReport.startTime = startTime;
                readSensor(&ValveReport);
          } while((ValveReport.amountUsed <= expectedWaterUse) && (valve.isOpen));
          valve.close();
          valve.isOpen = false;
          isIrrigating = false;
          ValveReport.irrigated = true;
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
      Valve.flowrate = FlowRate.read();
      Valve.amountUsed = FlowRate.convertToAmountUsed();
      Valve.waterPressure = PressureSensor.read();
}

bool IrrigationCycle::isDone(int taskCode){
  return true;
}

bool IrrigationCycle::reset(){
  return true;
}
