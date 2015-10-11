#include "sawtooth.h"
#include <math.h>

SawToothFunction::SawToothFunction(void)
{

}

/**
 * Call the sawtooth function periodically
 * @brief SawToothFunction::getValue
 * @return
 */
float SawToothFunction::getValue(void)
{
    float value = Source::getSinusValue();

    return (value-floor(value))*amplitude;
}
