#ifndef OSCILLATOR_H
#define OSCILLATOR_H

/**
 * This class is used as a strategy interface to define sound creating algorithms
 * This is a member of the oscillator class, a combobox in the mainwindow holds the different argument options (@see mainwindow.h)
 * A switch in mainwindow.cpp builds a new object for a child of this class.
 *  - @TODO add a simpler desin as an alternative to the switch
 * @brief The Source interface/abstract class used for defining simple mathematical defined sound sources
 */
class Source
{
public:
    Source() : index(0),amplitude(0.5),frequency(200),sampleRate(44100)
    {

    }
    virtual ~Source(){}
    /**
     * Mathematical algorithm to create sound
     * @brief getValue
     * @return the current value of the mathematical function, a value usualy between [-1,1]
     */
    virtual float getValue() = 0;

    /**
     * Return values for a sinus function as a base for sound generation
     * @brief getSinusValue
     * @return
     */
    float getSinusValue();
    /**
     * Set the volume(amplitude) of the signal.
     * @brief setVolume of the signal
     * @param amplitude the amplitude, without distortion between [0,1]
     */
    void setVolume(float amplitude);
    void setFrequency(float freq);
    void setSampleRate(float sample);
    //work around
    float getVolume(void);
    float getFrequency(void);
    float getSampleRate(void);
protected:
    int index;
    float amplitude;
    float frequency;
    float sampleRate;
};
#endif
