#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QFile>
#include <QDebug>
#include <QEventLoop>
#include <QUrl>
#include <QNetworkReply>
#include <QThread>
#include "track.h"
#include <QList>
#include "traksrepository.h"

class Downloader:public QObject, public TraksRepository
{
    Q_OBJECT

    public:

        explicit Downloader(QObject* parent = 0 );

        QList<int> taksIdList;

        QByteArray doDownload(QString url, QString artist, QString title);
        void saveFile(QString filename,QByteArray content);

        void showSIZE()
        {
            qDebug()<<"SIZE: " << audioList.size();


        }
public slots:

        void downloadLoop();



        void showDownloadSize(qint64,qint64);


signals:
        void progressDownloader(qint64,qint64);
        void endDownloadWantRemoveRow(QString id);


};

#endif // DOWNLOADER_H
