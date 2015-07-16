#ifndef OAUTH_H
#define OAUTH_H

#include <QString>
#include <QDebug>
#include <QUrl>
#include <QUrlQuery>
#include "audiomanager.h"
#include "requestmanager.h"

class OAuth: public QObject
{
    Q_OBJECT

    public:

        explicit OAuth(QObject* parent = 0 ) : QObject(parent){

        audioManager = new AudioManager();
        requestManager = new RequestManager();
    }


        QString getToken();
        QString getUserId();

        RequestManager *requestManager;
        AudioManager *audioManager;

    private:

        QString token;
        QString user_id;





    public slots:

        void check_URL(QUrl url);

    signals:
        void oauthSuccess();

};

#endif // OAUTH_H
