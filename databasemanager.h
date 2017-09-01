#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QList>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "member.h"

class DatabaseManager
{
public:
    DatabaseManager(QString filename);
    // get
    QList<Member>* getMemberList();
    // edition
    int insert(Member m);
    int update(Member m);
    // int remove(Member m);

private:
    QSqlDatabase dbConnection;
};

#endif // DATABASEMANAGER_H
