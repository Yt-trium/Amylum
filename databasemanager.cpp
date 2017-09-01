#include "databasemanager.h"

DatabaseManager::DatabaseManager(QString filename)
{
    dbConnection = QSqlDatabase::addDatabase("QSQLITE");
    dbConnection.setDatabaseName(filename);

    if (!dbConnection.open())
        qDebug() << "Error: connection with database";
}

QList<Member>* DatabaseManager::getMemberList()
{
    Member m;
    QList<Member> *lm = new QList<Member>();

    if(!dbConnection.open())
    {
        qDebug()<<"DatabaseManager::getMemberList : database not open";
        return lm;
    }

    QString q = "SELECT * FROM Member";
    QSqlQuery query(q);

    while (query.next())
    {
        m.idMember = query.value(0).toInt();
        m.lastName = query.value(1).toString().toStdString();
        m.firstName = query.value(2).toString().toStdString();
        m.email = query.value(3).toString().toStdString();
        m.status = (Status)query.value(4).toInt();

        lm->append(m);
    }
    return lm;
}

int DatabaseManager::insert(Member m)
{
    if(!dbConnection.open())
    {
        qDebug()<<"DatabaseManager::insert : database not open";
        return 1;
    }

    QString q = "INSERT INTO `Member` VALUES (NULL,'" +
                        QString(m.lastName.c_str()) +
                "','" + QString(m.firstName.c_str()) +
                "','" + QString(m.email.c_str()) +
                "','" + QString::number(m.status) + "')";
    QSqlQuery query(q);

    return 0;
}

int DatabaseManager::update(Member m)
{
    if(!dbConnection.open())
    {
        qDebug()<<"DatabaseManager::insert : database not open";
        return 1;
    }

    QString q = "UPDATE `Member` SET `lastName`='"
            + QString(m.lastName.c_str()) + "' WHERE `idMember`='"
            + QString::number(m.idMember)
            + "'";

    QSqlQuery query1(q);

            q = "UPDATE `Member` SET `firstName`='"
            + QString(m.firstName.c_str()) + "' WHERE `idMember`='"
            + QString::number(m.idMember)
            + "'";

    QSqlQuery query2(q);

            q = "UPDATE `Member` SET `email`='"
            + QString(m.email.c_str()) + "' WHERE `idMember`='"
            + QString::number(m.idMember)
            + "'";

    QSqlQuery query3(q);

            q = "UPDATE `Member` SET `status`='"
            + QString::number(m.status) + "' WHERE `idMember`='"
            + QString::number(m.idMember)
            + "'";

    QSqlQuery query4(q);

    return 0;
}
