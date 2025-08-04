#include "./monitor.h"
#include <iostream>
#include "./display.h"

bool isTemperatureOk(float temperature) {
  if (temperature < 95 || temperature > 102) {
    PrintConsoleAlert("Temperature is critical!");
    return false;
  }
  return true;
}

bool isPulseRateOk(float pulseRate) {
  if (pulseRate < 60 || pulseRate > 100) {
    PrintConsoleAlert("Pulse Rate is out of range!");
    return false;
  }
  return true;
}

bool isSpO2Ok(float spo2) {
  if (spo2 < 90) {
    PrintConsoleAlert("Oxygen Saturation out of range!");
    return false;
  }
  return true;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  return isTemperatureOk(temperature) &&
         isPulseRateOk(pulseRate) &&
         isSpO2Ok(spo2);
}
