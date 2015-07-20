#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H


#include <QMainWindow>
#include <QObject>
#include <QList>
#include <QDebug>
#include <QMenuBar>
#include <QStringList>
#include <QSignalMapper>
#include <QDebug>
#include "downloader.h"
#include "downloadqueue.h"
#include "track.h"
#include "traksrepository.h"


namespace Ui {
class AudioManager;
}



class AudioManager:public QMainWindow, public TraksRepository
{
    Q_OBJECT

    private:

        int audioCount;

    public:

        explicit AudioManager(QWidget *parent = 0);
        ~AudioManager();


        QSignalMapper *mapper;
        QStringList headerHorizNames;


        QThread* thread;
        DownloadQueue *downloadqueue;


        void setAudioCount(int count){audioCount = count;}
        int getAudioCount(){return audioCount;}


        void initTable();

        Ui::AudioManager *ui;

public slots:

        void audioRowButtonClicked(int RowNum);
        void updateBar(qint64,qint64);


};

#endif // AUDIOMANAGER_H
