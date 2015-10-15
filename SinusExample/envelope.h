#ifndef ENVELOPE_H
#define ENVELOPE_H
class Envelope
{
public:
    Envelope();
    enum State {OFF,RELEASE,ON,ATTACK,DECAY,SUSTAIN};
    float process(float input);
    void setReleaseSeconds(float seconds);
    void setState(State state);

    void setGain(float gain);
    void setRelease(float seconds);
    void setDecay(float seconds);
    void setSustain(float sustain);
    void setAttack(float attackSeconds);
    void setSample(float sample);

    int getState(void);


private:
    State state;
    float gain;
    float releaseSeconds;
    float decaySeconds;
    float sustain;
    float attackSeconds;
    float sampleRate;
};

#endif // ENVELOPE_H

