#ifndef CHOOSEINTERFACE_H
#define CHOOSEINTERFACE_H

#include <QDialog>
#include <QComboBox>

class ChooseInterface : public QDialog
{
    Q_OBJECT
public:
    ChooseInterface();

    QComboBox* _comboBox;
    QString _strSelect;

public slots:
    void slotComboBoxChange(QString);
};

#endif // CHOOSEINTERFACE_H
