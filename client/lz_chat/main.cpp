#include "mainwindow.h"
#include "global.h"
#include <QApplication>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qss(":/style/stylesheet.qss");

    if(qss.open(QFile::ReadOnly)){
        qDebug("Open success");
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }else{
        qDebug("Open fail;");
    }

    QString fileName = "config.ini";
    QString app_path = QCoreApplication::applicationDirPath();
    QString config_path = QDir::toNativeSeparators(app_path +
                                                   QDir::separator() + fileName);
    QSettings settings(config_path,QSettings::IniFormat);
    QString gate_host = settings.value("GateServer/host").toString();
    QString gate_post = settings.value("GateServer/port").toString();
    gate_url_prefix = "http://" + gate_host + ":" + gate_post;


    MainWindow w;
    w.show();
    return a.exec();
}
