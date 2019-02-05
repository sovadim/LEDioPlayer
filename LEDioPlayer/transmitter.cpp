#include "transmitter.h"

#include <QDebug>
#include <QThread>

Transmitter::Transmitter(QObject *parent) : QObject(parent)
{
    qDebug() << "Transmitter inition";

    m_pSerialPort = new QSerialPort(this);

    m_pSerialPort->setBaudRate(QSerialPort::Baud9600);
    m_pSerialPort->setDataBits(QSerialPort::Data8);
    m_pSerialPort->setParity(QSerialPort::NoParity);
    m_pSerialPort->setStopBits(QSerialPort::OneStop);
    m_pSerialPort->setFlowControl(QSerialPort::NoFlowControl);

    connect();
}

bool Transmitter::isConnected() const
{
    return m_isConnected;
}

void Transmitter::connect()
{

    info = new QSerialPortInfo();

    if(info->availablePorts().length()==0){
        m_isConnected = false;
        return;
    }
    m_pSerialPort->setPort(info->availablePorts()[0]);

    if (m_pSerialPort->open(QSerialPort::ReadWrite))
    {
        qDebug() << "Serial port is open";
        m_isConnected = true;
    }
    else
    {
        qDebug() << "Port is closed";
        m_isConnected = false;
    }

}

void Transmitter::writeRGB(int r, int g, int b, char delay, int led_amount)
{
    QByteArray sentData;
    sentData.resize(6);

    sentData[0] = -1;
    sentData[1] = char(r);
    sentData[2] = char(g);
    sentData[3] = char(b);
    sentData[4] = delay;
    sentData[5] = char(led_amount);

    m_pSerialPort->write(sentData);

    //qDebug() << "write: " + QString::number(r) + " " + QString::number(g) + " " + QString::number(b) + " " + QString::number(delay);
}
