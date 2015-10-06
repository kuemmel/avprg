#ifndef OSCILLATORSOURCE_H
#define OSCILLATORSOURCE_H

#include "audiosource.h"
#include "source.h"
#include "envelope.h"

class OscillatorSource: public AudioSource
{
public:
    OscillatorSource();
    virtual const QAudioFormat& format() const;
    virtual qint64 read(float** buffer, qint64 numFrames);
    virtual void setSource(Source& source);
    virtual void start();
    virtual void stop();
    virtual void setVolume(float amplitude);
    virtual void setFrequency(float freq);
    virtual void setSampleRate(float sampleRate);
    virtual float getSample();
    virtual void noteOn();
    virtual void noteOff();

    virtual void setGain(float gain);
    virtual void setRelease(float seconds);
    virtual void setDecay(float seconds);
    virtual void setSustain(float sustain);
    virtual void setAttack(float attackSeconds);
    virtual void setSample(float sample);


private:
    QAudioFormat audioFormat;
    Envelope envelope;
    Source* currentSource;
};

#endif // OSCILLATORSOURCE_H
