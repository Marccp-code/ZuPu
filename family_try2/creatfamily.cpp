#include "creatfamily.h"
#include "ui_creatfamily.h"
#include "tree.h"
#include "fileoperate.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QButtonGroup>
#include <QDebug>
#include <QSqlDatabase>

creatfamily::creatfamily(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::creatfamily)
{
    ui->setupUi(this);
    this->setWindowTitle("Creat A Family");
    this->setMaximumSize(822,583);
    this->setMinimumSize(822,583);

    ui->nameline->setPlaceholderText("name");
    ui->telnumline->setPlaceholderText("telephone");
    ui->addressline->setPlaceholderText("address");

    buttongroup1=new QButtonGroup(this);
    buttongroup2=new QButtonGroup(this);
    buttongroup1->addButton(ui->maleradio,0);
    buttongroup1->addButton(ui->femaleradio,1);
    buttongroup2->addButton(ui->liveradio,0);
    buttongroup2->addButton(ui->deadradio,1);
    connect(ui->returnbtn,SIGNAL(clicked()),this,SLOT(returnbtnSlot()));
    connect(ui->confirmbtn,SIGNAL(clicked()),this,SLOT(confirmbtnSlot()));
    connect(buttongroup1,SIGNAL(buttonClicked(int)),this,SLOT(onRadioClickGender(int)));
    //connect(ui->femaleradio,SIGNAL(clicked()),this,SLOT(onRadioClickGender()));
    connect(buttongroup2,SIGNAL(buttonClicked(int)),this,SLOT(onRadioClickIslive(int)));
    //connect(ui->deadradio,SIGNAL(clicked()),this,SLOT(onRadioClickIslive()));
}

creatfamily::~creatfamily()
{
    delete ui;
}

void creatfamily::clearAll()
{
    ui->nameline->clear();
    ui->telnumline->clear();
    ui->addressline->clear();
    ui->maleradio->setChecked(false);
    ui->femaleradio->setChecked(false);
    ui->liveradio->setChecked(false);
    ui->deadradio->setChecked(false);

}

bool creatfamily::judgeEmpty()
{
    if(ui->nameline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","name不能为空",QMessageBox::Yes);
        return false;
    }
    else if(ui->telnumline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","telephonenumber不能为空",QMessageBox::Yes);
        return false;
    }
    else if(ui->addressline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","address不能为空",QMessageBox::Yes);
        return false;
    }

    else
        return true;
}

void creatfamily::onRadioClickGender(int id)
{
    switch(buttongroup1->checkedId())
    {
    case 0:
        break;
    case 1:
        break;
    }
}

void creatfamily::onRadioClickIslive(int id)
{
    switch(buttongroup2->checkedId())
    {
    case 0:
        break;
    case 1:
        break;
    }
}


void creatfamily::returnbtnSlot()
{

        emit EmitToMenu();
        this->hide();
        return;

}
void creatfamily::confirmbtnSlot()
{
    if(!this->judgeEmpty())
        return;
    Tree *tr;
    tr = new Tree;

    tr->selfname = ui->nameline->text();
    tr->generation = 1;
    qDebug()<<"0"<<endl;
    if(buttongroup1->checkedId()==0)
        tr->gender="male";
    else if(buttongroup1->checkedId()==1)
        tr->gender="female";
    if(buttongroup2->checkedId()==0)
        tr->IsLife="live";
    else if(buttongroup2->checkedId()==1)
        tr->IsLife="dead";
    tr->telnum=ui->telnumline->text();
    tr->address=ui->addressline->text();
    tr->father_name="no";
    FileOperate f;

    f.FileCreate(tr,tr->selfname);

    }

