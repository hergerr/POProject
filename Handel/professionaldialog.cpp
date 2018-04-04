#include "professionaldialog.h"
#include "ui_professionaldialog.h"

ProfessionalDialog::ProfessionalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfessionalDialog)
{
    ui->setupUi(this);

    LoginWindow connection;

    QSqlQueryModel * modelVoivodeship = new QSqlQueryModel();

    QSqlQueryModel * modelCounty = new QSqlQueryModel();

    QSqlQueryModel * modelCity = new QSqlQueryModel();


//     connection.connOpen();
//   QSqlQuery * queryVoivodeship = new QSqlQuery(mainDb);
//   QSqlQuery * queryCounty = new QSqlQuery(mainDb);
//   QSqlQuery * queryCity = new QSqlQuery(mainDb);

//   queryVoivodeship->prepare("select wojewodztwo from Wojewodztwa");
//   queryVoivodeship->exec();
//   queryCounty->prepare("select powiat from Powiaty");
//   queryCounty->exec();
//   queryCity->prepare("select miasto from Miasta");
//   queryCity->exec();

//   modelVoivodeship->setQuery(*queryVoivodeship);
//   modelCounty->setQuery(*queryCounty);
//   modelCity->setQuery(*queryCity);

//   ui->voivodeshipComboBox->setModel(modelVoivodeship);
//   ui->countyComboBox->setModel(modelCounty);
//   ui->cityComboBox->setModel(modelCity);
//   connection.connClose();


//   qDebug() << (modelVoivodeship->rowCount());
//   qDebug() << (modelCounty->rowCount());
//   qDebug() << (modelCity->rowCount());
}

ProfessionalDialog::~ProfessionalDialog()
{
    delete ui;
}

void ProfessionalDialog::on_addPushButton_clicked()
{
    LoginWindow connection;

    QString name = ui->nameLineEdit->text();
    QString companyName = ui->companyNameLineEdit->text();
    QString companyType = ui->companyTypeLineEdit->text();
    QString phoneNumber = ui->phoneLineEdit->text();
    QString email = ui->emailLineEdit->text();

    connection.connOpen();
    QSqlQuery query;
    query.prepare("insert into Professionals  (name, company_name, company_type, phone_number, email) values ('"+name+"','"+companyName+"','"+companyType+"','"+phoneNumber+"','"+email+"')");

   if(query.exec()){
        QMessageBox::critical(this, "Komunikat", "Zapisano");
        connection.connClose();
    } else {
        QMessageBox::critical(this, "ERROR", "Nie zapisano");
    }

}
