#include "envelope.h"

Envelope::Envelope() : state(OFF),gain(0), releaseSeconds(0.2), decaySeconds(0.2),sustain(0.8),attackSeconds(0.5),sampleRate(44100)
{

}

void Envelope::setReleaseSeconds(float seconds)
{
    this->releaseSeconds = seconds;
}

void Envelope::setState(State state)
{
    this->state = state;
    if(state == OFF)
    {
        gain = 0;
    } else if(state == ON)
    {
        gain = sustain;
    }
}

float Envelope::process(float input)
{
    if(state == RELEASE)
    {
        gain -= 1/(sampleRate * releaseSeconds);
        if(gain <=0)
        {
            setState(OFF);
        }
    } else if (state == ATTACK)
    {
        gain += 1/(sampleRate * attackSeconds);
        if(gain >=1)
        {
            setState(DECAY);
        }
    } else if (state == DECAY)
    {
        gain -=  (1-sustain)/(sampleRate * decaySeconds);
        if (gain <= sustain)
        {
            setState(ON);
        }
    }

    return input*gain;
}

void Envelope::setGain(float gain)
{
    this->gain = gain;
}
void Envelope::setRelease(float seconds)
{
    this->releaseSeconds = seconds;
}
void Envelope::setDecay(float seconds)
{
    this->decaySeconds = seconds;
}
void Envelope::setSustain(float sustain)
{
    this->sustain = sustain;
}
void Envelope::setAttack(float attackSeconds)
{
    this->attackSeconds = attackSeconds;
}
void Envelope::setSample(float sample)
{
    this->sampleRate = sample;
}
