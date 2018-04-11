#include "traderdialog.h"
#include "ui_traderdialog.h"

//komentarze analogiczne do professionaldialog.cpp
//zmiany sa dosc kosmetyczne
TraderDialog::TraderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TraderDialog)
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

TraderDialog::~TraderDialog()
{
    delete ui;
}

void TraderDialog::on_voivodeshipComboBox_currentIndexChanged(int index)
{
    LoginWindow connection;
    int voivodeshipId = ui->voivodeshipComboBox->currentIndex();
    voivodeshipId += 1;
    voivodeshipId *= 2;
    QSqlQueryModel * modelCounty = new QSqlQueryModel();
    connection.connOpen();
    QSqlQuery * queryCounty = new QSqlQuery(connection.mainDb);
    queryCounty->prepare("select powiat from Powiaty where wojewodztwoId = :voivodeshipId");
    queryCounty->bindValue(":voivodeshipId", voivodeshipId);
    queryCounty->exec();
    modelCounty->setQuery(*queryCounty);
    ui->countyComboBox->setModel(modelCounty);
    ui->countyComboBox->setCurrentIndex(-1);
    connection.connClose();
    qDebug() << (modelCounty->rowCount());
}

void TraderDialog::on_countyComboBox_currentIndexChanged(int index)
{
    LoginWindow connection;
    int voivodeshipId = ui->voivodeshipComboBox->currentIndex();
    int countyId = ui->countyComboBox->currentIndex();
    voivodeshipId += 1;
    voivodeshipId *= 2;
    countyId += 1;
    QSqlQueryModel * modelCity = new QSqlQueryModel();
    connection.connOpen();
    QSqlQuery * queryCity = new QSqlQuery(connection.mainDb);
    queryCity->prepare("select miasto from Miasta where wojewodztwoId = :voivodeshipId and powiatId = :countyId");
    queryCity->bindValue(":voivodeshipId", voivodeshipId);
    queryCity->bindValue(":countyId", countyId);
    queryCity->exec();
    modelCity->setQuery(*queryCity);
    ui->cityComboBox->setModel(modelCity);
    ui->cityComboBox->setCurrentIndex(-1);
    connection.connClose();
    qDebug() << (modelCity->rowCount());
}

void TraderDialog::on_addPushButton_clicked()
{
    QString name = ui->nameLineEdit->text();
    QString workHours = ui->workHoursLineEdit->text();
    QString phoneNumber = ui->phoneLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString voivodeship = ui->voivodeshipComboBox->currentText();
    QString county = ui->countyComboBox->currentText();
    QString city = ui->cityComboBox->currentText();

    if(phoneNumber.length() == 9 || phoneNumber.length() == 11){

    LoginWindow connection;
    connection.connOpen();
    QSqlQuery query;
    query.prepare("insert into Traders  (name, work_hours, phone_number, email,"
                  " voivodeship, county, city) values ('"+name+"','"+workHours+"','"+phoneNumber+"',"
                  "'"+email+"','"+voivodeship+"','"+county+"','"+city+"')");

   if(query.exec()){
        QMessageBox::information(this, "Komunikat", "Zapisano");
        connection.connClose();
    } else {
        QMessageBox::information(this, "ERROR", "Nie zapisano");
    }
    } else QMessageBox::information(this, "Komunikat", "Niepoprawny numer telefonu");
}

void TraderDialog::on_deletePushButton_clicked()
{
    LoginWindow connection;
    QString id = ui->lineEdit->text();

    connection.connOpen();
    QSqlQuery query;
    query.prepare("delete from Traders where id = '"+id+"'");

   if(query.exec()){
        QMessageBox::information(this, "Komunikat", "Usunięto");
        connection.connClose();
    } else {
        QMessageBox::critical(this, "ERROR", "Nie usunięto");
    }
}

