#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmysqlconnector.h"
#include "mysqlconnectiondialog.h"

#include <QDebug>
#include <QCloseEvent>
#include <QMessageBox>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList labels { "id_emp", "nombre_emp", "login_emp" };
    ui->tableWidget->setColumnCount(labels.size());
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
    m_mysql = new QMySqlConnector(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    m_mysql->close();
    QMainWindow::closeEvent(event);
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
        if (m_mysql->open())
        {
            QMessageBox::information(this, "Connection", "You are connected to MySQL!");
        }
        else
        {
            QMessageBox::critical(this, "Error", "You are not connected to MySQL");
        }
    }
}

void MainWindow::on_actionRead_MySQL_triggered()
{
    if (m_mysql->isConnected())
    {
        m_mysql->query("SELECT * FROM empleados");
        while (m_mysql->next())
        {
            const int row = newRow();
            QTableWidgetItem *itemId = new QTableWidgetItem(QString::number(m_mysql->getInt("id_emp")));
            QTableWidgetItem *itemNombre = new QTableWidgetItem(m_mysql->getString("nombre_emp"));
            QTableWidgetItem *itemLogin = new QTableWidgetItem(m_mysql->getString("login_emp"));
            ui->tableWidget->setItem(row, 0, itemId);
            ui->tableWidget->setItem(row, 1, itemNombre);
            ui->tableWidget->setItem(row, 2, itemLogin);
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "You are not connected to MySQL");
    }
}

int MainWindow::newRow()
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    return row;
}

