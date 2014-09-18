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
