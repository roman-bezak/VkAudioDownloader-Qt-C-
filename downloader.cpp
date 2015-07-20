#include "downloader.h"


Downloader::Downloader(QObject *parent) : QObject(parent){}

QByteArray Downloader::doDownload(QString url,QString artist,QString title)
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

    delete manager;


    this->saveFile(artist+"-"+title, answer);

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

void Downloader::downloadLoop()
{
    while(true)
    {
        if(taksIdList.isEmpty() == false)
        {

            for(int i=0; i < audioList.size(); i++)
            {
                if(taksIdList.isEmpty() == false)
                   {

                        if(audioList[i].getId() == taksIdList.first())
                        {
                            qDebug()<<"In downloader";

                            this->doDownload(audioList[i].getUrl(),
                                     audioList[i].getArtist(),
                                     audioList[i].getTitle());

                            if(audioList[i].getId() == taksIdList.first())
                                emit endDownloadWantRemoveRow(QString::number(taksIdList.first()));

                            break;
                        }

                }else break;

            }
        }


        QThread::msleep(1000);

    }
}





void Downloader::showDownloadSize(qint64 current, qint64 total)
{
    emit progressDownloader(current,total);
}





