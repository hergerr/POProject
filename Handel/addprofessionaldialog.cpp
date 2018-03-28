#include "addprofessionaldialog.h"
#include "ui_addprofessionaldialog.h"
#include "databasecontroller.h"

AddProfessionalDialog::AddProfessionalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProfessionalDialog)
{
    ui->setupUi(this);
    QSqlQueryModel * modelVoivodeship = new QSqlQueryModel();

    QSqlQueryModel * modelCounty = new QSqlQueryModel();

    QSqlQueryModel * modelCity = new QSqlQueryModel();


    connOpen();
    QSqlQuery * queryVoivodeship = new QSqlQuery(mainDb);
    QSqlQuery * queryCounty = new QSqlQuery(mainDb);
    QSqlQuery * queryCity = new QSqlQuery(mainDb);

    queryVoivodeship->prepare("select wojewodztwo from Wojewodztwa");
    queryVoivodeship->exec();
    queryCounty->prepare("select powiat from Powiaty");
    queryCounty->exec();
    queryCity->prepare("select miasto from Miasta");
    queryCity->exec();

    modelVoivodeship->setQuery(*queryVoivodeship);
    modelCounty->setQuery(*queryCounty);
    modelCity->setQuery(*queryCity);

    ui->comboBoxVoivodeship->setModel(modelVoivodeship);
    ui->comboBoxCounty->setModel(modelCounty);
    ui->comboBoxCity->setModel(modelCity);
    connClose();


    qDebug() << (modelVoivodeship->rowCount());
    qDebug() << (modelCounty->rowCount());
    qDebug() << (modelCity->rowCount());
}

AddProfessionalDialog::~AddProfessionalDialog()
{
    delete ui;
}

