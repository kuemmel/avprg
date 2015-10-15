#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QAudioInput>
#include <QAudioDecoder>
#include <QAudioFormat>
#include <iostream>

#include "midicontrol.h"
#include "note.h"

#include "sources/noise.h"
#include "sources/sinus.h"
#include "sources/rect.h"
#include "sources/tent.h"
#include "sources/sawtooth.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , audioPlayer(this)

{
    initializeAudio();
    ui->setupUi(this);
    MidiControl* mControl = new MidiControl(*(ui->MidiChooser),*(ui->DebugMessageLabel));
    midiControl = mControl;

    QObject::connect(&midiControl->midiInput, SIGNAL(midiNoteOn(const int, const int, const int)), this, SLOT(onMidiNoteOn(const int, const int, const int)));
    QObject::connect(&midiControl->midiInput, SIGNAL(midiNoteOff(const int, const int, const int)), this, SLOT(onMidiNoteOff(const int, const int, const int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initializeAudio(){
    audioPlayer.setAudioSource(&oscillatorSource);
    audioPlayer.start();
}

//im Bereich 0-99
void MainWindow::on_VolumeControl_valueChanged(int value)
{
    ui->VolumeLCD->display(value);
    oscillatorSource.setVolume(value);
}

/**
 * Choose between different signals based on the index.
 * Better would have been to add this to oscillatorsource and open the class with the fitting index
 * instead of building a switch?
 *
 * @brief MainWindow::on_SetSource_currentIndexChanged
 * @param index
 */
void MainWindow::on_SetSource_currentIndexChanged(int index)
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

void MainWindow::on_FreeAmplitude_sliderMoved(int position)
{
    oscillatorSource.setFrequency(position);
    ui->CurrentFrequency->display(position);
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    if(checked) oscillatorSource.noteOn();//audioPlayer.start();
    //else audioPlayer.stop();
    else oscillatorSource.noteOff();
}

void MainWindow::on_pushButton_pressed()
{
    //audioPlayer.start();
    oscillatorSource.noteOn();
}

void MainWindow::on_pushButton_released()
{
    //audioPlayer.stop();
    oscillatorSource.noteOff();
}

void MainWindow::on_NoteSelector_sliderMoved(int position)
{
    float noteFrequency = Note::getNoteFrequency(position);
    oscillatorSource.setFrequency(noteFrequency);
    ui->FreeAmplitude->setValue(noteFrequency);
    ui->CurrentNote->setText(QString::fromStdString(Note::getNoteName(position)));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    int pressedKey = event->key();
    if (!oscillatorSource.isOn())
    {
        switch (pressedKey)
        {
            case Qt::Key_1:
                oscillatorSource.setFrequency(Note::getNoteFrequency("C4"));
                break;
            case Qt::Key_2:
                oscillatorSource.setFrequency(Note::getNoteFrequency("D4"));
                break;
            case Qt::Key_3:
                oscillatorSource.setFrequency(Note::getNoteFrequency("E4"));
                break;
            case Qt::Key_4:
                oscillatorSource.setFrequency(Note::getNoteFrequency("F4"));
                break;
            case Qt::Key_5:
                oscillatorSource.setFrequency(Note::getNoteFrequency("G4"));
                break;
            case Qt::Key_6:
                oscillatorSource.setFrequency(Note::getNoteFrequency("A4"));
                break;
            case Qt::Key_7:
                oscillatorSource.setFrequency(Note::getNoteFrequency("B4"));
                break;
            case Qt::Key_8:
                oscillatorSource.setFrequency(Note::getNoteFrequency("C5"));
                break;
        }
        oscillatorSource.noteOn();
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    oscillatorSource.noteOff();
}

void MainWindow::on_AttackSlider_valueChanged(int value)
{
    oscillatorSource.setAttack(value*0.01);
    ui->AttackLCD->display(value*0.01);
}

void MainWindow::on_DecaySlider_valueChanged(int value)
{
    oscillatorSource.setDecay(value*0.01);
    ui->DecayLCD->display(value*0.01);

}

void MainWindow::on_SustainSlider_valueChanged(int value)
{
    oscillatorSource.setSustain(value);
    ui->SustainLCD->display(value);

}

void MainWindow::on_ReleaseSlider_valueChanged(int value)
{
    oscillatorSource.setRelease(value*0.01);
    ui->ReleaseLCD->display(value*0.01);
}


void MainWindow::onMidiNoteOff(const int chan, const int note, const int vel)
{
    oscillatorSource.noteOff();
    ui->DebugMessageLabel->setText(QString("note off: ch=%1 note=%2 vel=%3\n").arg(chan).arg(note).arg(vel));
}

void MainWindow::onMidiNoteOn(const int chan, const int note, const int vel)
{
    if (vel == 0){
        onMidiNoteOff(chan, note, vel);
    }
    oscillatorSource.setFrequency(Note::getNoteFrequency(note));
    oscillatorSource.noteOn();
    ui->DebugMessageLabel->setText(QString("note on:  ch=%1 note=%2 vel=%3\n").arg(chan).arg(note).arg(vel));
}

