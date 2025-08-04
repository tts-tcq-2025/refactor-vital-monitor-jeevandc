#include "./monitor.h"
#include "display.h"
#include <assert.h>
#include <iostream>
using std::cout;
using std::cout;

int vitalsOk(float temperature, float pulseRate, float spo2) {
  if (temperature > 102 || temperature < 95) {
    showBlinkingAlert("Temperature is critical!");
    return 0;
  }
  if (pulseRate < 60 || pulseRate > 100) {
    showBlinkingAlert("Pulse Rate is out of range!");
    return 0;
  }
  if (spo2 < 90) {
    showBlinkingAlert("Oxygen Saturation out of range!");
    return 0;
  }
  return 1;
}
