#include "settings.h"
#include "ui_settings.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QDebug>

static int v1r = 255;
static int v1g = 0;
static int v1b = 51;

static int v2r = 0;
static int v2g = 0;
static int v2b = 0;

static int v3r = 0;
static int v3g = 125;
static int v3b = 255;

static float minLevel = 0.1f;

static bool mode = false; // second one as default

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    this->setStyleSheet("#backgroundWidget { background-color:white; }"
                        "QWidget { border: none; }");

    // Setting up defaults
    setDefaults();

    // Mode selection
    connect(ui->btnMode1, &QRadioButton::clicked, [this](){
        mode = ui->btnMode1->isChecked();
    });

    connect(ui->btnMode2, &QRadioButton::clicked, [this](){
        mode = ui->btnMode1->isChecked();
    });

    connect(ui->btnMode2, &QRadioButton::clicked, [this](){
        mode = ui->btnMode1->isChecked();
    });


}

Settings::~Settings()
{
    delete ui;
}

void Settings::setDefaults()
{
    ui->v1r->setValue(v1r);
    ui->v1g->setValue(v1g);
    ui->v1b->setValue(v1b);

    ui->v2r->setValue(v2r);
    ui->v2g->setValue(v2g);
    ui->v2b->setValue(v2b);

    ui->v3r->setValue(v3r);
    ui->v3g->setValue(v3g);
    ui->v3b->setValue(v3b);

    ui->slider_minLevel->setValue(minLevel * 100);
    ui->label_minLevel->setText(QString::number(minLevel));

    updateSliders();
}

void Settings::updateSliders(){
    ui->v1r->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v1r->value()) + "," +
                           QString::number(ui->v1g->value()) + "," + QString::number(ui->v1b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(255, 0, 0, 255);}");
    ui->v1g->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v1r->value()) + "," +
                           QString::number(ui->v1g->value()) + "," + QString::number(ui->v1b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(0, 255, 0, 255);}");
    ui->v1b->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v1r->value()) + "," +
                           QString::number(ui->v1g->value()) + "," + QString::number(ui->v1b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(0, 0, 255, 255);}");

    ui->v2r->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v2r->value()) + "," +
                           QString::number(ui->v2g->value()) + "," + QString::number(ui->v2b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(255, 0, 0, 255);}");
    ui->v2g->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v2r->value()) + "," +
                           QString::number(ui->v2g->value()) + "," + QString::number(ui->v2b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(0, 255, 0, 255);}");
    ui->v2b->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v2r->value()) + "," +
                           QString::number(ui->v2g->value()) + "," + QString::number(ui->v2b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(0, 0, 255, 255);}");

    ui->v3r->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v3r->value()) + "," +
                           QString::number(ui->v3g->value()) + "," + QString::number(ui->v3b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(255, 0, 0, 255);}");
    ui->v3g->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v3r->value()) + "," +
                           QString::number(ui->v3g->value()) + "," + QString::number(ui->v3b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(0, 255, 0, 255);}");
    ui->v3b->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v3r->value()) + "," +
                           QString::number(ui->v3g->value()) + "," + QString::number(ui->v3b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(0, 0, 255, 255);}");
}

float Settings::get_minLevel(){
    return minLevel;
}

bool Settings::get_mode(){
    return mode;
}

int Settings::get_v1r(){
    return v1r;
}

int Settings::get_v1g(){
    return v1g;
}


int Settings::get_v1b(){
    return v1b;
}


int Settings::get_v2r(){
    return v2r;
}


int Settings::get_v2g(){
    return v2g;
}


int Settings::get_v2b(){
    return v2b;
}


int Settings::get_v3r(){
    return v3r;
}


int Settings::get_v3g(){
    return v3g;
}


int Settings::get_v3b(){
    return v3b;
}


void Settings::on_v1r_valueChanged(int value)
{
    ui->label_v1r->setText(QString::number(value));
    updateSliders();
    v1r = value;

}

void Settings::on_v1g_valueChanged(int value)
{
    ui->label_v1g->setText(QString::number(value));
    updateSliders();
    v1g = value;
}

void Settings::on_v1b_valueChanged(int value)
{
    ui->label_v1b->setText(QString::number(value));
    updateSliders();
    v1b = value;
}

void Settings::on_v2r_valueChanged(int value)
{
    ui->label_v2r->setText(QString::number(value));
    updateSliders();
    v2r = value;
}

void Settings::on_v2g_valueChanged(int value)
{
    ui->label_v2g->setText(QString::number(value));
    updateSliders();
    v2g = value;
}

void Settings::on_v2b_valueChanged(int value)
{
    ui->label_v2b->setText(QString::number(value));
    updateSliders();
    v2b = value;
}

void Settings::on_v3r_valueChanged(int value)
{
    ui->label_v3r->setText(QString::number(value));
    updateSliders();
    v3r = value;
}

void Settings::on_v3g_valueChanged(int value)
{
    ui->label_v3g->setText(QString::number(value));
    updateSliders();
    v3g = value;
}

void Settings::on_v3b_valueChanged(int value)
{
    ui->label_v3b->setText(QString::number(value));
    updateSliders();
    v3b = value;
}

void Settings::on_slider_minLevel_valueChanged(int value)
{
    ui->label_minLevel->setText(QString::number(value/100.0f));
    minLevel = value/100.0f;
}

void Settings::on_slider_amount_valueChanged(int value)
{
    ui->label_amount->setText(QString::number(value));
}
