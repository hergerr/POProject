#ifndef PROFESSIONALDIALOG_H
#define PROFESSIONALDIALOG_H

#include <QDialog>

namespace Ui {
class ProfessionalDialog;
}

class ProfessionalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProfessionalDialog(QWidget *parent = 0);
    ~ProfessionalDialog();

private:
    Ui::ProfessionalDialog *ui;
};

#endif // PROFESSIONALDIALOG_H
