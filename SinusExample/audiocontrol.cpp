#include <QDebug>
#include "audiocontrol.h"

#include "note.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "sources/noise.h"
#include "sources/sinus.h"
#include "sources/rect.h"
#include "sources/tent.h"
#include "sources/sawtooth.h"

AudioControl::AudioControl(Ui::MainWindow* ui) : audioPlayer(this)
{
    initializeAudio();
    initializeMidi(ui);

    QObject::connect(ui->VolumeControl, SIGNAL(on_VolumeControl_valueChanged(int)), this, SLOT(on_VolumeControl_valueChanged(int)));
    QObject::connect(ui->FreeAmplitude, SIGNAL(on_FreeAmplitude_sliderMoved(int)), this, SLOT(on_FreeAmplitude_sliderMoved(int)));
    QObject::connect(ui->NoteSelector, SIGNAL(on_NoteSelector_sliderMoved(int)), this, SLOT(on_NoteSelector_sliderMoved(int)));
    QObject::connect(ui->AttackSlider, SIGNAL(on_AttackSlider_valueChanged(int)), this, SLOT(on_AttackSlider_valueChanged(int)));
    QObject::connect(ui->DecaySlider, SIGNAL(on_DecaySlider_valueChanged(int)), this, SLOT(on_DecaySlider_valueChanged(int)));
    QObject::connect(ui->SustainSlider, SIGNAL(on_SustainSlider_valueChanged(int)), this, SLOT(on_SustainSlider_valueChanged(int)));
    QObject::connect(ui->ReleaseSlider, SIGNAL(on_ReleaseSlider_valueChanged(int)), this, SLOT(on_ReleaseSlider_valueChanged(int)));

    QObject::connect(ui->MidiChooser, SIGNAL(activated(const QString)),this,SLOT(on_MidiChooser_activated(QString)));
    QObject::connect(&midiInput, SIGNAL(midiNoteOn(const int, const int, const int)), this, SLOT(onMidiNoteOn(const int, const int, const int)));
    QObject::connect(&midiInput, SIGNAL(midiNoteOff(const int, const int, const int)), this, SLOT(onMidiNoteOff(const int, const int, const int)));
}


void AudioControl::initializeMidi(Ui::MainWindow* ui)
{
    QStringList connections = midiInput.connections(true);
    ui->MidiChooser->addItems(connections);
    if (connections.size() > 0)
    {
        on_MidiChooser_activated(ui->MidiChooser->currentText());
    }

   }

void AudioControl::initializeAudio(){
    audioPlayer.setAudioSource(&oscillatorSource);
    audioPlayer.start();
}

void AudioControl::on_MidiChooser_activated(const QString &string)
{
    midiInput.open(string);
}

void AudioControl::onMidiNoteOff(const int chan, const int note, const int vel)
{
    oscillatorSource.noteOff();
}

void AudioControl::onMidiNoteOn(const int chan, const int note, const int vel)
{
    if (vel == 0){
        onMidiNoteOff(chan, note, vel);
    }
    oscillatorSource.setFrequency(Note::getNoteFrequency(note));
    oscillatorSource.noteOn();
}

void AudioControl::on_SetSource_currentIndexChanged(int index)
{
    switch(index)
    {
        case SINUS:
        {
            Sinus* sinus = new Sinus;
            oscillatorSource.setSource(*sinus);
            break;
        }
        case NOISE:
        {
            Noise* noise = new Noise;
            oscillatorSource.setSource(*noise);
            break;
        }
        case RECT:
        {
            RectangleFunction* rect = new RectangleFunction;
            oscillatorSource.setSource(*rect);
            break;
        }
        case TENT:
        {
            TriangularFunction* tent = new TriangularFunction;
            oscillatorSource.setSource(*tent);
            break;
        }
        case SAWT:
        {
            SawToothFunction* sawt = new SawToothFunction;
            oscillatorSource.setSource(*sawt);
            break;
        }
    }
}

//im Bereich 0-99
void AudioControl::on_VolumeControl_valueChanged(int value)
{
    oscillatorSource.setVolume(value);
}
void AudioControl::on_FreeAmplitude_sliderMoved(int position)
{
    oscillatorSource.setFrequency(position);
}

void AudioControl::on_checkBox_toggled(bool checked)
{
    if(checked) oscillatorSource.noteOn();
    else oscillatorSource.noteOff();
}

void AudioControl::on_pushButton_pressed()
{
    //audioPlayer.start();
    oscillatorSource.noteOn();
}

void AudioControl::on_pushButton_released()
{
    //audioPlayer.stop();
    oscillatorSource.noteOff();
}

void AudioControl::on_NoteSelector_sliderMoved(int position)
{
    oscillatorSource.setFrequency(Note::getNoteFrequency(position));
}

void AudioControl::on_AttackSlider_valueChanged(int value)
{
    oscillatorSource.setAttack(value*0.01);
}

void AudioControl::on_DecaySlider_valueChanged(int value)
{
    oscillatorSource.setDecay(value*0.01);
}

void AudioControl::on_SustainSlider_valueChanged(int value)
{
    oscillatorSource.setSustain(value);
}

void AudioControl::on_ReleaseSlider_valueChanged(int value)
{
    oscillatorSource.setRelease(value*0.01);
}


