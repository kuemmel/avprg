#ifndef MIDICONTROL_H
#define MIDICONTROL_H

#include <QLabel>
#include <QComboBox>
#include <QObject>
//#include <QMainWindow>
#include "mainwindow.h"
#include "midiinput.h"
#include "audioplayer.h"
#include "oscillatorsource.h"


namespace Ui {
class MainWindow;
}


class AudioControl : public QObject
{
    Q_OBJECT


    typedef enum
    {
        SINUS = 0,
        NOISE = 1,
        RECT = 2,
        TENT = 3,
        SAWT = 4
    } Sources;


public:
    AudioControl();
    AudioControl(Ui::MainWindow* ui);
    ~AudioControl(){};

    void addQWidget(QComboBox& comboBox);

    drumstick::rt::MIDIInput midiInput;
private slots:
    void on_MidiChooser_activated(const QString &string);
    void onMidiNoteOff(const int chan, const int note, const int vel);
    void onMidiNoteOn(const int chan, const int note, const int vel);

    void on_SetSource_currentIndexChanged(int index);
    void on_VolumeControl_valueChanged(int value);
    void on_FreeAmplitude_sliderMoved(int position);

    void on_checkBox_toggled(bool checked);

    void on_pushButton_pressed();
    void on_pushButton_released();
    void on_NoteSelector_sliderMoved(int position);

    void on_AttackSlider_valueChanged(int value);
    void on_DecaySlider_valueChanged(int value);
    void on_SustainSlider_valueChanged(int value);
    void on_ReleaseSlider_valueChanged(int value);
private:
    void initializeAudio();
    void initializeMidi(Ui::MainWindow* ui);
    void prependMessage(QString message);

private:
    OscillatorSource oscillatorSource;
    AudioPlayer audioPlayer;
};

#endif // MIDICONTROL_H

