#ifndef TRADERDIALOG_H
#define TRADERDIALOG_H

#include <QDialog>

namespace Ui {
class TraderDialog;
}

class TraderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TraderDialog(QWidget *parent = 0);
    ~TraderDialog();

private:
    Ui::TraderDialog *ui;
};

#endif // TRADERDIALOG_H
