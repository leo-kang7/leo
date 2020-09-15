#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"math.h"
#include "QDebug"
#include<iostream>
#include<string>
using namespace std;
#include<stack>
#include<vector>
#include<cstdlib>
#include<limits.h>
bool isNum(char ch);
bool isOperate(char ch);
int level(char ch);
double scd(string s);
double getValue(vector<string> V);
vector<string> midToPost(string s);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     system_init();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::system_init(){

    //进制转换
    input.addButton(ui->radioButton1,2);
    input.addButton(ui->radioButton2,10);
    input.addButton(ui->radioButton3,16);
    ui->radioButton2->setChecked(true);

    output.addButton(ui->radioButton4,2);
    output.addButton(ui->radioButton5,10);
    output.addButton(ui->radioButton6,16);
    output.setId(ui->radioButton5,10);
    ui->radioButton5->setChecked(true);
    connect(ui->num0,&QPushButton::clicked,this,&MainWindow::num0Clicked);
    connect(ui->num1,&QPushButton::clicked,this,&MainWindow::num1Clicked);
    connect(ui->num2,&QPushButton::clicked,this,&MainWindow::num2Clicked);
    connect(ui->num3,&QPushButton::clicked,this,&MainWindow::num3Clicked);
    connect(ui->num4,&QPushButton::clicked,this,&MainWindow::num4Clicked);
    connect(ui->num5,&QPushButton::clicked,this,&MainWindow::num5Clicked);
    connect(ui->num6,&QPushButton::clicked,this,&MainWindow::num6Clicked);
    connect(ui->num7,&QPushButton::clicked,this,&MainWindow::num7Clicked);
    connect(ui->num8,&QPushButton::clicked,this,&MainWindow::num8Clicked);
    connect(ui->num9,&QPushButton::clicked,this,&MainWindow::num9Clicked);
    connect(ui->fu,&QPushButton::clicked,this,&MainWindow::fuClicked);
    connect(ui->plus,&QPushButton::clicked,this,&MainWindow::plusClicked);
    connect(ui->min,&QPushButton::clicked,this,&MainWindow::minClicked);
    connect(ui->mul,&QPushButton::clicked,this,&MainWindow::mulClicked);
    connect(ui->div,&QPushButton::clicked,this,&MainWindow::divClicked);
    connect(ui->equal,&QPushButton::clicked,this,&MainWindow::equalClicked);
    connect(ui->dot,&QPushButton::clicked,this,&MainWindow::dotClicked);
    connect(ui->clear,&QPushButton::clicked,this,&MainWindow::clearClicked);
    connect(ui->delete_2,&QPushButton::clicked,this,&MainWindow::deleteClicked);
    connect(ui->left,&QPushButton::clicked,this,&MainWindow::leftClicked);
    connect(ui->right,&QPushButton::clicked,this,&MainWindow::rightClicked);
}
void MainWindow::code_change(){
    QString ss=ui->lineEdit_input->text();
    qDebug()<<"sss"<<input.checkedId();
    on_lineEdit_input_textChanged(ss);
}
void MainWindow::on_lineEdit_input_textChanged(const QString &arg1)//将输入的字符串转换成相应进制的数
{
    bool ok;
    qDebug()<<arg1;
    code_input=input.checkedId();
    code_resu=output.checkedId();
    switch (code_input) {
    case 2:
        start=arg1.toInt(&ok,2);
        break;
    case 8:
        start=arg1.toInt(&ok,8);
        break;
    case 10:
        start=arg1.toInt(&ok,10);
        break;
    case 16:
        start=arg1.toInt(&ok,16);
        break;
    }
    print_resu();
}
//进制转换输出
void MainWindow::print_resu(){
    switch (code_resu) {
    case 2:
        resu=QString::number(start,2);
        break;
    case 8:
        resu=QString::number(start,8);
        break;
    case 10:
       resu=QString::number(start,10);
        break;
    case 16:
        resu=QString::number(start,16);
        break;
    }
    ui->lineEdit_output->setText(resu);
}

void MainWindow::num0Clicked()  //以下是实现相应的槽函数
{
    input2='0';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::num1Clicked()
{
    input2='1';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::num2Clicked()
{
    input2='2';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::num3Clicked()
{
    input2='3';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::num4Clicked()
{
    input2='4';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::num5Clicked()
{
    input2='5';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::num6Clicked()
{
    input2='6';
   ui->edit_show->insertPlainText(input2);
}

void MainWindow::num7Clicked()
{
    input2='7';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::num8Clicked()
{
    input2='8';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::num9Clicked()
{
    input2='9';
    ui->edit_show->insertPlainText(input2);
}
void MainWindow::plusClicked()
{
    input2='+';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::minClicked()
{
    input2='-';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::mulClicked()
{
    input2='*';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::divClicked()
{
    input2='/';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::dotClicked() //小数点
{
    input2='.';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::fuClicked() //正负号
{
        input2='-';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::leftClicked()//左括号
{
    input2='(';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::rightClicked()//右括号
{
    input2=')';
    ui->edit_show->insertPlainText(input2);
}
void MainWindow::deleteClicked()
{   QString input2=ui->edit_show->toPlainText();
    input2 = input2.left(input2.length()-1); //减去一字符
    ui->edit_show->clear();
    ui->edit_show->insertPlainText(input2);
}
void MainWindow::clearClicked() //直接清空
{
    ui->edit_show->clear();
}

void MainWindow::equalClicked(){

}
