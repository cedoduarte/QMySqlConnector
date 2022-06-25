#ifndef QMYSQLCONNECTOR_H
#define QMYSQLCONNECTOR_H

#include "qmysqlconnectioninfo.h"

#include <QDate>
#include <QObject>
#include <cppconn/driver.h>
#include <mysql_connection.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class QMySqlConnector : public QObject
{
    Q_OBJECT
public:
    explicit QMySqlConnector(QObject *parent = nullptr);
    virtual ~QMySqlConnector();
    bool open();
    bool close();
    void query(const QString &sqlquery);
    bool next();
    int getInt(int columnIndex) const;
    int getInt(const QString &columnName) const;
    qint64 getInt64(int columnIndex) const;
    qint64 getInt64(const QString &columnName) const;
    quint32 getUInt(int columnIndex) const;
    quint32 getUInt(const QString &columnName) const;
    quint64 getUInt64(int columnIndex) const;
    quint64 getUInt64(const QString &columnName) const;
    double getDouble(int columnIndex) const;
    double getDouble (const QString &columnName) const;
    float getFloat(int columnIndex) const;
    float getFloat(const QString &columnName) const;
    bool getBoolean(int columnIndex) const;
    bool getBoolean(const QString &columnName) const;
    QString getString(int columnIndex) const;
    QString getString(const QString &columnName) const;
    QDate getDate(int columnIndex) const;
    QDate getDate(const QString &columnName) const;
    //m_res->getBlob();

    void setConnectionInfo(const QMySqlConnectionInfo &conInfo)
    {
        m_conInfo = conInfo;
    }

    bool isConnected() const
    {
        return m_connected;
    }
private:
    QMySqlConnectionInfo m_conInfo;
    sql::Driver *m_driver;
    sql::Connection *m_con;
    sql::Statement *m_stmt;
    sql::ResultSet *m_res;
    bool m_connected;
};

#endif // QMYSQLCONNECTOR_H
