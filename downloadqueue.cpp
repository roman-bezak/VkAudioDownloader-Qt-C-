#include "downloadqueue.h"
#include "ui_downloadqueue.h"

DownloadQueue::DownloadQueue(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DownloadQueue)
{
    ui->setupUi(this);

    headerHorizNames <<"Artist"<<"Title"<<" ";

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(headerHorizNames);
}

DownloadQueue::~DownloadQueue()
{
    delete ui;
}

void DownloadQueue::insertAudioRowForDownload(QString artist, QString title)
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);

    ui->tableWidget->setItem(ui->tableWidget->rowCount()+1,
                             0, new QTableWidgetItem(artist));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()+1,
                             1, new QTableWidgetItem(title));
}
