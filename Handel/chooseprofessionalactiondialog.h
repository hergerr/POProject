#ifndef CHOOSEPROFESSIONALACTIONDIALOG_H
#define CHOOSEPROFESSIONALACTIONDIALOG_H

#include <QDialog>
#include "addprofessionaldialog.h"

namespace Ui {
class chooseProfessionalActionDialog;
}

class chooseProfessionalActionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit chooseProfessionalActionDialog(QWidget *parent = 0);
    ~chooseProfessionalActionDialog();

private slots:
    void on_OkpushButton_clicked();

private:
    Ui::chooseProfessionalActionDialog *ui;
    AddProfessionalDialog *addProfessionalDialog;
};

#endif // CHOOSEPROFESSIONALACTIONDIALOG_H
