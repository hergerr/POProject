#ifndef ADDPROFESSIONALDIALOG_H
#define ADDPROFESSIONALDIALOG_H

#include <QMainWindow>
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

private:
    Ui::AddProfessionalDialog *ui;
};

#endif // ADDPROFESSIONALDIALOG_H
