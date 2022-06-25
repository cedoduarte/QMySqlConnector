
# MySQL Library
INCLUDEPATH += "C:/Program Files/MySQL/MySQL Server 8.0/include"
INCLUDEPATH += "C:/Program Files/MySQL/MySQL Server 8.0/include/mysql"

# MySQL C++ Connector Library
INCLUDEPATH += "C:/Program Files/MySQL/Connector C++ 8.0/include/jdbc"
INCLUDEPATH += "C:/Program Files/MySQL/Connector C++ 8.0/include/jdbc/cppconn"
INCLUDEPATH += "C:/Program Files/MySQL/Connector C++ 8.0/include/mysql"
INCLUDEPATH += "C:/Program Files/MySQL/Connector C++ 8.0/include/mysqlx"
INCLUDEPATH += "C:/Program Files/MySQL/Connector C++ 8.0/include/mysqlx/common"
INCLUDEPATH += "C:/Program Files/MySQL/Connector C++ 8.0/include/mysqlx/devapi"
INCLUDEPATH += "C:/Program Files/MySQL/Connector C++ 8.0/include/mysqlx/devapi/detail"

# MySQL Library
LIBS += -L"C:/Program Files/MySQL/MySQL Server 8.0/bin"
LIBS += -L"C:/Program Files/MySQL/MySQL Server 8.0/lib"
LIBS += -L"C:/Program Files/MySQL/MySQL Server 8.0/lib/plugin"

# MySQL C++ Connector Library
LIBS += -L"C:/Program Files/MySQL/Connector C++ 8.0/lib64"
LIBS += -L"C:/Program Files/MySQL/Connector C++ 8.0/lib64/plugin"
LIBS += -L"C:/Program Files/MySQL/Connector C++ 8.0/lib64/vs14"

# MySQL Library
LIBS += -lfido2
LIBS += -llibprotobuf-lite
LIBS += -llibprotobuf
LIBS += -llibmysql
LIBS += -llibprotobuf-lite
LIBS += -lmysqlclient
LIBS += -lmysqlharness_stdx
LIBS += -lmysqlharness_tls
LIBS += -lmysqlrouter_http
LIBS += -lmysqlrouter_http_auth_backend
LIBS += -lmysqlrouter_http_auth_realm
LIBS += -lmysqlrouter_io_component
LIBS += -lmysqlrouter_lib

# MySQL C++ Connector Library
LIBS += -llibcrypto
LIBS += -llibssl
LIBS += -lmysqlcppconn-static
LIBS += -lmysqlcppconn
LIBS += -lmysqlcppconn8-static
LIBS += -lmysqlcppconn8
