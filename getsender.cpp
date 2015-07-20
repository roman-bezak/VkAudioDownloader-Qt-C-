#include "getsender.h"



QByteArray GetSender::sendGetRequest(QString url)
{
    QNetworkAccessManager* manager = new QNetworkAccessManager();//создаем объект класса для работы с http
    QNetworkReply* reply = manager->get(QNetworkRequest(QUrl(url)));//выполняем гет запрос и записываем ответ

    QEventLoop eventLoop;
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),&eventLoop, SLOT(quit()));
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), manager, SLOT(deleteLater()));
    eventLoop.exec();

    QByteArray answer = reply->readAll();

    reply->deleteLater();

    delete manager;

    return answer;
}
