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

class ProfessionalDialog : public QDialog
{
    Q_OBJECT


public:
    explicit ProfessionalDialog(QWidget *parent = 0);
    ~ProfessionalDialog();

private slots:
    void on_addPushButton_clicked();

    void on_modifyPushButton_clicked();

    void on_deletePushButton_clicked();

    void on_findPushButton_2_clicked();

    void on_pushButton_clicked();

    void on_showAllPushButton_clicked();

    void on_showEverethingPushButton_clicked();

    void on_findPushButton_clicked();

    void on_voivodeshipComboBox_currentIndexChanged(const QString &arg1);

    void on_voivodeshipComboBox_currentIndexChanged(int index);

    void on_cityComboBox_currentIndexChanged(int index);

    void on_countyComboBox_currentIndexChanged(int index);

    void on_countyComboBox_currentTextChanged(const QString &arg1);

    void on_infoTableView_activated(const QModelIndex &index);

    void on_infoTableView_clicked(const QModelIndex &index);

private:
    Ui::ProfessionalDialog *ui;
};

#endif // PROFESSIONALDIALOG_H
