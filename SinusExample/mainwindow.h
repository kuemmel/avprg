#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QAudioOutput>
#include <QKeyEvent>
#include "audioplayer.h"
#include "oscillatorsource.h"

#include "sinus.h"
#include "noise.h"
#include "rect.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    typedef enum
    {
    	SINUS = 0,
        NOISE = 1,
        RECT = 2,
        TENT = 3,
        SAWT = 4
    } Sources;

private slots:
    void on_VolumeControl_valueChanged(int value);
    void on_SetSource_currentIndexChanged(int index);

    void on_FreeAmplitude_sliderMoved(int position);

    void on_checkBox_toggled(bool checked);

    void on_pushButton_pressed();
    void on_pushButton_released();
    void on_NoteSelector_sliderMoved(int position);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void on_AttackSlider_valueChanged(int value);

    void on_DecaySlider_valueChanged(int value);

    void on_SustainSlider_valueChanged(int value);

    void on_ReleaseSlider_valueChanged(int value);

private:
    void initializeAudio();
    Ui::MainWindow *ui;
    OscillatorSource oscillatorSource;
    AudioPlayer audioPlayer;
};

#endif // MAINWINDOW_H
