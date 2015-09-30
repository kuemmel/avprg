#ifndef SAWTOOTH_H
#define SAWTOOTH_H

#include "source.h"

class SawToothFunction : public Source
{
public:
    SawToothFunction();
    float getValue();
};

#endif // SAWTOOTH_H

