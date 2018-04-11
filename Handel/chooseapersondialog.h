#ifndef CHOOSEAPERSONDIALOG_H
#define CHOOSEAPERSONDIALOG_H

#include <QDialog>
#include "professionaldialog.h"
#include "traderdialog.h"

namespace Ui {
class ChooseAPersonDialog;
}

class ProfessionalDialog;
class TraderDialog;

//dziedziczenie po QDialog
class ChooseAPersonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseAPersonDialog(QWidget *parent = 0);
    ~ChooseAPersonDialog();

private slots:
    //deklaracja metody obslugujacej zdarzenie klikniecia guzika
    void on_okPushButton_clicked();

private:
    Ui::ChooseAPersonDialog *ui;

    //Tutaj tworze wskazniki z pomoca ktorych w pliku .cpp bede mogl otworzyc nowe okno zamiast istniejacego
    ProfessionalDialog *professionalDialog;
    TraderDialog *traderDialog;
};

#endif // CHOOSEAPERSONDIALOG_H
