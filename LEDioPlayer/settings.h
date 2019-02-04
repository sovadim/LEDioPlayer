#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

    static int get_v1r();
    static int get_v1g();
    static int get_v1b();

    static int get_v2r();
    static int get_v2g();
    static int get_v2b();

    static int get_v3r();
    static int get_v3g();
    static int get_v3b();

    static float get_minLevel();

    static bool get_mode();

private slots:
    void setDefaults();

    void on_v1r_valueChanged(int value);

    void on_v1g_valueChanged(int value);

    void on_v1b_valueChanged(int value);

    void on_v2r_valueChanged(int value);

    void on_v2g_valueChanged(int value);

    void on_v2b_valueChanged(int value);

    void on_v3r_valueChanged(int value);

    void on_v3g_valueChanged(int value);

    void on_v3b_valueChanged(int value);

    void updateSliders();

    void on_slider_minLevel_valueChanged(int value);

    void on_slider_amount_valueChanged(int value);

private:
    Ui::Settings *ui;

};

#endif // SETTINGS_H
