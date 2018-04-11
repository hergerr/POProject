#ifndef TRADERDIALOG_H
#define TRADERDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include "loginwindow.h"

namespace Ui {
class TraderDialog;
}

//dziedziczenie po QDialog
class TraderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TraderDialog(QWidget *parent = 0);
    ~TraderDialog();

private slots:
    //deklaracje metod obslugujacych zdarzenie klikniecia guzikow

    void on_voivodeshipComboBox_currentIndexChanged(int index);

    void on_countyComboBox_currentIndexChanged(int index);

    void on_addPushButton_clicked();

    void on_deletePushButton_clicked();

    void on_modifyPushButton_clicked();

    void on_findPushButton_clicked();

    void on_infoTableView_activated(const QModelIndex &index);

    void on_cleanPushButton_clicked();

private:
    Ui::TraderDialog *ui;
};

#endif // TRADERDIALOG_H
