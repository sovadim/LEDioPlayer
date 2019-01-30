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

private slots:
    void on_btnPrevious_clicked();

    void on_btnStop_clicked();

    void on_btnPlay_clicked();

    void on_btnPause_clicked();

    void on_btnNext_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
