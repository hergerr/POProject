#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H
#pragma once

#include <QtSql>
#include <QDebug>
#include <QFileInfo>

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

#endif // DATABASECONTROLLER_H
