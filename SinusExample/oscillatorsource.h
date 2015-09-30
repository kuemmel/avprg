#ifndef OSCILLATORSOURCE_H
#define OSCILLATORSOURCE_H

#include "audiosource.h"
#include "source.h"

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
private:
    QAudioFormat audioFormat;
    Source* currentSource;
};

#endif // OSCILLATORSOURCE_H
