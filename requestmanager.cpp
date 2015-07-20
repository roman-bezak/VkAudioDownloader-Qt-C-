#include "requestmanager.h"

#include "json.h"
#include <QVariantList>
#include <QVariantMap>
#include <QMap>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include "oauth.h"
#include "track.h"

using namespace QtJson;

void RequestManager::audioGet(QString id, QString token, int count, QList<Track> &audioList )
{

     QByteArray answer = getSender->sendGetRequest("https://api.vk.com/method/audio.get?owner_id="+id+
                                                   "&count="+QString::number(count)+"&v=5.34&access_token="+token);

     QVariantList list = parse(answer).toMap().value("response").toMap().value("items").toList();

     Track tempTemplateTrack;

     for(int i = 0; i < list.size(); i++)
     {
        QVariantMap map = list[i].toMap();

        tempTemplateTrack.setId(map.value("id").toInt());
        tempTemplateTrack.setArtist(map.value("artist").toString());
        tempTemplateTrack.setTitle(map.value("title").toString());
        tempTemplateTrack.setDuration(map.value("duration").toInt());
        tempTemplateTrack.setUrl(map.value("url").toString());
        tempTemplateTrack.setStyle(map.value("genre_id").toInt());

        audioList.push_back(tempTemplateTrack);
     }

 emit TrackListBeLoaded();

}

int RequestManager::audioCount(QString id, QString token)
{

    QByteArray answer = getSender->sendGetRequest("https://api.vk.com/method/audio.getCount?owner_id=" + id + "&v=5.34&access_token=" + token );
    QVariantMap result = parse(answer).toMap();
    return result["response"].toInt();
}
