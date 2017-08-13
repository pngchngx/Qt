#include "Widget05.h"
#include <QVBoxLayout>
#include <QSqlQuery>

Widget05::Widget05(QWidget *parent) : QWidget(parent)
{
    _model = new QSqlQueryModel;
    _view = new QTableView(this);
    _view->setModel(_model);

    _model->setQuery("select * from tableQt");
    _model->query();

    QVBoxLayout* lay = new QVBoxLayout(this);
    lay->addWidget(_view);
}
