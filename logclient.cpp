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


//#include "RtLog.h"
//#include <QDateTime>
//#include <QtNetwork/QUdpSocket>
//#include <QFile>
//#include <QDebug>
//
//RtLog::RtLog(const QString &file, quint32 line)
//	: stream_(&buffer_, QIODevice::Append)
//{
//	stream_ << "[" << QDateTime::currentDateTime().toString("HH:mm:ss.zzz") << "," << file.section("\\", -1) << "," << line << "] ";
//}
//
//RtLog::~RtLog()
//{
//}
//
////---------------------------------------------------------
//ConsoleLog::ConsoleLog(const QString &file, quint32 line)
//	: RtLog(file, line)
//{
//}
//
//ConsoleLog::~ConsoleLog()
//{
//	qDebug() << buffer_;
//}
//
////---------------------------------------------------------
//QUdpSocket* UdpLog::s_udp = NULL;
//UdpLog::UdpLog(const QString &file, quint32 line)
//	: RtLog(file, line)
//{
//	if (NULL == s_udp) {
//		s_udp = new QUdpSocket();
//	}
//}
//
//UdpLog::~UdpLog()
//{
//	if (s_udp) {
//		QByteArray aArray = buffer_.toUtf8();
//		s_udp->writeDatagram(aArray.data(), aArray.size(), QHostAddress("127.0.0.1"), 5566);
//	}
//}
//
////---------------------------------------------------------------------
//QTextStream* FileLog::writeStream_ = NULL;
//FileLog::FileLog(const QString &file, quint32 line)
//	: RtLog(file, line)
//{
//	if (NULL == writeStream_) {
//		QFile *data = new QFile("output.txt");
//		if (data->open(QIODevice::Append)) {
//			writeStream_ = new QTextStream(data);
//		}
//	}
//}
//
//FileLog::~FileLog()
//{
//	if (writeStream_) {
//		*writeStream_ << buffer_ << "\n";
//		writeStream_->flush();
//	}
//}
