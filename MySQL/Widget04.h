#ifndef WIDGET04_H
#define WIDGET04_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTableView> // show table
// MVC是模型(model)－视图(view)－控制器(controller)的缩写

#include <QItemDelegate>
#include <QComboBox>

// declaration
class MyTableModel;
class Widget04 : public QWidget
{
    Q_OBJECT
public:
    explicit Widget04(QWidget *parent = 0);

    //QSqlTableModel* _model;
    MyTableModel* _model;
    QTableView* _view;

signals:

public slots:
    void slotSubmitClicked();
    void slotDelClicked();
    void slotAddClicked();

};

#endif // WIDGET04_H


class GenderDelegate : public QItemDelegate
{
public:
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &,
                          const QModelIndex &) const
    {
        QComboBox*  combo = new QComboBox(parent);
        QString m = QString::fromLocal8Bit("男");
        QString f = QString::fromLocal8Bit("女");
        combo->addItem(m);
        combo->addItem(f);
        return combo;
    }
};

class MyTableModel : public QSqlTableModel
{
public:
    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const
    {
        if(idx.column() != 3)
            return QSqlTableModel::data(idx, role);

        QVariant var = QSqlTableModel::data(idx, role);
        QString m = QString::fromLocal8Bit("男");
        QString f = QString::fromLocal8Bit("女");
        if(var == 0)
        {
            return f;
        }
        else
            return m;
    }

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole)
    {
        if(index.column() != 3)
            return QSqlTableModel::setData(index, value, role);

        QString m = QString::fromLocal8Bit("男");
        QString f = QString::fromLocal8Bit("女");
        if(value == m)
            return QSqlTableModel::setData(index, 1, role);
        else
            return QSqlTableModel::setData(index, 0, role);
    }
};

class ReadOnlyDelegate : public QItemDelegate
{
    QWidget *createEditor(QWidget *,
                          const QStyleOptionViewItem &,
                          const QModelIndex &) const
    {
        return NULL;
    }
};

// combine GenderDelegate and ReadOnlyDelegate
class TUserDelegate : public QItemDelegate
{
    QWidget *createEditor(QWidget * parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
    {
        if(index.column() == 0)
            return NULL;
        if(index.column() == 3)
        {
            QComboBox*  combo = new QComboBox(parent);
            QString m = QString::fromLocal8Bit("男");
            QString f = QString::fromLocal8Bit("女");
            combo->addItem(m);
            combo->addItem(f);
            return combo;
        }

        return QItemDelegate::createEditor(parent, option, index);
    }
};
