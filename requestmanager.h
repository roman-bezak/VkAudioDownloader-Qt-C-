#ifndef REQUESTMANAGER_H
#define REQUESTMANAGER_H

#include <QObject>
#include "getsender.h"
#include "track.h"

class RequestManager:public QObject
{


Q_OBJECT

public:

    explicit RequestManager(QObject* parent = 0 ) : QObject(parent){

        getSender = new GetSender();

    }

    void audioGet(QString, QString, int, QList<Track>&);
    int audioCount(QString, QString);

    GetSender *getSender;

signals:

    void TrackListBeLoaded();


};

#endif // REQUESTMANAGER_H
