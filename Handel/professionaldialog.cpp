#include "professionaldialog.h"
#include "ui_professionaldialog.h"
#include <QStringList>

ProfessionalDialog::ProfessionalDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ProfessionalDialog){
    ui->setupUi(this);
    QString voideshipsData = "2~DOLNOŚLĄSKIE 4~KUJAWSKO-POMORSKIE 6~LUBELSKIE 8~LUBUSKIE 10~ŁÓDZKIE 12~MAŁOPOLSKIE 14~MAZOWIECKIE 16~OPOLSKIE 18~PODKARPACKIE 20~PODLASKIE 22~POMORSKIE 24~ŚLĄSKIE 26~ŚWIĘTOKRZYSKIE 28~WARMIŃSKO-MAZURSKIE 30~WIELKOPOLSKIE 32~ZACHODNIOPOMORSKIE ";
    QStringList list = voideshipsData.split("~");
    ui->voivodeshipComboBox->insertItems(0, list);
}

ProfessionalDialog::~ProfessionalDialog()
{
    delete ui;
}