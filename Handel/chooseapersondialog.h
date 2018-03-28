#ifndef CHOOSEAPERSONDIALOG_H
#define CHOOSEAPERSONDIALOG_H

#include <QDialog>
#include "chooseprofessionalactiondialog.h"

namespace Ui {
class ChooseAPersonDialog;
}

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
    chooseProfessionalActionDialog *chooseProfessionalAction;
};

#endif // CHOOSEAPERSONDIALOG_H
