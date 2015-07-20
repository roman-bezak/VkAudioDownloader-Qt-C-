#ifndef GETSENDER_H
#define GETSENDER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>

class GetSender:public QObject
{
    Q_OBJECT

public:

    explicit GetSender(QObject* parent = 0 ) : QObject(parent){}
    QByteArray sendGetRequest(QString);
};

#endif // GETSENDER_H
