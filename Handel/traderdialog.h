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

class TraderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TraderDialog(QWidget *parent = 0);
    ~TraderDialog();

private slots:
    void on_voivodeshipComboBox_currentIndexChanged(int index);

    void on_countyComboBox_currentIndexChanged(int index);

    void on_addPushButton_clicked();

    void on_deletePushButton_clicked();

    void on_modifyPushButton_clicked();

    void on_findPushButton_clicked();

    void on_infoTableView_activated(const QModelIndex &index);

private:
    Ui::TraderDialog *ui;
};

#endif // TRADERDIALOG_H
