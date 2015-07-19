#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QFile>
#include <QDebug>
#include <QEventLoop>
#include <QUrl>
#include <QNetworkReply>



class Downloader:public QObject
{
    Q_OBJECT

    public:

        explicit Downloader(QObject* parent = 0 ) : QObject(parent){}

        QNetworkAccessManager* manager;
        QByteArray Do_Download(QString url);
        void saveFile(QString filename,QByteArray content);

public slots:
        void showDownloadSize(qint64,qint64);
signals:
        void progressDownloader(qint64,qint64);


};

#endif // DOWNLOADER_H
