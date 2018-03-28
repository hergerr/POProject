#include "addprofessionaldialog.h"
#include "ui_addprofessionaldialog.h"

AddProfessionalDialog::AddProfessionalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProfessionalDialog)
{
    ui->setupUi(this);
}

AddProfessionalDialog::~AddProfessionalDialog()
{
    delete ui;
}
