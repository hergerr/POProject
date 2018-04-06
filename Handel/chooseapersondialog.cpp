#include "chooseapersondialog.h"
#include "ui_chooseapersondialog.h"
#include <QMessageBox>

ChooseAPersonDialog::ChooseAPersonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseAPersonDialog)
{
    ui->setupUi(this);
}

ChooseAPersonDialog::~ChooseAPersonDialog()
{
    delete ui;
}

void ChooseAPersonDialog::on_okPushButton_clicked()
{
    if(ui->professionalRadioButton->isChecked()){
       hide();
       professionalDialog = new ProfessionalDialog(this);
       professionalDialog->show();
    } else {
        hide();
        traderDialog = new TraderDialog(this);
        traderDialog->show();
    }
}
