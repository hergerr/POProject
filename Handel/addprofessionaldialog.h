#ifndef ADDPROFESSIONALDIALOG_H
#define ADDPROFESSIONALDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class AddProfessionalDialog;
}

class AddProfessionalDialog : public QDialog
{
    Q_OBJECT
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
    explicit AddProfessionalDialog(QWidget *parent = 0);
    ~AddProfessionalDialog();

private slots:
    void on_comboBoxVoivodeship_activated(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::AddProfessionalDialog *ui;
};

#endif // ADDPROFESSIONALDIALOG_H
