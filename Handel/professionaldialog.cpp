#include "professionaldialog.h"
#include "ui_professionaldialog.h"

ProfessionalDialog::ProfessionalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfessionalDialog)
{
    ui->setupUi(this);

    //na poczatku trzeba zaladowac do comboBoxa z wojewodztwami
    //wszystkie wojedzwtwa

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
    //dodawanie nowego rekordu z uwzglednieniem poprawnosci nr telefonu
    //przewidziane formy to xxx xxx xxx lub xxxxxxxxx

    LoginWindow connection;
    QString name = ui->nameLineEdit->text();
    QString companyName = ui->companyNameLineEdit->text();
    QString companyType = ui->companyTypeLineEdit->text();
    QString phoneNumber = ui->phoneLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString voivodeship = ui->voivodeshipComboBox->currentText();
    QString county = ui->countyComboBox->currentText();
    QString city = ui->cityComboBox->currentText();

    if(phoneNumber.length() == 9 || phoneNumber.length() == 11){
        connection.connOpen();
        QSqlQuery query;
        query.prepare("insert into Professionals  (name, company_name, company_type, phone_number, email, voivodeship, county, city)"
                  " values ('"+name+"','"+companyName+"','"+companyType+"','"+phoneNumber+"','"+email+"','"+voivodeship+"','"+county+"','"+city+"')");

    if(query.exec()){
         QMessageBox::information(this, "Komunikat", "Zapisano");
         connection.connClose();
     } else {
         QMessageBox::information(this, "ERROR", "Nie zapisano");
     }

    }
    else QMessageBox::information(this, "Komunikat", "Niepoprawny numer telefonu");



}

void ProfessionalDialog::on_modifyPushButton_clicked()
{
    //modyfikowanie rekordu na podstawie id z uwzglednieniem nr. telefonu
    LoginWindow connection;
    QString id = ui->lineEdit->text();
    QString name = ui->nameLineEdit->text();
    QString companyName = ui->companyNameLineEdit->text();
    QString companyType = ui->companyTypeLineEdit->text();
    QString phoneNumber = ui->phoneLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString voivodeship = ui->voivodeshipComboBox->currentText();
    QString county = ui->countyComboBox->currentText();
    QString city = ui->cityComboBox->currentText();

    if(phoneNumber.length() == 9 || phoneNumber.length() == 11){
    connection.connOpen();
    QSqlQuery query;
    query.prepare("update Professionals set name = '"+name+"',company_name = '"+companyName+"',"
                  " company_type = '"+companyType+"', phone_number = '"+phoneNumber+"',"
                  " email = '"+email+"', voivodeship = '"+voivodeship+"', county = '"+county+"',city = '"+city+"' where id = '"+id+"'");

   if(query.exec()){
        QMessageBox::information(this, "Komunikat", "Zmieniono");
        connection.connClose();
    } else {
        QMessageBox::information(this, "ERROR", "Nie zmieniono");
    }

    }
    else QMessageBox::information(this, "Komunikat", "Niepoprawny numer telefonu");
}

void ProfessionalDialog::on_deletePushButton_clicked()
{
    //usuwanie rekordu na podstawie id

    LoginWindow connection;
    QString id = ui->lineEdit->text();

    connection.connOpen();
    QSqlQuery query;
    query.prepare("delete from Professionals where id = '"+id+"'");

   if(query.exec()){
        QMessageBox::information(this, "Komunikat", "Usunięto");
        connection.connClose();
    } else {
        QMessageBox::critical(this, "ERROR", "Nie usunięto");
    }
}


void ProfessionalDialog::on_findPushButton_clicked()
{
    //Pokazanie wszystkich rekordow, a takze wyszukiwanie na podstawie
    //tekstu w comboBoxach

    LoginWindow connection;
    QSqlQueryModel * model = new QSqlQueryModel();
    connection.connOpen();
    QSqlQuery * query = new QSqlQuery(connection.mainDb);


    if(ui->voivodeshipComboBox->currentIndex() == -1){
        query->prepare("select * from Professionals");
    } else if (ui->voivodeshipComboBox->currentIndex() != -1 && ui->countyComboBox->currentIndex() == -1){
        QString voivodeship = ui->voivodeshipComboBox->currentText();
        query->prepare("select * from Professionals where voivodeship = '"+voivodeship+"' ");
    } else{
        QString voivodeship = ui->voivodeshipComboBox->currentText();
        QString county = ui->countyComboBox->currentText();
        query->prepare("select * from Professionals where voivodeship = '"+voivodeship+"' and county = '"+county+"'");
    }


    query->exec();
    model->setQuery(*query);
    ui->infoTableView->setModel(model);
    connection.connClose();
    qDebug() << (model->rowCount());
    if(model->rowCount() == 0) QMessageBox::information(this, "Komumikat", "Brak pasujacych rekordów");
}



void ProfessionalDialog::on_voivodeshipComboBox_currentIndexChanged(int index)
{
    //wyszukiwaanie powiatow na podstawie wybranego wojewodztwa
    LoginWindow connection;
    int voivodeshipId = ui->voivodeshipComboBox->currentIndex();

    //nalezy zmodyfikowac otrzymany indeks, tak aby zgadzal sie z indexem w bazie danych
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


void ProfessionalDialog::on_countyComboBox_currentIndexChanged(int index)
{
    //analogicznie do powyzszej metody, wybieranie miasta na podstawie wojewodztwa
    // i powiatu do ktorego nalezy
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

void ProfessionalDialog::on_infoTableView_activated(const QModelIndex &index)
{
    //gdy klikniemy na jakies pole rekordu to dane zaprezentuja sie
    //w textboxach, bardziej w formie wizytowkowej

    //w ten sposob mozna wygodnie edytowac rekordy
    LoginWindow connection;
    QString val = ui->infoTableView->model()->data(index).toString();
    connection.connOpen();
    QSqlQuery query;
    query.prepare("select * from Professionals where id = '"+val+"' or name = '"+val+"'"
                  " or company_name = '"+val+"' or company_type = '"+val+"' or phone_number = '"+val+"'"
                  " or email = '"+val+"'or voivodeship = '"+val+"' or county = '"+val+"' or city = '"+val+"'");

    //ustalanie zawartosci textboxow na podstawie pozycji w tabeli w bazie danych
    if(query.exec()){
        while(query.next()){
            ui->lineEdit->setText(query.value(0).toString());
            ui->nameLineEdit->setText(query.value(1).toString());
            ui->companyNameLineEdit->setText(query.value(2).toString());
            ui->companyTypeLineEdit->setText(query.value(3).toString());
            ui->phoneLineEdit->setText(query.value(4).toString());
            ui->emailLineEdit->setText(query.value(5).toString());
            ui->voivodeshipComboBox->setCurrentText(query.value(6).toString());
            ui->countyComboBox->setCurrentText(query.value(7).toString());
            ui->cityComboBox->setCurrentText(query.value(8).toString());
        }
        connection.connClose();
    } else {
        QMessageBox::critical(this,"ERROR", query.lastError().text());
    }
}

void ProfessionalDialog::on_cleanPushButton_clicked()
{
    //wyczeszczenie textboxow

    ui->lineEdit->setText("");
    ui->nameLineEdit->setText("");
    ui->companyNameLineEdit->setText("");
    ui->companyTypeLineEdit->setText("");
    ui->phoneLineEdit->setText("");
    ui->emailLineEdit->setText("");
    ui->voivodeshipComboBox->setCurrentIndex(-1);
    ui->countyComboBox->setCurrentIndex(-1);
    ui->cityComboBox->setCurrentIndex(-1);
}
