#include <QDebug>
#include "midicontrol.h"

MidiControl::MidiControl(QComboBox &qtChooser,QLabel &label)
{
    midiChooser = &qtChooser;
    messageLabel = &label;
    initializeMidi();
}

void MidiControl::initializeMidi()
{
    QStringList connections = midiInput.connections(true);
    midiChooser->addItems(connections);
    if (connections.size() > 0)
    {
        on_MidiChooser_activated(midiChooser->currentText());
    }

    connect(midiChooser, SIGNAL(activated(const QString)),this,SLOT(on_MidiChooser_activated(QString)));

}

void MidiControl::on_MidiChooser_activated(const QString &string)
{
    midiInput.open(string);
}

