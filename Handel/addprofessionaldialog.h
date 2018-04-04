#ifndef ADDPROFESSIONALDIALOG_H
#define ADDPROFESSIONALDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class AddProfessionalDialog;
}

class AddProfessionalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddProfessionalDialog(QWidget *parent = 0);
    ~AddProfessionalDialog();


private slots:
    void on_comboBoxCounty_currentIndexChanged(int index);

    void on_comboBoxVoivodeship_currentIndexChanged(int index);

    void on_comboBoxCounty_currentIndexChanged(const QString &arg1);

private:
    Ui::AddProfessionalDialog *ui;
};

#endif // ADDPROFESSIONALDIALOG_H
