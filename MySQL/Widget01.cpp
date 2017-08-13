#include "Widget01.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlResult>


Widget01::Widget01(QWidget *parent) : QWidget(parent)
{
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

    db.exec("insert into tableQt (id, username, password, gender) values(5, 'king', 'land', 1)");
#if 0
    QSqlQuery query = db.exec("select * from tableQt");
    bool b = query.first();
    while(b)
    {
        const QSqlResult* result = query.result();
        // failed here: QSqlResult::boundValues() protected member
        QVector<QVariant> values =  result->boundValues();
        qDebug() << values;
        b = query.next();
    }
#endif
}
