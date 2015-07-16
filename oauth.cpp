#include "oauth.h"

void OAuth::check_URL(QUrl url)
{
    url = url.toString().replace("#","?");      // т.к https://vk.com#token=13123123dsgfdgjsdklgj464624244242&id=dasd


    this->token = QUrlQuery(url).queryItemValue("access_token");
    this->user_id =  QUrlQuery(url).queryItemValue("user_id");


    if(this->token.isEmpty())
    {
        qDebug() <<"Error get token(check_URL)";
        return;
    }

    audioManager->setAudioCount(this->requestManager->audioCount(this->getUserId(),this->getToken()));
    emit oauthSuccess();

}

QString OAuth::getToken()
{
    return this->token;
}

QString OAuth::getUserId()
{
    return this->user_id;
}
