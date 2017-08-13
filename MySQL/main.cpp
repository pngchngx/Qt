#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include "Widget01.h"
#include "Widget02.h"
#include "Widget03.h"
#include "Widget04.h"
#include "Contact.h"
#include "Widget05.h"


// "Driver not loaded Driver not loaded"
// copy libmysql.lib and libmysql.dll in directory D:\Program Files\MySQL\mysql-5.7.17-win32\lib
// paste to directory F:\Qt\Qt5.6.0\5.6\msvc2015\bin
// only copy libmysql.dll also done


// main() for Widget01 and Widget02
#if 0
int main(int argc, char*argv[])
{
    QApplication app(argc, argv);

    //Widget01 w;
    Widget02 w;
    w.show();

    return app.exec();
}
#endif

#if 1
int main(int argc, char*argv[])
{
    QApplication app(argc, argv);

    // QSQLITE QODBC QPLSQL
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //db.setHostName("127.0.0.1");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("116693");
    db.setDatabaseName("dbQt");
    bool bRet = db.open();
    if(bRet == false)
    {
        qDebug() << "error open database" << db.lastError().text();
        exit(0);
    }
    qDebug() << "open database success";

    //Widget03 w;
    //Widget04 w;
    //Contact w;
    Widget05 w;
    w.show();

    return app.exec();
}
#endif
