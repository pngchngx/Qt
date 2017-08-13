#ifndef WIDGET03_H
#define WIDGET03_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTableView> // show table
// MVC是模型(model)－视图(view)－控制器(controller)的缩写

class Widget03 : public QWidget
{
    Q_OBJECT
public:
    explicit Widget03(QWidget *parent = 0);

    QSqlTableModel* _model;
    QTableView* _view;

signals:

public slots:
    void slotSubmitClicked();
    void slotDelClicked();
    void slotAddClicked();

};

#endif // WIDGET03_H
