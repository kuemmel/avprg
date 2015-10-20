#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QAudioInput>
#include <QAudioDecoder>
#include <QAudioFormat>
#include <iostream>

#include "midicontrol.h"


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
    //ui elements send multiple signals, one for altering the ui, one for conrolling audio
    QObject::connect(&ui->VolumeControl, SIGNAL(on_VolumeControl_valueChanged(int)), this, SLOT(on_VolumeControl_valueChanged(int)));
    QObject::connect(&ui->FreeAmplitude, SIGNAL(on_FreeAmplitude_sliderMoved(int)), this, SLOT(on_FreeAmplitude_sliderMoved(int)));
    QObject::connect(&ui->AttackSelector, SIGNAL(on_NoteSelector_sliderMoved(int)), this, SLOT(on_NoteSelector_sliderMoved(int)));
    QObject::connect(&ui->AttackSlider, SIGNAL(on_AttackSlider_valueChanged(int)), this, SLOT(on_AttackSlider_valueChanged(int)));
    QObject::connect(&ui->DecaySlider, SIGNAL(on_DecaySlider_valueChanged(int)), this, SLOT(on_DecaySlider_valueChanged(int)));
    QObject::connect(&ui->SustainSlider, SIGNAL(on_SustainSlider_valueChanged(int)), this, SLOT(on_SustainSlider_valueChanged(int)));
    QObject::connect(&ui->ReleaseSlider, SIGNAL(on_ReleaseSlider_valueChanged(int)), this, SLOT(on_ReleaseSlider_valueChanged(int)));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onMidiNoteOff(const int chan, const int note, const int vel)
{
    ui->DebugMessageLabel->setText(QString("note off: ch=%1 note=%2 vel=%3\n").arg(chan).arg(note).arg(vel));
}

void MainWindow::onMidiNoteOn(const int chan, const int note, const int vel)
{
    ui->DebugMessageLabel->setText(QString("note on:  ch=%1 note=%2 vel=%3\n").arg(chan).arg(note).arg(vel));
}

//im Bereich 0-99
void MainWindow::on_VolumeControl_valueChanged(int value)
{
    ui->VolumeLCD->display(value);
}
void MainWindow::on_FreeAmplitude_sliderMoved(int position)
{
    ui->CurrentFrequency->display(position);
}

void MainWindow::on_NoteSelector_sliderMoved(int position)
{
    ui->FreeAmplitude->setValue(noteFrequency);
    ui->CurrentNote->setText(QString::fromStdString(Note::getNoteName(position)));
}

void MainWindow::on_AttackSlider_valueChanged(int value)
{
    ui->AttackLCD->display(value*0.01);
}

void MainWindow::on_DecaySlider_valueChanged(int value)
{
    ui->DecayLCD->display(value*0.01);
}

void MainWindow::on_SustainSlider_valueChanged(int value)
{
    ui->SustainLCD->display(value);
}

void MainWindow::on_ReleaseSlider_valueChanged(int value)
{
    ui->ReleaseLCD->display(value*0.01);
}
