#include "Widget02.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>

Widget02::Widget02(QWidget *parent) : QWidget(parent)
{
    // QSQLITE QODBC QPLSQL
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    //db.setHostName("localhost");
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

    // QSqlTableModel: 数据表对应的数据结构
    QSqlTableModel model;
    model.setTable("tableQt");
    //model.setFilter("username<>'newuser'");
    //model.setFilter("username='newuser'");

    model.select();  // exec query

    int ret = model.rowCount();
    // read data from database
    for(int i=0; i<ret; ++i)
    {
       QSqlRecord record = model.record(i);
       for(int j=0; j<record.count(); j++)
       {
           qDebug() << record.value(j);
       }
    }

    qDebug() << model.data(model.index(0,2));
    // update data to database
//    bool setData(const QModelIndex &index,
//                 const QVariant &value,
//                 int role = Qt::EditRole) Q_DECL_OVERRIDE;
    model.setData(model.index(0, 2), "home");
    model.submitAll();
    qDebug() << model.data(model.index(0,2));

    // insert data to database
    QSqlRecord record = model.record();
    // record.setValue("id", ); // self increase
    record.setValue("id", 5);
    record.setValue("username", "king");
    record.setValue("password", "land");
    record.setValue("gender", 1);
    model.insertRecord(-1, record);
    model.submitAll();

}
