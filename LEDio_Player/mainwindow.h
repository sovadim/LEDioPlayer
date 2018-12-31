#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //Q_PROPERTY(QPoint previousPosition READ previousPosition WRITE setPreviousPosition NOTIFY previousPositionChanged)

    enum MouseType{
        None = 0,
        Top,
        Bottom,
        Left,
        Right,
        Move
    };

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    //void setPreviousPosition(QPoint previousPosition);

signals:
    //void previousPositionChanged(QPoint previousPosition);

protected:
    /*void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);*/

private slots:

    void on_btnAdd_clicked();

    void on_btnPause_clicked();

    void on_btnPrevious_clicked();

    void on_btnNext_clicked();

    void on_volController_valueChanged(int value);

    void on_btnPlay_clicked();

    void on_btnStop_clicked();

    void drawSpectrum();

    void on_MainWindow_destroyed();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *playListModel;
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


    //MouseType m_leftMouseButtonPressed;
    //QPoint m_previousPosition;

    //MouseType checkResizableField(QMouseEvent *event);
};

#endif // MAINWINDOW_H
