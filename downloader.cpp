#include "downloader.h"


QByteArray Downloader::Do_Download(QString url)
{
    QNetworkAccessManager* manager = new QNetworkAccessManager();//создаем объект класса для работы с http
    QNetworkReply* reply = manager->get(QNetworkRequest(QUrl(url)));//выполняем гет запрос и записываем ответ

    QEventLoop eventLoop;

        QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), manager, SLOT(deleteLater()));
        QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),&eventLoop, SLOT(quit()));
        QObject::connect(reply, SIGNAL(downloadProgress(qint64,qint64)),this, SLOT(showDownloadSize(qint64,qint64)));

    eventLoop.exec();

    QByteArray answer = reply->readAll();
    reply->deleteLater();

    return answer;
}

void Downloader::saveFile(QString filename,QByteArray content)
{

    QFile localFile("E://VkAudioSaver/"+filename+".mp3");
          if (!localFile.open(QIODevice::WriteOnly))
              qDebug() << "Vse huna!!!" ;

        localFile.write(content);
        localFile.close();

        qDebug() << "ENDSAVE";

}



void Downloader::showDownloadSize(qint64 current, qint64 total)
{
    //qDebug() <<current<<total;
    emit progressDownloader(current,total);
}



