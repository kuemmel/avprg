#ifndef NOISE_H
#define NOISE_H

#include "source.h"

class Noise : public Source
{
public:
    Noise();
    ~Noise();
    void setMin(float min_value);
    void setMax(float max_value);
    void setVolume(float volume);
    float getValue();
private:
    float max; // the positive maximum, default is 1, which should be max, unless distortion is wanted
    float min; // negative maximum, default is -1
    float precision; // the precision or count of decimal places
};

#endif
