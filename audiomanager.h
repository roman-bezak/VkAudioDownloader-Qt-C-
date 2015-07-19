#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H


#include <QMainWindow>
#include <QObject>
#include <QList>
#include <QDebug>
#include <QMenuBar>
#include <QStringList>
#include <QSignalMapper>
#include "downloader.h"
#include "downloadqueue.h"

#include "track.h"


namespace Ui {
class AudioManager;
}



class AudioManager:public QMainWindow
{
    Q_OBJECT

    private:

        int audioCount;

    public:

        explicit AudioManager(QWidget *parent = 0);
        ~AudioManager();


        QSignalMapper *mapper;
        QStringList headerHorizNames;
        QList<Track> audioList;

        DownloadQueue *downloadqueue;
        Downloader *downloader;

        void setAudioCount(int count){audioCount = count;}
        int getAudioCount(){return audioCount;}


        void showTraksInfo()
        {
            for(int i = 0;i<audioList.size();i++)
            {
                qDebug() <<audioList[i].getTitle();
                qDebug() <<audioList[i].getArtist();
                qDebug() <<audioList[i].getUrl();
                qDebug() <<audioList[i].getDuration();
                qDebug() <<audioList[i].getStyle();
                qDebug() <<audioList[i].getId();
            }

        }
        void initTable();

        Ui::AudioManager *ui;

public slots:

        void CellButtonClicked(int RowNum);
        void updateBar(qint64,qint64);

};

#endif // AUDIOMANAGER_H
