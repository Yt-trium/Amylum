#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dbm = new DatabaseManager("adem.db");
    memberList = NULL;
    updateUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_save_clicked()
{
    Member m = getMember();

    m.idMember = ui->listWidgetMember->currentRow()+1;

    dbm->update(m);
    updateUI();
}

void MainWindow::on_pushButton_new_clicked()
{
    Member m = getMember();

    dbm->insert(m);
    updateUI();
}

void MainWindow::on_actionQuitter_triggered()
{
    QCoreApplication::quit();
}

Member MainWindow::getMember()
{
    Member m;
    m.idMember = 0;
    m.lastName = ui->lineEdit_lastName->text().toStdString();
    m.firstName = ui->lineEdit_firstName->text().toStdString();
    m.email = ui->lineEdit_email->text().toStdString();
    m.status = m.stringToStatus(ui->comboBox_status->currentText().toStdString());

    return m;
}

void MainWindow::updateUI()
{
    if(memberList != NULL)
        delete memberList;

    memberList = dbm->getMemberList();

    QStringList members;
    Member m;
    int i;
    for (i=0;i<memberList->size();i++)
    {
        m = memberList->at(i);
        members += QString::number(m.idMember) + " - "
                +  QString(m.lastName.c_str())  + " "
                +  QString(m.firstName.c_str()) + " ["
                +  QString(m.getStatus().c_str()) + "]";
    }

    ui->listWidgetMember->clear();
    ui->listWidgetMember->addItems(members);
}

void MainWindow::on_lineEdit_search_textChanged(const QString &arg1)
{
    if(memberList != NULL)
        delete memberList;

    memberList = dbm->getMemberList();

    QStringList members;
    Member m;
    int i;
    for (i=0;i<memberList->size();i++)
    {
        m = memberList->at(i);
        if(QString(m.lastName.c_str()).contains(ui->lineEdit_search->text())
         ||QString(m.firstName.c_str()).contains(ui->lineEdit_search->text()))
        {
            members += QString::number(m.idMember) + " - "
                    +  QString(m.lastName.c_str())  + " "
                    +  QString(m.firstName.c_str()) + " ["
                    +  QString(m.getStatus().c_str()) + "]";
        }
        else
            members += " ";
    }

    ui->listWidgetMember->clear();
    ui->listWidgetMember->addItems(members);
}

void MainWindow::on_listWidgetMember_activated(const QModelIndex &index)
{
    Member m = memberList->at(index.row());

    ui->lineEdit_lastName->setText(QString(m.lastName.c_str()));
    ui->lineEdit_firstName->setText(QString(m.firstName.c_str()));
    ui->lineEdit_email->setText(QString(m.email.c_str()));

    switch(m.status)
    {
    case L1:
        ui->comboBox_status->setCurrentIndex(0);
        break;
    case L2I:
        ui->comboBox_status->setCurrentIndex(1);
        break;
    case L2M:
        ui->comboBox_status->setCurrentIndex(2);
        break;
    case L3I:
        ui->comboBox_status->setCurrentIndex(3);
        break;
    case L3M:
        ui->comboBox_status->setCurrentIndex(4);
        break;
    case M1I:
        ui->comboBox_status->setCurrentIndex(5);
        break;
    case M1M:
        ui->comboBox_status->setCurrentIndex(6);
        break;
    case M2I:
        ui->comboBox_status->setCurrentIndex(7);
        break;
    case M2M:
        ui->comboBox_status->setCurrentIndex(8);
        break;
    case DOC:
        ui->comboBox_status->setCurrentIndex(9);
        break;
    case PROF:
        ui->comboBox_status->setCurrentIndex(10);
        break;
    case AUTRE:
        ui->comboBox_status->setCurrentIndex(11);
        break;
    }
}

void MainWindow::on_actionG_n_rer_mailing_triggered()
{
    // TODO
}
