#include "inserirmatrizscream.h"
#include "ui_inserirmatrizscream.h"
#include <bits/stdc++.h>
using namespace std;

inserirMatrizScream::inserirMatrizScream(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inserirMatrizScream)

{
    ui->setupUi(this);
    this->cliked = 0;
}

inserirMatrizScream::~inserirMatrizScream()
{
    delete ui;
}

void inserirMatrizScream::setMat(TP2::Matriz<int> *mat){
    this->mat = mat;
}

void inserirMatrizScream::setDimesion(int linha, int coluna){
    this->linhas = linha;
    this->coluna = coluna;
    ui->tableWidget->setRowCount(this->linhas);
    ui->tableWidget->setColumnCount(this->coluna);
    ui->tableWidget->gridStyle();
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void inserirMatrizScream::getElements()
{
    try{
        for(int i =0;i<this->linhas;i++)
        {
            for(int j =0;j<this->coluna;j++)
            {
               mat->setElemento(ui->tableWidget->item(i,j)->text().toInt(),i,j);
            }
        }
    }
    catch(...)
    {
/////////////////////////// throw
    }
}

void inserirMatrizScream::setElements()
{
    for(int i =0;i<this->linhas;i++){
        for(int j =0;j<this->coluna;j++){
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(this->mat->getElemento(i,j))));
        }
    }
}

void inserirMatrizScream::setcliked(int *i){
    this->cliked = i;
}

void inserirMatrizScream::on_pushButton_clicked()
{
    try{
        this->getElements();
        *cliked = 1;
        this->close();
    }
    catch(QString &aux){
        QMessageBox::warning(this," ",aux);
    }
}
