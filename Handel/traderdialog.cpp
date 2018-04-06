#include "traderdialog.h"
#include "ui_traderdialog.h"

TraderDialog::TraderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TraderDialog)
{
    ui->setupUi(this);
}

TraderDialog::~TraderDialog()
{
    delete ui;
}
