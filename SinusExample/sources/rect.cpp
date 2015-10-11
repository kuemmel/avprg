#include "rect.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>

RectangleFunction::RectangleFunction(void)
{

}

/**
 * periodically call the function
 * @brief RectangleFunction::getValue
 * @return
 */
float RectangleFunction::getValue(void)
{
    float value = Source::getSinusValue();
    return (value > 0) ? amplitude : -1*amplitude;
}
