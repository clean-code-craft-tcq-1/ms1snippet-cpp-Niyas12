#include "sensor-validate.h"

#define MAX_SOC_DELTA (0.05f)
#define MAX_CURRENT_DELTA (0.1f)

bool isMeasurementJumpedAbruptly(double* values, int numOfValues, int maxDelta) 
{
    int lastButOneIndex = numOfValues - 1;
    for (int i = 0; i < lastButOneIndex; i++) {
        if((values[i + 1] - values[i]) > maxDelta)
        {
            return false;
        }
    }
    return true;
}
bool ValidateInputValues(double* values)
{
    if (values == nullptr)
        return false;
    return true;
}
bool validateSOCreadings(double* values, int numOfValues) 
{
    if (!ValidateInputValues(values))
        return false;

    return isMeasurementJumpedAbruptly(values, numOfValues, MAX_SOC_DELTA);
}

bool validateCurrentreadings(double* values, int numOfValues) 
{
    if (!ValidateInputValues(values))
        return false;

    return isMeasurementJumpedAbruptly(values, numOfValues, MAX_CURRENT_DELTA);
}
