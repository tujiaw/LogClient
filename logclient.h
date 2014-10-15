#ifndef LOGCLIENT_H
#define LOGCLIENT_H

#include <QTextStream>

class LogClient
{
public:
    LogClient(const QString &file, quint32 line);
    ~LogClient();

    QTextStream& stream() { return stream_; }

private:
    QString buffer_;
    QTextStream stream_;
};

#define MYLOG LogClient(__FILE__, __LINE__).stream()

#endif // LOGCLIENT_H


//#pragma once
//#include <QTextStream>
//
//#define CLOG ConsoleLog(__FILE__, __LINE__).stream()
//#define ULOG UdpLog(__FILE__, __LINE__).stream()
//#define FLOG FileLog(__FILE__, __LINE__).stream()
//
//class RtLog
//{
//public:
//	RtLog(const QString &file, quint32 line);
//	virtual ~RtLog() = 0;
//	QTextStream& stream() { return stream_; }
//
//protected:
//	QString buffer_;
//	QTextStream stream_;
//};
//
//class ConsoleLog : public RtLog
//{
//public:
//	ConsoleLog(const QString &file, quint32 line);
//	~ConsoleLog();
//};
//
//class QUdpSocket;
//class UdpLog : public RtLog
//{
//public:
//	UdpLog(const QString &file, quint32 line);
//	~UdpLog();
//
//private:
//	static QUdpSocket *s_udp;
//};
//
//class FileLog : public RtLog
//{
//public:
//	FileLog(const QString &file, quint32 line);
//	~FileLog();
//
//private:
//	static QTextStream *writeStream_;
//};
