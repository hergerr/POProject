#include "chooseprofessionalactiondialog.h"
#include "ui_chooseprofessionalactiondialog.h"

chooseProfessionalActionDialog::chooseProfessionalActionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chooseProfessionalActionDialog)
{
    ui->setupUi(this);
}

chooseProfessionalActionDialog::~chooseProfessionalActionDialog()
{
    delete ui;
}

void chooseProfessionalActionDialog::on_OkpushButton_clicked()
{
    if(ui->addProfessionalRadioButton->isChecked()){
        hide();
//        addProfessionalDialog = new AddProfessionalDialog(this);
//        addProfessionalDialog->show();
    } else if (ui->findProfessionalRadioButton->isChecked()){

    } else if (ui->deleteProfessionalRadioButton->isChecked()){

    } else if (ui->modifyProfessionalRadioButton->isChecked()){

    }
}
