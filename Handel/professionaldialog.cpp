#include "professionaldialog.h"
#include "ui_professionaldialog.h"

ProfessionalDialog::ProfessionalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfessionalDialog)
{
    ui->setupUi(this);

    LoginWindow connection;
    QSqlQueryModel * modelVoivodeship = new QSqlQueryModel();
    connection.connOpen();
    QSqlQuery * queryVoivodeship = new QSqlQuery(connection.mainDb);
    queryVoivodeship->prepare("select wojewodztwo from Wojewodztwa");
    queryVoivodeship->exec();
    modelVoivodeship->setQuery(*queryVoivodeship);
    ui->voivodeshipComboBox->setModel(modelVoivodeship);
    ui->voivodeshipComboBox->setCurrentIndex(-1);
    qDebug() << (modelVoivodeship->rowCount());

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
        QMessageBox::information(this, "Komunikat", "Zapisano");
        connection.connClose();
    } else {
        QMessageBox::information(this, "ERROR", "Nie zapisano");
    }

}

void ProfessionalDialog::on_modifyPushButton_clicked()
{
    LoginWindow connection;

    QString name = ui->nameLineEdit->text();
    QString companyName = ui->companyNameLineEdit->text();
    QString companyType = ui->companyTypeLineEdit->text();
    QString phoneNumber = ui->phoneLineEdit->text();
    QString email = ui->emailLineEdit->text();

    connection.connOpen();
    QSqlQuery query;
    query.prepare("update Professionals set name = '"+name+"',company_name = '"+companyName+"', company_type = '"+companyType+"', phone_number = '"+phoneNumber+"', email = '"+email+"' where phone_number = '"+phoneNumber+"'");

   if(query.exec()){
        QMessageBox::information(this, "Komunikat", "Zmieniono");
        connection.connClose();
    } else {
        QMessageBox::information(this, "ERROR", "Nie zmieniono");
    }
}

void ProfessionalDialog::on_deletePushButton_clicked()
{
    LoginWindow connection;

    QString name = ui->nameLineEdit->text();
    QString companyName = ui->companyNameLineEdit->text();
    QString companyType = ui->companyTypeLineEdit->text();
    QString phoneNumber = ui->phoneLineEdit->text();
    QString email = ui->emailLineEdit->text();

    connection.connOpen();
    QSqlQuery query;
    query.prepare("delete from Professionals where phone_number = '"+phoneNumber+"'");

   if(query.exec()){
        QMessageBox::information(this, "Komunikat", "Usunięto");
        connection.connClose();
    } else {
        QMessageBox::information(this, "ERROR", "Nie usunięto");
    }
}


void ProfessionalDialog::on_findPushButton_clicked()
{
    LoginWindow connection;
    QSqlQueryModel * model = new QSqlQueryModel();

    connection.connOpen();
    QSqlQuery * query = new QSqlQuery(connection.mainDb);
    query->prepare("select * from Professionals");
    query->exec();
    model->setQuery(*query);
    ui->infoTableView->setModel(model);
    connection.connClose();
    qDebug() << (model->rowCount());
}



void ProfessionalDialog::on_voivodeshipComboBox_currentIndexChanged(int index)
{
    LoginWindow connection;
    int voivodeshipId = ui->voivodeshipComboBox->currentIndex();
    voivodeshipId += 1;
    voivodeshipId *= 2;
    QSqlQueryModel * modelCounty = new QSqlQueryModel();
    connection.connOpen();
    QSqlQuery * queryCounty = new QSqlQuery(connection.mainDb);
    qDebug() << voivodeshipId;
    queryCounty->prepare("select powiat from Powiaty where wojewodztwoId = :voivodeshipId");
    queryCounty->bindValue(":voivodeshipId", voivodeshipId);
    queryCounty->exec();
    modelCounty->setQuery(*queryCounty);
    ui->countyComboBox->setModel(modelCounty);
    ui->countyComboBox->setCurrentIndex(-1);
    connection.connClose();
    qDebug() << (modelCounty->rowCount());

}

