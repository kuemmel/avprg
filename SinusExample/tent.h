#ifndef TENT_H
#define TENT_H

#include "source.h"
/**
 * triangular function class, getValue() periodically returns the triangular function values between -1,1
 * @brief The TriangularFunction class
 */
class TriangularFunction : public Source
{
public:
    TriangularFunction();
    float getValue(void);

    void setVolume(float amplitude);
    void setFrequency(float freq);
    void setSampleRate(float sample);
    //work around
    float getVolume(void);
    float getFrequency(void);
    float getSampleRate(void);
};

#endif // TENT_H

