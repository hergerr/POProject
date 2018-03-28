#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QDialog>
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
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_LoginPushButton_clicked();

private:
    Ui::LoginWindow *ui;
    QSqlDatabase login;
    ChooseAPersonDialog *chooseAPersonDialog;
};

#endif // LOGINWINDOW_H
