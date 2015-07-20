#include "downloadqueue.h"
#include "ui_downloadqueue.h"



DownloadQueue::DownloadQueue(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DownloadQueue)
{
    ui->setupUi(this);

    mapper = new QSignalMapper(this);


    headerHorizNames <<"Artist"<<"Title"<<"ID"<<" ";

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(headerHorizNames);

    connect(mapper, SIGNAL(mapped(QString)), this, SLOT(removeAudioRow(QString)));

    downloaderInThread = new Downloader();
    threadForDownloader = new QThread();

    downloaderInThread->moveToThread(threadForDownloader);

    connect(threadForDownloader,SIGNAL(started()),
            downloaderInThread,SLOT(downloadLoop()));

    threadForDownloader->start();

}

DownloadQueue::~DownloadQueue()
{
    delete ui;
}

void DownloadQueue::insertAudioRowForDownload(QString artist, QString title,int id)
{

    downloaderInThread->taksIdList.push_back(id);

    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);

    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                             0, new QTableWidgetItem(artist));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                             1, new QTableWidgetItem(title));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                             2, new QTableWidgetItem(QString::number(id)));


    QPushButton *pButton = new QPushButton("Удалить из очереди",ui->tableWidget);

    connect(pButton, SIGNAL(clicked()), mapper, SLOT(map()));

    mapper->setMapping(pButton, QString::number(id));

    ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 3, pButton);



}


void DownloadQueue::removeAudioRow(QString id)
{


    downloaderInThread->taksIdList.removeOne(id.toInt());

    for(int i=0; i < ui->tableWidget->rowCount(); i++)
        if( ui->tableWidget->item(i,2)->text() == id )
            ui->tableWidget->removeRow(i);

}


