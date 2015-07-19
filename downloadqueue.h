#ifndef DOWNLOADQUEUE_H
#define DOWNLOADQUEUE_H

#include <QMainWindow>
#include <QStringList>


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

    void insertAudioRowForDownload(QString artist, QString title);
};

#endif // DOWNLOADQUEUE_H
