#include "mediaplayer.h"


MediaPlayer::MediaPlayer(QObject *parent) : QObject(parent)
{
    qDebug() << "MediaPlayer constructor";
}

bool MediaPlayer::InitBass(int hz){

    if (!InitDefaultDevice){
        InitDefaultDevice = BASS_Init(-1, hz, BASS_DEVICE_DEFAULT, NULL, NULL);
        qDebug() << "active: " + InitDefaultDevice;
    }
    return InitDefaultDevice;

}

void MediaPlayer::play(QString filename, int vol){

    qDebug() << "play";

    stop();

    if (InitBass(HZ)){
        Stream = BASS_StreamCreateFile(false, filename.toLatin1().data(), 0, 0, 0);
        if (Stream != 0){
            Volume = vol;
            BASS_ChannelSetAttribute(Stream, BASS_ATTRIB_VOL, Volume/100.0);
            BASS_ChannelPlay(Stream, false);
        }
    }
}

void MediaPlayer::stop(){
    qDebug() << "stop";

    BASS_ChannelStop(Stream);
    BASS_StreamFree(Stream);
}

void MediaPlayer::pause(){
    qDebug() << "pause";

    BASS_ChannelPause(Stream);
}

void MediaPlayer::resume(){
    qDebug() << "resume";

    if (!BASS_ChannelPlay(Stream, false))
        qDebug() << "Error resuming";

}

void MediaPlayer::SetVolumeToStream(int vol){
    Volume = vol;
    BASS_ChannelSetAttribute(Stream, BASS_ATTRIB_VOL, Volume/100.0);
}

int MediaPlayer::GetTimeOfStream(){
    long TimeBytes = BASS_ChannelGetLength(Stream, BASS_POS_BYTE); // Check out
    double Time = BASS_ChannelBytes2Seconds(Stream, TimeBytes);

    return (int)Time;
}

// getting current position in seconds
int MediaPlayer::GetPosOfStream(){
    long pos = BASS_ChannelGetPosition(Stream, BASS_POS_BYTE);
    int posSec = (int)BASS_ChannelBytes2Seconds(Stream, pos);

    return posSec;
}

void MediaPlayer::SetPosOfScroll(int pos){
    BASS_ChannelSetPosition(Stream, (double)pos, BASS_POS_BYTE);
}

float* MediaPlayer::getFFT(float *fft){
    BASS_ChannelGetData(Stream, fft, BASS_DATA_FFT1024);
    return fft;
}
