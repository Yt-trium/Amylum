#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

#include "member.h"
#include "databasemanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_new_clicked();

    void on_actionQuitter_triggered();

    void on_lineEdit_search_textChanged(const QString &arg1);

    void on_listWidgetMember_activated(const QModelIndex &index);

    void on_actionG_n_rer_mailing_triggered();

private:
    Ui::MainWindow *ui;

    DatabaseManager *dbm;
    QList<Member> *memberList;

    Member getMember();
    void updateUI();
};

#endif // MAINWINDOW_H
