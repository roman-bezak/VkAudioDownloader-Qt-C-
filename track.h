#ifndef TRACK_H
#define TRACK_H

#include <QObject>

class Track
{


public:

    Track(){}

    void setId(int _id){id=_id;}
    void setArtist(QString _artist){artist=_artist;}
    void setTitle(QString _title){title=_title;}
    void setDuration(int dur){duration=dur;}
    void setUrl(QString _url){url=_url;}
    void setStyle(int _style){style=_style;}

    int getId(){return id;}
    QString getArtist(){return artist;}
    QString getTitle(){return title;}
    int getDuration(){return duration;}
    QString getUrl(){return url;}
    int getStyle(){return style;}


private:

    int id;
    QString artist;
    QString title;
    int duration;
    QString url;
    int style;



};

#endif // TRACK_H
