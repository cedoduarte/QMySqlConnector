#include "mysqlconnectiondialog.h"
#include "ui_mysqlconnectiondialog.h"

MySqlConnectionDialog::MySqlConnectionDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MySqlConnectionDialog)
{
    ui->setupUi(this);
    ui->txtHost->setText("127.0.0.1");
    ui->txtUsername->setText("root");
    ui->spinnerPort->setRange(0, std::numeric_limits<int>::max());
    ui->spinnerPort->setValue(3306);
}

MySqlConnectionDialog::~MySqlConnectionDialog()
{
    delete ui;
}

void MySqlConnectionDialog::on_buttonBox_accepted()
{
    m_conInfo.setDatabaseName(ui->txtDatabaseName->text());
    m_conInfo.setHostName(ui->txtHost->text());
    m_conInfo.setPassword(ui->txtPassword->text());
    m_conInfo.setPort(ui->spinnerPort->value());
    m_conInfo.setUserName(ui->txtUsername->text());
    accept();
}

void MySqlConnectionDialog::on_buttonBox_rejected()
{
    reject();
}

