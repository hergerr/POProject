#ifndef PROFESSIONALDIALOG_H
#define PROFESSIONALDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include "loginwindow.h"

namespace Ui {
class ProfessionalDialog;
}

//Dziedziczenie po QDialog
class ProfessionalDialog : public QDialog
{
    Q_OBJECT


public:
    explicit ProfessionalDialog(QWidget *parent = 0);
    ~ProfessionalDialog();

private slots:
    //obsluga zdarzen polegajacych na kliknieciu guzika

    void on_addPushButton_clicked();

    void on_modifyPushButton_clicked();

    void on_deletePushButton_clicked();

    void on_findPushButton_clicked();

    void on_voivodeshipComboBox_currentIndexChanged(int index);

    void on_countyComboBox_currentIndexChanged(int index);

    void on_infoTableView_activated(const QModelIndex &index);

    void on_cleanPushButton_clicked();

private:
    Ui::ProfessionalDialog *ui;
};

#endif // PROFESSIONALDIALOG_H
