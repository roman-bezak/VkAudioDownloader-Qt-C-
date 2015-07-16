#include "downloadqueue.h"
#include "ui_downloadqueue.h"

DownloadQueue::DownloadQueue(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DownloadQueue)
{
    ui->setupUi(this);

    model = new QStringListModel();

    list <<"audio"<<"vksaver"<<"add"<<"set";

    model->setStringList(list);
    ui->listView->setModel(model);
}

DownloadQueue::~DownloadQueue()
{
    delete ui;
}
