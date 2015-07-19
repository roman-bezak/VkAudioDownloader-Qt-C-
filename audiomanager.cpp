#include "audiomanager.h"
#include "ui_audiomanager.h"
#include <QPushButton>
#include <QSignalMapper>
#include <QDebug>
#include "ui_audiomanager.h"
#include "downloader.h"
#include "ui_downloadqueue.h"




AudioManager::AudioManager(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::AudioManager)
{
    ui->setupUi(this);

    mapper = new QSignalMapper(this);
    downloader = new Downloader();
    downloadqueue = new DownloadQueue();


    downloadqueue->show();





//    QPushButton *pButton = new QPushButton("Download",ui->tableWidget);
//    pList.push_back(pButton);
//    pList.push_back(pButton);

//    ui->tableWidget->setCellWidget(0,4,pButton);

//    connect(pButton, SIGNAL(clicked()), mapper, SLOT(map()));
//    mapper->setMapping(pButton, 0);
//    connect(mapper, SIGNAL(mapped(int)), this, SLOT(CellButtonClicked(int)));


//    QSpinBox* sp;
//     sp = (QSpinBox*)ui->tblScores->cellWidget(srow,j);
//    ui->tableWidget->cellWidget()

//    //ui->tableWidget->setStyleSheet("QTableView {selection-background-color: red;}");

   // ui->tableWidget->setIsetItem(0, 1, new QTableWidgetItem("Hello"));


}

AudioManager::~AudioManager()
{
    delete ui;
}

void AudioManager::initTable()
{


    ui->tableWidget->setColumnCount(5);                 //id,title,artist,duration
    ui->tableWidget->setRowCount(audioList.size());

    headerHorizNames<<"Artist"<<"Title"<<"Duration"<<"Sound ID"<<" ";
    ui->tableWidget->setHorizontalHeaderLabels(headerHorizNames);

    for (int i = 0; i < audioList.size(); i++)
    {
        QPushButton *pButton = new QPushButton("Download",ui->tableWidget);
        connect(pButton, SIGNAL(clicked()), mapper, SLOT(map()));
        mapper->setMapping(pButton, i);
        ui->tableWidget->setCellWidget(i,4,pButton);
    }

    connect(mapper, SIGNAL(mapped(int)), this, SLOT(audioRowButtonClicked(int)));


}

void AudioManager::audioRowButtonClicked(int RowNum)
{

    downloadqueue->insertAudioRowForDownload(audioList[RowNum].getArtist(),
                                             audioList[RowNum].getTitle());

    qDebug() << "START_DOWNLOAD";


    connect(downloader,SIGNAL(progressDownloader(qint64,qint64)),this,SLOT(updateBar(qint64,qint64)));

    QByteArray answer = downloader->Do_Download(audioList[RowNum].getUrl());

    downloader->saveFile(audioList[RowNum].getTitle(),answer);

    qDebug() << "EndDownloadAndSaveFile: "+audioList[RowNum].getTitle()+"\n\n";


}

void AudioManager::updateBar(qint64 current, qint64 total)
{
   ui->progressBar->setMaximum(total);
   ui->progressBar->setValue(current);
}
