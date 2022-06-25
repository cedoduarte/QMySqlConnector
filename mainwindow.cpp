#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmysqlconnector.h"
#include "mysqlconnectiondialog.h"

#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList labels { "id_emp", "nombre_emp", "login_emp" };
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    m_mysql = new QMySqlConnector(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClose_triggered()
{
    close();
}

void MainWindow::on_actionConnect_triggered()
{
    MySqlConnectionDialog d(this);
    if (d.exec() == QDialog::Accepted)
    {
        m_mysql->setConnectionInfo(d.connectionInfo());
        m_mysql->open();
    }
}

void MainWindow::on_actionRead_MySQL_triggered()
{
    int row = newRow();
    m_mysql->query("SELECT * FROM empleados");
    while (m_mysql->next())
    {
        QTableWidgetItem *itemId = new QTableWidgetItem(QString::number(m_mysql->getInt("id_emp")));
        QTableWidgetItem *itemNombre = new QTableWidgetItem(m_mysql->getString("nombre_emp"));
        QTableWidgetItem *itemLogin = new QTableWidgetItem(m_mysql->getString("login_emp"));
        ui->tableWidget->setItem(row, 0, itemId);
        ui->tableWidget->setItem(row, 1, itemNombre);
        ui->tableWidget->setItem(row, 2, itemLogin);
        row = newRow();
    }
}

int MainWindow::newRow()
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    return row;
}

