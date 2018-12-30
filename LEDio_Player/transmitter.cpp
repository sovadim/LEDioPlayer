#include "transmitter.h"

#include <QDebug>
#include <QThread>

Transmitter::Transmitter(QObject *parent) : QObject(parent)
{
    qDebug() << "Transmitter inition";

    m_pSerialPort = new QSerialPort(this);
    m_pSerialPort->setPortName("COM5");

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
    if (m_pSerialPort->open(QSerialPort::ReadWrite))
    {
        qDebug() << "Serial port is open";
    }
    else
    {
        qDebug() << "Port is closed";
        m_isConnected = false;
    }

}

void Transmitter::writeRGB(int r, int g, int b)
{
    QByteArray sentData;
    sentData.resize(4);

    sentData[0] = -1;
    sentData[1] = char(r);
    sentData[2] = char(g);
    sentData[3] = char(b);

    m_pSerialPort->write(sentData);

    //qDebug() << "write: " + QString::number(r) + " " + QString::number(g) + " " + QString::number(b);
}
