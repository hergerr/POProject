#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "chooseapersondialog.h"


namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mainDb;
    void connClose(){
        mainDb.close();
        mainDb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen(){
        mainDb = QSqlDatabase::addDatabase("QSQLITE");
        mainDb.setDatabaseName("C:/sqlite/poland.db");
        mainDb.open();

        if(!mainDb.open()) {
            qDebug() << ("Cos nie dziala");
            return false;
        }
        else{
            qDebug() << ("Dziala");
            return true;
        }
    }

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_LoginPushButton_clicked();

private:
    Ui::LoginWindow *ui;
    ChooseAPersonDialog *chooseAPersonDialog;
};

#endif // LOGINWINDOW_H
