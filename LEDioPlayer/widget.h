#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QDebug>
#include <QStringList>
#include <QTime>
#include <QTimer>
#include <QPainter>
#include <QWidget>
#include "mediaplayer.h"
#include "bass.h"
#include "transmitter.h"
#include <QMouseEvent>
#include "settings.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QPoint previousPosition READ previousPosition WRITE setPreviousPosition NOTIFY previousPositionChanged)

    enum MouseType{
        None = 0,
        Top,
        Bottom,
        Left,
        Right,
        Move
    };

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    QPoint previousPosition() const;

public slots:
    void setPreviousPosition(QPoint previousPosition);

signals:
    void previousPositionChanged(QPoint previousPosition);

private slots:

    void on_volController_valueChanged(int value);

    void drawSpectrum();

    void playMode1(float *fft);

    void playMode2(float *fft);

    void on_btnAdd_clicked();

    void applyStyles();

    void toZeroValues();

    void connectAll();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::Widget *ui;
    QStandardItemModel *playListModel;

    MouseType m_leftMouseButtonPressed;
    QPoint m_previousPosition;

    MouseType checkResizableField(QMouseEvent *event);

    MediaPlayer *m_player;

    QTimer *timer;

    QStringList *trackList;
    int currentAudioIndex;
    int selectedAudioIndex;

    bool running;
    bool onPause;

    QString getAudioFileName(QString filename);

    // Arduino control
    Transmitter *m_transmitter;

    byte delay;

    Settings s;
};

#endif // WIDGET_H
