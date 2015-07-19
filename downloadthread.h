#ifndef DOWNLOADTHREAD_H
#define DOWNLOADTHREAD_H

#include <QDebug>
#include <QThread>
#include <QList>
#include "track.h"

class DownloadThread : public QThread
{
public:


    QList<int> downloadTrackList;
    //QList<Track>  &audioTrackList;

    DownloadThread();


    void run();

};

#endif // DOWNLOADTHREAD_H
