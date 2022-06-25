#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QMySqlConnector;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();
private slots:
    void on_actionClose_triggered();
    void on_actionConnect_triggered();
    void on_actionRead_MySQL_triggered();
private:
    int newRow();

    Ui::MainWindow *ui;
    QMySqlConnector *m_mysql;
};

#endif // MAINWINDOW_H
