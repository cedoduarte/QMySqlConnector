#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationDomain("mysql.com");
    a.setOrganizationName("mysql");
    a.setApplicationName("QMySqlConnector");
    a.setApplicationVersion("1.0");
    a.setStyle("fusion");
    MainWindow w;
    w.show();
    return a.exec();
}
