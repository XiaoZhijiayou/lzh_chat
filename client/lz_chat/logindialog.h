/******************************************************************************
 *
 * @file       logindialog.h
 * @brief      登录窗口
 *
 * @author     zhihao li
 * @date       2025/01/08
 * @history
 *****************************************************************************/
#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "global.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private:
    void initHttpHandlers();
    void initHead();
    Ui::LoginDialog *ui;
    void showTip(QString str,bool b_ok);
    bool checkUserValid();
    bool checkPwdValid();
    QMap<ReqId, std::function<void(const QJsonObject&)>> _handlers;
    bool enableBtn(bool);
    void AddTipErr(TipErr te, QString tips);
    void DelTipErr(TipErr te);
    QMap<TipErr, QString> _tip_errs;
    int _uid;
    QString _token;

signals:
    void switchRegister();
    void switchReset();
    void sig_connect_tcp(ServerInfo);

private slots:
    void slot_forget_pwd();
    void on_login_btn_clicked();
    void slot_login_mod_finish(ReqId id, QString res, ErrorCodes err);
    void slot_tcp_con_finish(bool bsuccess);
    void slot_login_failed(int);
};

#endif // LOGINDIALOG_H
