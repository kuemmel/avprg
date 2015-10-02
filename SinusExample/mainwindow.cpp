#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QAudioInput>
#include <QAudioDecoder>
#include <QAudioFormat>
#include <iostream>

#include "note.h"

#include "noise.h"
#include "sinus.h"
#include "rect.h"
#include "tent.h"
#include "sawtooth.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , audioPlayer(this)

{
    initializeAudio();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initializeAudio(){
    audioPlayer.setAudioSource(&oscillatorSource);
    //audioPlayer.start();
}

//im Bereich 0-99
void MainWindow::on_VolumeControl_valueChanged(int value)
{
    oscillatorSource.setVolume(value*0.01);
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
    if(checked) audioPlayer.start();
    else audioPlayer.stop();
}

void MainWindow::on_pushButton_pressed()
{
    audioPlayer.start();
}

void MainWindow::on_pushButton_released()
{
    audioPlayer.stop();
}

void MainWindow::on_NoteSelector_sliderMoved(int position)
{
    Note note(position);
    oscillatorSource.setFrequency(note.frequency);
    ui->CurrentNote->setText(QString::fromStdString(note.name));
    ui->FreeAmplitude->setValue((int)note.frequency);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    int pressedKey = event->key();

    switch (pressedKey)
    {
        case Qt::Key_0:
            oscillatorSource.setFrequency(Note::getNoteFrequency("C4"));
            break;
        case Qt::Key_1:
            oscillatorSource.setFrequency(Note::getNoteFrequency("D4"));
            break;
        case Qt::Key_2:
            oscillatorSource.setFrequency(Note::getNoteFrequency("E4"));
            break;
        case Qt::Key_3:
            oscillatorSource.setFrequency(Note::getNoteFrequency("F4"));
            break;
        case Qt::Key_4:
            oscillatorSource.setFrequency(Note::getNoteFrequency("G4"));
            break;
        case Qt::Key_5:
            oscillatorSource.setFrequency(Note::getNoteFrequency("A4"));
            break;
        case Qt::Key_6:
            oscillatorSource.setFrequency(Note::getNoteFrequency("B4"));
            break;
        case Qt::Key_7:
            oscillatorSource.setFrequency(Note::getNoteFrequency("C5"));
            break;
    }

    audioPlayer.start();
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    audioPlayer.stop();
}
