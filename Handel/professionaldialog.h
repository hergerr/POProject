#ifndef PROFESSIONALDIALOG_H
#define PROFESSIONALDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include "loginwindow.h"

namespace Ui {
class ProfessionalDialog;
}

class ProfessionalDialog : public QDialog
{
    Q_OBJECT


public:
    explicit ProfessionalDialog(QWidget *parent = 0);
    ~ProfessionalDialog();

private slots:
    void on_addPushButton_clicked();

private:
    Ui::ProfessionalDialog *ui;
};

#endif // PROFESSIONALDIALOG_H
