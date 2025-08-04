#include "display.h"
#include <iostream>

bool isTemperatureOk(float temperature) {
  if (temperature < 95 || temperature > 102) {
    showBlinkingAlert("Temperature is critical!");
    return false;
  }
  return true;
}

bool isPulseRateOk(float pulseRate) {
  if (pulseRate < 60 || pulseRate > 100) {
    showBlinkingAlert("Pulse Rate is out of range!");
    return false;
  }
  return true;
}

bool isSpO2Ok(float spo2) {
  if (spo2 < 90) {
    showBlinkingAlert("Oxygen Saturation out of range!");
    return false;
  }
  return true;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  return isTemperatureOk(temperature) &&
         isPulseRateOk(pulseRate) &&
         isSpO2Ok(spo2);
}
