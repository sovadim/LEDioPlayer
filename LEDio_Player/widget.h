#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QMouseEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QPoint previousPosition READ previousPosition WRITE setPreviousPosition NOTIFY previousPositionChanged)

    enum MouseType {
        None = 0,
        Top,
        Bottom,
        Left,
        Right,
        Move
    };

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QPoint previousPosition() const;

public slots:
    void setPreviousPosition(QPoint previousPosition);

signals:
    void previousPositionChanged(QPoint previousPosition);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::Widget *ui;
    QStandardItemModel  *m_playListModel;

    MouseType m_leftMouseButtonPressed;
    QPoint m_previousPosition;

    MouseType checkResizableField(QMouseEvent *event);

};
#endif // WIDGET_H
