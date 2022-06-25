#ifndef QMYSQLCONNECTIONINFO_H
#define QMYSQLCONNECTIONINFO_H

#include <QString>

class QMySqlConnectionInfo
{
    friend class QMySqlConnector;
public:
    explicit QMySqlConnectionInfo();
    virtual ~QMySqlConnectionInfo();

    void setPort(int port)
    {
        m_port = port;
    }

    void setHostName(const QString &hostname)
    {
        m_hostName = hostname;
    }

    void setDatabaseName(const QString &databasename)
    {
        m_databaseName = databasename;
    }

    void setUserName(const QString &username)
    {
        m_userName = username;
    }

    void setPassword(const QString &password)
    {
        m_password = password;
    }

    int port() const
    {
        return m_port;
    }

    QString hostName() const
    {
        return m_hostName;
    }

    QString databaseName() const
    {
        return m_databaseName;
    }

    QString userName() const
    {
        return m_userName;
    }

    QString password() const
    {
        return m_password;
    }
private:
    int m_port;
    QString m_hostName;
    QString m_databaseName;
    QString m_userName;
    QString m_password;
};

#endif // QMYSQLCONNECTIONINFO_H
