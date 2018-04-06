#ifndef CHOOSEAPERSONDIALOG_H
#define CHOOSEAPERSONDIALOG_H

#include <QDialog>
#include "professionaldialog.h"
#include "traderdialog.h"

namespace Ui {
class ChooseAPersonDialog;
}

class ProfessionalDialog;
class TraderDialog;

class ChooseAPersonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseAPersonDialog(QWidget *parent = 0);
    ~ChooseAPersonDialog();

private slots:
    void on_okPushButton_clicked();

private:
    Ui::ChooseAPersonDialog *ui;
    ProfessionalDialog *professionalDialog;
    TraderDialog *traderDialog;
};

#endif // CHOOSEAPERSONDIALOG_H
