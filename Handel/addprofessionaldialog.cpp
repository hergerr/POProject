#include "addprofessionaldialog.h"
#include "ui_addprofessionaldialog.h"

AddProfessionalDialog::AddProfessionalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProfessionalDialog)
{
    ui->setupUi(this);
    QSqlQueryModel * model = new QSqlQueryModel();

    connOpen();
    QSqlQuery * query = new QSqlQuery(mainDb);

    query->prepare("select wojewodztwo from Wojewodztwa");
    query->exec();
    model->setQuery(*query);
    ui->comboBoxVoivodeship->setModel(model);
    connClose();
    qDebug() << (model->rowCount());
}

AddProfessionalDialog::~AddProfessionalDialog()
{
    delete ui;
}

