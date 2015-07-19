#include "downloadthread.h"



DownloadThread::DownloadThread()
{

}


void DownloadThread::run()
{
   while(true)
   {
       qDebug() <<downloadTrackList.size();
       msleep(1000);
   }
}
