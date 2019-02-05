#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <QSerialPort>
#include <QSerialPortInfo>

class Transmitter : public QObject
{
    Q_OBJECT
public:
    explicit Transmitter(QObject *parent = 0);

    bool isConnected() const;

    void connect();
    void writeRGB(int r, int g, int b, char delay, int led_amount);

private:

    QSerialPort *m_pSerialPort;
    QSerialPortInfo *info;
    bool m_isConnected;

};

#endif // TRANSMITTER_H
