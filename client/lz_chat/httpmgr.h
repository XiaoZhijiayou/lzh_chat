#ifndef HTTPMGR_H
#define HTTPMGR_H

#include "singleton.h"
#include <QString>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>

//CRTP
class HttpMgr : public QObject, public Singleton<HttpMgr>
    , public std::enable_shared_from_this<HttpMgr>
{
    Q_OBJECT
public:
    /// 为何要将这个析构置为public，就是因为在Singleton析构的时候会调用shared_ptr的析构，
    /// 然后里面再继续调用HttpMgr的析构
    /// 因此需要置为public
    ~HttpMgr();

    void PostHttpReq(QUrl url,QJsonObject json, ReqId req_id, Modules mod);
private:
    ///这里为了让其Singleton<HttpMgr>能够new，将这个构造函数声明成为有元
    friend class Singleton<HttpMgr>;
    HttpMgr();

    /// QT原生的网络管理者
    QNetworkAccessManager _manager;

private slots:
    /// http的信号槽
    void slot_http_finish(ReqId id, QString res,ErrorCodes err,Modules mod);
signals:
    /// http完成信号
    void sig_http_finish(ReqId id, QString res,ErrorCodes err,Modules mod);
    /// 注册信号
    void sig_reg_mod_finish(ReqId id, QString res,ErrorCodes err);

    void sig_reset_mod_finish(ReqId id, QString res, ErrorCodes err);

    void sig_login_mod_finish(ReqId id, QString res, ErrorCodes err);
};

#endif // HTTPMGR_H
