#ifndef MYSQLCONNECTIONDIALOG_H
#define MYSQLCONNECTIONDIALOG_H

#include "qmysqlconnectioninfo.h"

#include <QDialog>

namespace Ui
{
class MySqlConnectionDialog;
}

class MySqlConnectionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MySqlConnectionDialog(QWidget *parent = nullptr);
    virtual ~MySqlConnectionDialog();

    QMySqlConnectionInfo connectionInfo() const
    {
        return m_conInfo;
    }
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
private:
    Ui::MySqlConnectionDialog *ui;
    QMySqlConnectionInfo m_conInfo;
};

#endif // MYSQLCONNECTIONDIALOG_H
