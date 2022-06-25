#include "qmysqlconnector.h"

#include <QDebug>

QMySqlConnector::QMySqlConnector(QObject *parent)
    : QObject(parent)
{
    m_driver = nullptr;
    m_con = nullptr;
    m_stmt = nullptr;
    m_res = nullptr;
    m_connected = false;
}

QMySqlConnector::~QMySqlConnector()
{
    // nothing to do here
}

bool QMySqlConnector::open()
{
    try
    {
        m_driver = get_driver_instance();
        QString hostAndPort = QString("tcp://%1:%2").arg(m_conInfo.m_hostName).arg(m_conInfo.m_port);
        m_con = m_driver->connect(sql::SQLString(hostAndPort.toStdString()),
                                  sql::SQLString(m_conInfo.m_userName.toStdString()),
                                  sql::SQLString(m_conInfo.m_password.toStdString()));
        m_con->setSchema(sql::SQLString(m_conInfo.m_databaseName.toStdString()));
        m_stmt = m_con->createStatement();
        m_connected = true;
    }
    catch (sql::SQLException &e)
    {
        qDebug() << e.what() << __FILE__ << __LINE__;
        qDebug() << e.getErrorCode() << __FILE__ << __LINE__;
        qDebug() << e.getSQLState().c_str() << __FILE__ << __LINE__;
        m_connected = false;
    }
    return m_connected;
}

bool QMySqlConnector::close()
{
    try
    {
        m_con->close();
        delete m_con;
        m_con = nullptr;
        m_driver->threadEnd();
        m_connected = false;
        return true;
    }
    catch (sql::SQLException &e)
    {
        qDebug() << e.what() << __FILE__ << __LINE__;
        return false;
    }
    return false;
}

void QMySqlConnector::query(const QString &sqlquery)
{
    try
    {
        m_res = m_stmt->executeQuery(sql::SQLString(sqlquery.toStdString()));
    }
    catch (sql::SQLException &e)
    {
        qDebug() << e.what() << __FILE__ << __LINE__;
        qDebug() << e.getErrorCode() << __FILE__ << __LINE__;
        qDebug() << e.getSQLState().c_str() << __FILE__ << __LINE__;
    }
}

bool QMySqlConnector::next()
{
    try
    {
        return m_res->next();
    }
    catch (sql::SQLException &e)
    {
        qDebug() << e.what() << __FILE__ << __LINE__;
        qDebug() << e.getErrorCode() << __FILE__ << __LINE__;
        qDebug() << e.getSQLState().c_str() << __FILE__ << __LINE__;
    }
    return false;
}

int QMySqlConnector::getInt(int columnIndex) const
{
    return m_res->getInt(columnIndex + 1);
}

int QMySqlConnector::getInt(const QString &columnName) const
{
    return m_res->getInt(sql::SQLString(columnName.toStdString()));
}

qint64 QMySqlConnector::getInt64(int columnIndex) const
{
    return m_res->getInt64(columnIndex + 1);
}

qint64 QMySqlConnector::getInt64(const QString &columnName) const
{
    return m_res->getInt64(sql::SQLString(columnName.toStdString()));
}

quint32 QMySqlConnector::getUInt(int columnIndex) const
{
    return m_res->getUInt(columnIndex + 1);
}

quint32 QMySqlConnector::getUInt(const QString &columnName) const
{
    return m_res->getUInt(sql::SQLString(columnName.toStdString()));
}

quint64 QMySqlConnector::getUInt64(int columnIndex) const
{
    return m_res->getUInt64(columnIndex + 1);
}

quint64 QMySqlConnector::getUInt64(const QString &columnName) const
{
    return m_res->getUInt64(sql::SQLString(columnName.toStdString()));
}

double QMySqlConnector::getDouble(int columnIndex) const
{
    return m_res->getDouble(columnIndex + 1);
}

double QMySqlConnector::getDouble (const QString &columnName) const
{
    return m_res->getDouble(sql::SQLString(columnName.toStdString()));
}

float QMySqlConnector::getFloat(int columnIndex) const
{
    return float(getDouble(columnIndex));
}

float QMySqlConnector::getFloat(const QString &columnName) const
{
    return float(getDouble(columnName));
}

bool QMySqlConnector::getBoolean(int columnIndex) const
{
    return m_res->getBoolean(columnIndex + 1);
}

bool QMySqlConnector::getBoolean(const QString &columnName) const
{
    return m_res->getBoolean(sql::SQLString(columnName.toStdString()));
}

QString QMySqlConnector::getString(int columnIndex) const
{
    return QString::fromStdString(m_res->getString(columnIndex + 1));
}

QString QMySqlConnector::getString(const QString &columnName) const
{
    return QString::fromStdString(m_res->getString(sql::SQLString(columnName.toStdString())));
}

QDate QMySqlConnector::getDate(int columnIndex) const
{
    return QDate::fromString(QString::fromStdString(m_res->getString(columnIndex + 1)));
}

QDate QMySqlConnector::getDate(const QString &columnName) const
{
    return QDate::fromString(QString::fromStdString(m_res->getString(sql::SQLString(columnName.toStdString()))));
}
