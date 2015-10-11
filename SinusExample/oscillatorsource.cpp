#include "oscillatorsource.h"
#include <iostream>
#include <math.h>
#include "sources/sinus.h"

OscillatorSource::OscillatorSource()
{
    Sinus* sinus = new Sinus;
    currentSource = sinus;
    audioFormat.setCodec("audio/pcm");
    audioFormat.setByteOrder(QAudioFormat::LittleEndian);
    audioFormat.setChannelCount(2);
    audioFormat.setSampleSize(32);
    audioFormat.setSampleType(QAudioFormat::Float);
    audioFormat.setSampleRate(44100);

}

void OscillatorSource::setSource(Source& source) {
    std::cout << "Changing source\n ... ... \n" ;
    currentSource = &source;
    std::cout << "Done!\n";
}

void OscillatorSource::start(){

}
const QAudioFormat& OscillatorSource::format() const{
    return audioFormat;
}

void OscillatorSource::setVolume(float decibel){
    float gain = pow(10,decibel/20.f);
    currentSource->setVolume(gain);
}

void OscillatorSource::setSampleRate(float sample){
    currentSource->setSampleRate(sample);
}

void OscillatorSource::setFrequency(float freq){
    currentSource->setFrequency(freq);
}

void OscillatorSource::noteOn()
{
    envelope.setState(Envelope::ATTACK);
}
void OscillatorSource::noteOff()
{
    envelope.setState(Envelope::RELEASE);
}

float OscillatorSource::getSample()
{
    return envelope.process((float)currentSource->getValue());
}

qint64 OscillatorSource::read(float** buffer, qint64 numFrames){

    // get audio data for left channel
    for(int i = 0; i < numFrames; i++){
        buffer[0][i] = (float) getSample();
    }
    // copy to other channels
    for(int c = 0; c < audioFormat.channelCount(); c++){
        for(int i = 0; i < numFrames; i++){
            buffer[c][i] = buffer[0][i];
        }
    }
    return numFrames;
}
void OscillatorSource::stop(){}

 void OscillatorSource::setGain(float gain)
 {
    envelope.setGain(gain);
 }
 void OscillatorSource::setRelease(float seconds)
 {
    envelope.setRelease(seconds);
 }
 void OscillatorSource::setDecay(float seconds)
 {
    envelope.setDecay(seconds);
 }
 void OscillatorSource::setSustain(float sustain)
 {
    envelope.setSustain(sustain);
 }
 void OscillatorSource::setAttack(float attackSeconds)
 {
    envelope.setAttack(attackSeconds);
 }
 void OscillatorSource::setSample(float sample)
 {
    envelope.setSample(sample);
 }
