#include "audiomanager.h"
#include "ui_audiomanager.h"
#include <QPushButton>
#include <QSignalMapper>
#include <QCheckBox>
#include <QTableWidgetItem>
#include "ui_audiomanager.h"
#include "downloader.h"
#include "ui_downloadqueue.h"




AudioManager::AudioManager(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::AudioManager)
{
    ui->setupUi(this);

    mapper = new QSignalMapper(this);

    downloadqueue = new DownloadQueue();

    downloadqueue->show();

    ui->tableWidget->hideColumn(0);


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



    QCheckBox *box = new QCheckBox();        
    ui->tableWidget->setCellWidget(0,0,box);
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(audioRowButtonClicked(int)));


}

void AudioManager::audioRowButtonClicked(int RowNum)
{

    downloadqueue->insertAudioRowForDownload(audioList[RowNum].getArtist(),
                                             audioList[RowNum].getTitle(),
                                             audioList[RowNum].getId());

}


