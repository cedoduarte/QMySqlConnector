#include "mysqlconnectiondialog.h"
#include "ui_mysqlconnectiondialog.h"

#include <QSettings>

MySqlConnectionDialog::MySqlConnectionDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MySqlConnectionDialog)
{
    ui->setupUi(this);
    ui->spinnerPort->setRange(0, std::numeric_limits<int>::max());
    ui->spinnerPort->setValue(3306);
    loadSettings();
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

void MySqlConnectionDialog::on_txtHost_textEdited(const QString &txt)
{
    QSettings settings;
    settings.beginGroup("settings");
    settings.setValue("txtHost", txt);
    settings.endGroup();
}

void MySqlConnectionDialog::on_txtDatabaseName_textEdited(const QString &txt)
{
    QSettings settings;
    settings.beginGroup("settings");
    settings.setValue("txtDatabaseName", txt);
    settings.endGroup();
}

void MySqlConnectionDialog::on_txtUsername_textEdited(const QString &txt)
{
    QSettings settings;
    settings.beginGroup("settings");
    settings.setValue("txtUsername", txt);
    settings.endGroup();
}

void MySqlConnectionDialog::on_txtPassword_textEdited(const QString &txt)
{
    QSettings settings;
    settings.beginGroup("settings");
    settings.setValue("txtPassword", txt);
    settings.endGroup();
}

void MySqlConnectionDialog::on_spinnerPort_valueChanged(int value)
{
    QSettings settings;
    settings.beginGroup("settings");
    settings.setValue("spinnerPort", value);
    settings.endGroup();
}

void MySqlConnectionDialog::loadSettings()
{
    QSettings settings;
    settings.beginGroup("settings");
    ui->txtDatabaseName->setText(settings.value("txtDatabaseName", "almacen").toString());
    ui->txtHost->setText(settings.value("txtHost", "127.0.0.1").toString());
    ui->txtPassword->setText(settings.value("txtPassword", "root").toString());
    ui->txtUsername->setText(settings.value("txtUsername", "root").toString());
    ui->spinnerPort->setValue(settings.value("spinnerPort", 3306).toInt());
    settings.endGroup();
}

