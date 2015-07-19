#include "downloadqueue.h"
#include "ui_downloadqueue.h"

DownloadQueue::DownloadQueue(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DownloadQueue)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(60);

}

DownloadQueue::~DownloadQueue()
{
    delete ui;
}
