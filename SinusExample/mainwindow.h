#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QAudioOutput>
#include <QKeyEvent>

#include "midicontrol.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

/**
 * These slots are also in the audiocontrol
 **/
private slots:
    void onMidiNoteOff(const int chan, const int note, const int vel);
    void onMidiNoteOn(const int chan, const int note, const int vel);

    void on_VolumeControl_valueChanged(int value);
    void on_FreeAmplitude_sliderMoved(int position);

    void on_NoteSelector_sliderMoved(int position);

    void on_AttackSlider_valueChanged(int value);
    void on_DecaySlider_valueChanged(int value);
    void on_SustainSlider_valueChanged(int value);
    void on_ReleaseSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    MidiControl* midiControl;
};

#endif // MAINWINDOW_H
