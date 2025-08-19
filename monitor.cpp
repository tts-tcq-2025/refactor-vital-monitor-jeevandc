#include "./monitor.h"
#include <iostream>
#include "./display.h"

// Utility to calculate tolerance-based warning
float calcTolerance(float upperLimit, float percentage) {
    return (upperLimit * percentage) / 100.0f;
}

bool isTemperatureOk(float temperature) {
    float lower = 95.0f;
    float upper = 102.0f;
    float tolerance = calcTolerance(upper, 1.5f);

    if (temperature < lower || temperature > upper) {
        PrintConsoleAlert("Temperature is critical!");
        return false;
    }
    if (temperature >= lower && temperature <= lower + tolerance) {
        PrintConsoleAlert("Warning: Approaching hypothermia");
    }
    if (temperature >= upper - tolerance && temperature <= upper) {
        PrintConsoleAlert("Warning: Approaching hyperthermia");
    }
    return true;
}

bool isPulseRateOk(float pulseRate) {
    float lower = 60.0f;
    float upper = 100.0f;
    float tolerance = calcTolerance(upper, 1.5f);

    if (pulseRate < lower || pulseRate > upper) {
        PrintConsoleAlert("Pulse Rate is out of range!");
        return false;
    }
    if (pulseRate >= lower && pulseRate <= lower + tolerance) {
        PrintConsoleAlert("Warning: Approaching bradycardia (low pulse)");
    }
    if (pulseRate >= upper - tolerance && pulseRate <= upper) {
        PrintConsoleAlert("Warning: Approaching tachycardia (high pulse)");
    }
    return true;
}

bool isSpO2Ok(float spo2) {
    float lower = 90.0f;
    float upper = 100.0f;  // normal max
    float tolerance = calcTolerance(upper, 1.5f);

    if (spo2 < lower) {
        PrintConsoleAlert("Oxygen Saturation out of range!");
        return false;
    }
    if (spo2 >= lower && spo2 <= lower + tolerance) {
        PrintConsoleAlert("Warning: Approaching hypoxemia");
    }
    if (spo2 >= upper - tolerance && spo2 <= upper) {
        PrintConsoleAlert("Warning: Approaching upper saturation limit");
    }
    return true;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    return isTemperatureOk(temperature) &&
           isPulseRateOk(pulseRate) &&
           isSpO2Ok(spo2);
}
