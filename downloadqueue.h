#ifndef DOWNLOADQUEUE_H
#define DOWNLOADQUEUE_H

#include <QMainWindow>
#include <QStringList>
#include <QStringListModel>

namespace Ui {
class DownloadQueue;
}

class DownloadQueue : public QMainWindow
{
    Q_OBJECT

public:
    explicit DownloadQueue(QWidget *parent = 0);
    ~DownloadQueue();

    Ui::DownloadQueue *ui;
};

#endif // DOWNLOADQUEUE_H
