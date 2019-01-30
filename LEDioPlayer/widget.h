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
    void on_btnPrevious_clicked();

    void on_btnStop_clicked();

    void on_btnPlay_clicked();

    void on_btnPause_clicked();

    void on_btnNext_clicked();

    void on_volController_valueChanged(int value);

    void drawSpectrum();

    void on_btnAdd_clicked();

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

    void applyStyles();

    void toZeroValues();

    // Arduino control
    Transmitter *m_transmitter;
};

#endif // WIDGET_H