void TraderDialog::on_modifyPushButton_clicked()
{
    QString id = ui->lineEdit->text();
    QString name = ui->nameLineEdit->text();
    QString workHours = ui->workHoursLineEdit->text();
    QString phoneNumber = ui->phoneLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString voivodeship = ui->voivodeshipComboBox->currentText();
    QString county = ui->countyComboBox->currentText();
    QString city = ui->cityComboBox->currentText();

    if(phoneNumber.length() == 9 || phoneNumber.length() == 11){
    LoginWindow connection;
    connection.connOpen();
    QSqlQuery query;
    query.prepare("update Traders set name = '"+name+"', work_hours = '"+workHours+"',"
                  " phone_number = '"+phoneNumber+"', email = '"+email+"', voivodeship = '"+voivodeship+"',"
                  " county = '"+county+"',city = '"+city+"' where id = '"+id+"'");

   if(query.exec()){
        QMessageBox::information(this, "Komunikat", "Zmieniono");
        connection.connClose();
    } else {
        QMessageBox::information(this, "ERROR", "Nie zmieniono");
    }
    } else QMessageBox::information(this, "Komunikat", "Niepoprawny numer telefonu");
}

void TraderDialog::on_findPushButton_clicked()
{
    LoginWindow connection;
    QSqlQueryModel * model = new QSqlQueryModel();
    connection.connOpen();
    QSqlQuery * query = new QSqlQuery(connection.mainDb);


    if(ui->voivodeshipComboBox->currentIndex() == -1){
        query->prepare("select * from Traders");
    } else if (ui->voivodeshipComboBox->currentIndex() != -1 && ui->countyComboBox->currentIndex() == -1){
        QString voivodeship = ui->voivodeshipComboBox->currentText();
        query->prepare("select * from Traders where voivodeship = '"+voivodeship+"' ");
    } else{
        QString voivodeship = ui->voivodeshipComboBox->currentText();
        QString county = ui->countyComboBox->currentText();
        query->prepare("select * from Traders where voivodeship = '"+voivodeship+"' and county = '"+county+"'");
    }


    query->exec();
    model->setQuery(*query);
    ui->infoTableView->setModel(model);
    connection.connClose();
    qDebug() << (model->rowCount());

    if(model->rowCount() == 0) QMessageBox::information(this, "Komumikat", "Brak pasujacych rekordów");
}

void TraderDialog::on_infoTableView_activated(const QModelIndex &index)
{
    LoginWindow connection;
    QString val = ui->infoTableView->model()->data(index).toString();
    connection.connOpen();
    QSqlQuery query;
    query.prepare("select * from Traders where id = '"+val+"' or name = '"+val+"'"
                  " or work_hours = '"+val+"' or phone_number = '"+val+"'"
                  " or email = '"+val+"'or voivodeship = '"+val+"' or county = '"+val+"' or city = '"+val+"'");

    if(query.exec()){
        while(query.next()){
            ui->lineEdit->setText(query.value(0).toString());
            ui->nameLineEdit->setText(query.value(1).toString());
            ui->workHoursLineEdit->setText(query.value(2).toString());
            ui->phoneLineEdit->setText(query.value(3).toString());
            ui->emailLineEdit->setText(query.value(4).toString());
            ui->voivodeshipComboBox->setCurrentText(query.value(5).toString());
            ui->countyComboBox->setCurrentText(query.value(6).toString());
            ui->cityComboBox->setCurrentText(query.value(7).toString());
        }
        connection.connClose();
    } else {
        QMessageBox::critical(this,"ERROR", query.lastError().text());
    }
}

void TraderDialog::on_cleanPushButton_clicked()
{
    ui->lineEdit->setText("");
    ui->nameLineEdit->setText("");
    ui->workHoursLineEdit->setText("");
    ui->phoneLineEdit->setText("");
    ui->emailLineEdit->setText("");
    ui->voivodeshipComboBox->setCurrentIndex(-1);
    ui->countyComboBox->setCurrentIndex(-1);
    ui->cityComboBox->setCurrentIndex(-1);
}
