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

class ChooseAPersonDialog;


//dziedziczenie po QMainWindow
class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:

    // metodY odpowiedzialne za otwieranie i zamykanie polaczenia z baza danych
    QSqlDatabase mainDb;
    void connClose(){
        mainDb.close();
        mainDb = QSqlDatabase();
        mainDb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen(){
        mainDb = QSqlDatabase::addDatabase("QSQLITE");
        mainDb.setDatabaseName("../main.db");
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
    //deklaracja metody obslugujacej zdarzenie klikniecia guzika
    void on_LoginPushButton_clicked();

private:
    Ui::LoginWindow *ui;

    //Tutaj tworze wskaznik z pomoca ktorego w pliku .cpp bede mogl otworzyc nowe okno zamiast istniejacego
    ChooseAPersonDialog *chooseAPersonDialog;
};

#endif // LOGINWINDOW_H
