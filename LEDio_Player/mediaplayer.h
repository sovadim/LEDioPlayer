#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include "bass.h"
#include <QObject>
#include <QDebug>

class MediaPlayer : public QObject
{
    Q_OBJECT
public:
    explicit MediaPlayer(QObject *parent = nullptr);

    bool InitDefaultDevice;
    int Stream;

private:
    int HZ = 44100;
    int Volume = 100;


    bool InitBass(int hz);

signals:

public slots:
    void play(QString filename, int vol);
    void pause();
    void resume();
    void stop();

    void SetVolumeToStream(/*int stream,*/ int vol);
    void SetPosOfScroll(int pos);

    int GetTimeOfStream();
    int GetPosOfStream();

    float* getFFT(float *fft);
};

#endif // MEDIAPLAYER_H
