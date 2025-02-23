#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resetdialog.h"
#include "chatdialog.h"
#include "tcpmgr.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _login_dig = new LoginDialog(this);
    _login_dig->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    setCentralWidget(_login_dig);
    // _login_dig->show();

    /// 创建和注册消息链接
    connect(_login_dig, &LoginDialog::switchRegister, this,&MainWindow::SlotSwtichReg);
    //连接登录界面忘记密码信号
    connect(_login_dig, &LoginDialog::switchReset, this, &MainWindow::SlotSwitchReset);
    //连接创建聊天界面信号
    connect(TcpMgr::GetInstance().get(),&TcpMgr::sig_swich_chatdlg, this, &MainWindow::SlotSwitchChat);

    // emit  TcpMgr::GetInstance()->sig_swich_chatdlg();
}


MainWindow::~MainWindow()
{
    delete ui;
    // if(_login_dig){
    //     delete _login_dig;
    //     _login_dig = nullptr;
    // }
    // if(_reg_dig){
    //     delete _reg_dig;
    //     _reg_dig = nullptr;
    // }
}

void MainWindow::SlotSwtichReg(){

    _reg_dig = new RegisterDialog(this);


    _reg_dig->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);

    //连接注册界面返回登录信号
    connect(_reg_dig, &RegisterDialog::sigSwitchLogin, this, &MainWindow::SlotSwitchLogin);

    setCentralWidget(_reg_dig);
    _login_dig->hide();
    _reg_dig->show();
}

void MainWindow::SlotSwitchLogin()
{
    //创建一个CentralWidget, 并将其设置为MainWindow的中心部件
     _login_dig = new LoginDialog(this);
    _login_dig->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(_login_dig);
    _reg_dig->hide();
    _login_dig->show();
    //连接登录界面注册信号
    connect(_login_dig, &LoginDialog::switchRegister, this, &MainWindow::SlotSwtichReg);
    //连接登录界面忘记密码信号
    connect(_login_dig, &LoginDialog::switchReset, this, &MainWindow::SlotSwitchReset);
}

void MainWindow::SlotSwitchReset()
{
    //创建一个CentralWidget, 并将其设置为MainWindow的中心部件
    _reset_dlg = new ResetDialog(this);
    _reset_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(_reset_dlg);
    _login_dig->hide();
    _reset_dlg->show();
    //注册返回登录信号和槽函数
    connect(_reset_dlg, &ResetDialog::switchLogin, this, &MainWindow::SlotSwitchLogin2);
    //连接创建聊天界面信号
    connect(TcpMgr::GetInstance().get(),&TcpMgr::sig_swich_chatdlg, this, &MainWindow::SlotSwitchChat);
}

void MainWindow::SlotSwitchLogin2()
{
    //创建一个CentralWidget, 并将其设置为MainWindow的中心部件
    _login_dig = new LoginDialog(this);
    _login_dig->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(_login_dig);
    _reset_dlg->hide();
    _login_dig->show();
    //连接登录界面忘记密码信号
    connect(_login_dig, &LoginDialog::switchReset, this, &MainWindow::SlotSwitchReset);
    //连接登录界面注册信号
    connect(_login_dig, &LoginDialog::switchRegister, this, &MainWindow::SlotSwtichReg);
}

void MainWindow::SlotSwitchChat()
{
    _chat_dlg = new ChatDialog();
    _chat_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(_chat_dlg);
    _chat_dlg->show();
    _login_dig->hide();
    this->setMinimumSize(QSize(1050,900));
    this->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
}
