#include "serialinterface.h"

SerialInterface::SerialInterface(QObject *parent) : QObject(parent) {
    connect(&m_serialPort, &QSerialPort::readyRead, this, &SerialInterface::handleReadyRead);
    connect(&m_serialPort, &QSerialPort::errorOccurred, this, &SerialInterface::handleError);
}

bool SerialInterface::connect(const QString &portName, qint32 baudRate) {
    m_serialPort.setPortName(portName);
    m_serialPort.setBaudRate(baudRate);
    m_serialPort.setParity(QSerialPort::NoParity);
    m_serialPort.setDataBits(QSerialPort::Data8);
    m_serialPort.setStopBits(QSerialPort::OneStop);
    return m_serialPort.open(QIODevice::ReadWrite);
}

void SerialInterface::disconnect() {
    m_serialPort.close();
}

void SerialInterface::sendData(const QByteArray &data) {
    m_serialPort.write(data);
}

void SerialInterface::handleReadyRead() {
    emit dataReceived(m_serialPort.readAll());
}

void SerialInterface::handleError(QSerialPort::SerialPortError error) {
    if(error != QSerialPort::NoError)
        emit errorOccurred(m_serialPort.errorString());
}