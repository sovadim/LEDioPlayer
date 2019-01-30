#include "widget.h"
#include "ui_widget.h"
#include "bass.h"
#include <QFileDialog>
#include <QDir>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include "stylehelper.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
