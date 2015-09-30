#include <math.h>
#include "source.h"
const float pi = 3.1415926f;

float Source::getSinusValue()
{
    float value = sin(2*pi * (frequency/sampleRate)*index);
    index++;
    return value;
}

void Source::setFrequency(float freq)
{
    frequency = freq;
}

void Source::setSampleRate(float sample)
{
    sampleRate = sample;
}

void Source::setVolume(float volume)
{
    amplitude = volume;
}

/**
 * get the volume, a value between [0,1] for now
 * @brief Source::getVolume
 * @return
 */
float Source::getVolume(void)
{
    return amplitude;
}
/**
 * get the sample rate, usually 44100Hz for now
 * @brief Source::getSampleRate
 * @return
 */
float Source::getSampleRate(void)
{
    return sampleRate;
}
/**
 * get the frequency of the sinus function, should be between 20 and 20kHz.
 * @brief Source::getFrequency
 * @return
 */
float Source::getFrequency(void)
{
    return frequency;
}
