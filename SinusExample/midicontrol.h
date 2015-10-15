#ifndef MIDICONTROL_H
#define MIDICONTROL_H

#include <QLabel>
#include <QComboBox>
#include <QObject>
#include "midiinput.h"

class MidiControl : public QObject
{
    Q_OBJECT

public:
    MidiControl();
    MidiControl(QComboBox& qtChooser,QLabel& label);
    ~MidiControl(){};

    void addQWidget(QComboBox& comboBox);

    drumstick::rt::MIDIInput midiInput;
private slots:
    //void onMidiNoteOff(const int chan, const int note, const int vel);
    //void onMidiNoteOn(const int chan, const int note, const int vel);
    void on_MidiChooser_activated(const QString &string);
private:
    void initializeMidi();
    void prependMessage(QString message);
private:
    QComboBox* midiChooser;
    QLabel* messageLabel;
};

#endif // MIDICONTROL_H

