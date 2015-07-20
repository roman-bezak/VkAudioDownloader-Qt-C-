#ifndef TRAKSREPOSITORY_H
#define TRAKSREPOSITORY_H

#include <QList>
#include "track.h"

class TraksRepository
{
public:
    TraksRepository();
    QList<Track> audioList;
};

#endif // TRAKSREPOSITORY_H
