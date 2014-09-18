#include "logclient.h"
#include <QtNetwork/QUdpSocket>
#include <QTextCodec>
#include <QDateTime>

static unsigned short PORT = 5566;
static QUdpSocket *s_udp = NULL;

LogClient::LogClient(const QString &file, quint32 line)
    : stream_(&buffer_, QIODevice::Append)
{
    stream_ << "[" << QDateTime::currentDateTime().toString("HH:mm:ss.zzz") << "," << file.section("\\", -1) << "," << line << "] ";
}

LogClient::~LogClient()
{
    if (NULL == s_udp) {
        s_udp = new QUdpSocket();
    }

    QByteArray myArray = buffer_.toUtf8();
    s_udp->writeDatagram(myArray.data(), myArray.size(), QHostAddress::LocalHost, PORT);
}


