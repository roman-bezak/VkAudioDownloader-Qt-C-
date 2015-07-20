#ifndef DOWNLOADQUEUE_H
#define DOWNLOADQUEUE_H

#include <QMainWindow>
#include <QStringList>
#include <QSignalMapper>
#include <QDebug>
#include <QPushButton>
#include <QThread>
#include "downloader.h"





namespace Ui {
class DownloadQueue;
}

class DownloadQueue : public QMainWindow
{
    Q_OBJECT

private:

    QStringList headerHorizNames;


public:


    explicit DownloadQueue(QWidget *parent = 0);
    ~DownloadQueue();


    Ui::DownloadQueue *ui;
    QSignalMapper *mapper;

    Downloader *downloaderInThread;
    QThread *threadForDownloader;

    void insertAudioRowForDownload(QString artist, QString title, int id);


public slots:

    void removeAudioRow(QString id);

};

#endif // DOWNLOADQUEUE_H
