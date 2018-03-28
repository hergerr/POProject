#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "chooseapersondialog.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    login = QSqlDatabase::addDatabase("QSQLITE");
    login.setDatabaseName("C:/sqlite/login.db");
    login.open();

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_LoginPushButton_clicked()
{
    QString username = ui->loginLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QSqlQuery query;



    if(query.exec("select * from users where login = '"+username+"' and password='"+password+"'")){
        int count = 0;
        while(query.next()){
            count++;
            qDebug() << count;
        }
        if(count == 1){
            hide();
            chooseAPersonDialog = new ChooseAPersonDialog();
            chooseAPersonDialog->show();
        }

        if(count < 1){
           QMessageBox::information(this,"Error", "Niepoprawne haslo lub nazwa uzytkownika.");
        }
    } else qDebug() << query.lastError().text();

}
