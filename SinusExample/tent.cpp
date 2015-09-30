#include "tent.h"
#include <stdlib.h>

TriangularFunction::TriangularFunction(void)
{

}

/**
 * Periodically calls the triangular function to get the values.
 * @brief TriangularFunction::getValue
 * @return
 */
float TriangularFunction::getValue(void)
{
    float value = Source::getSinusValue();
    return (abs(2*value) < 1)? (1-abs(2*value))*amplitude : 0;
}
