#include <math.h>
#include <cstdlib>

#include "sources/noise.h"

Noise::Noise(void) : max(1.0),min(-1.0),precision(1000)
{

}

Noise::~Noise(void)
{

}

/**
 * returns a simple noise sound
 * @brief Noise::getValue
 * @return
 */
float Noise::getValue(void)
{
    float value = (min+1) + (((float) rand()) / (float)RAND_MAX) * (max - (min+1));
    return value;
}

void Noise::setVolume(float volume)
{
    this->setMax(volume);
    this->setMin(-1*volume);
}

void Noise::setMin(float min_value)
{
    min = min_value;
}

void Noise::setMax(float max_value)
{
    max = max_value;
}
