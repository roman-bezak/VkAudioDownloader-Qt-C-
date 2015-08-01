#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QtNetwork>
#include <QDebug>
#include "downloader.h"
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QJsonDocument>
#include <QObject>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSignalMapper>

#include "ui_audiomanager.h"



MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    oauth = new OAuth();
    oauth->audioManager->show();
    //downloader = new Downloader();


    this->showStartPage();

    QObject::connect(ui->webView,SIGNAL(urlChanged(QUrl)),oauth,SLOT(check_URL(QUrl)));//изменение урла страницы сохранит токен в oauth.token
    QObject::connect(this->oauth,SIGNAL(oauthSuccess()),this,SLOT(afterSuccessOaouth()));

//    QObject::connect(oauth->audioManager,SIGNAL(sendTrackListToDownloadThread(QList<Track>)),
//            oauth->audioManager->downloadqueue->downloadthread,
//            SLOT(updateTrackList(QList<Track>)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showStartPage()
{
    ui->webView->load(QUrl("https://oauth.vk.com/authorize?client_id=4744269&scope=offline,audio&redirect_uri=https://oauth.vk.com/blank.html&display=mobile&v=5.34&response_type=token"));
}

void MainWindow::afterSuccessOaouth()
{
    //уже получен токен и аудио каунт


    this->oauth->requestManager->audioGet(oauth->getUserId(),oauth->getToken(),oauth->audioManager->getAudioCount(),oauth->audioManager->audioList);



    //this->hide();
    oauth->audioManager->initTable();
    oauth->audioManager->show();


}

void MainWindow::on_pushButton_clicked()
{

       //this->oauth->requestManager->audioGet(oauth->getUserId(),oauth->getToken(),oauth->audioManager->getAudioCount(),oauth->audioManager->audioList);
       qDebug() << "END";

        this->oauth->audioManager->ui->tableWidget->setRowCount(this->oauth->audioManager->audioList.size());

//       QSignalMapper mapper;

//       //QWidget *pWidget = new QWidget();
//       QPushButton *pButton = new QPushButton("Download",this);
//       oauth->audioManager->ui->tableWidget->setCellWidget(0,4,pButton);

//       connect(pButton, SIGNAL(clicked()), &mapper, SLOT(map()));
//       mapper.setMapping(pButton, 0);
//       connect(&mapper, SIGNAL(mapped(int)), oauth->audioManager, SLOT(CellButtonClicked(int)));


       //QHBoxLayout *pLayout = new QHBoxLayout(pWidget);
       //pLayout->addWidget(pButton);
       //pLayout->setAlignment(Qt::AlignCenter);
       //pLayout->setContentsMargins(0,0,0,0);
       //pWidget->setLayout(pLayout);








           for(int i = 0; i < this->oauth->audioManager->audioList.size(); i++)
               {
                  oauth->audioManager->ui->tableWidget->setItem(i, 1, new QTableWidgetItem("      "+this->oauth->audioManager->audioList[i].getArtist()));
                  oauth->audioManager->ui->tableWidget->setItem(i, 2, new QTableWidgetItem(this->oauth->audioManager->audioList[i].getTitle()));
                  oauth->audioManager->ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(this->oauth->audioManager->audioList[i].getDuration())));
                  oauth->audioManager->ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(this->oauth->audioManager->audioList[i].getId())));
               }


//    Downloader * downloader;
//    qDebug() <<sizeof(downloader);
//    downloader = new Downloader();
//    qDebug() <<sizeof(downloader);
//    QFile localFile("E:/downloadedfile.mp3");
//      if (!localFile.open(QIODevice::WriteOnly))qDebug() << "Vse huna!!!" ;

//    localFile.write(downloader->Do_Download("http:\/\/cs5831.vk.me\/u17513964\/audios\/3284dc6b25e4.mp3?extra=rWbwZya8QtrBS00FrSlaNgC6hBH8IojA29wnRFP-uGx3CI7MF_pCRG9OD8d48LnRze14ROtls-WFPzpxmA4z4KXS1eicKyhA4g"));
//    localFile.close();

//    qDebug() << "END";

//    delete downloader;

}

void MainWindow::on_pushButton_2_clicked()
{

    oauth->audioManager->downloadqueue->downloaderInThread->showSIZE();
}


