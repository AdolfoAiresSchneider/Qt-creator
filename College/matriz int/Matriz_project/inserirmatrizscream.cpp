#include "inserirmatrizscream.h"
#include "ui_inserirmatrizscream.h"


inserirMatrizScream::inserirMatrizScream(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inserirMatrizScream)

{
    ui->setupUi(this);
    this->cliked = 0;
}

inserirMatrizScream::~inserirMatrizScream(){
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
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

bool inserirMatrizScream::getElements()
{
    int aux;
    try{
        for(int i =0;i<this->linhas;i++){
            for(int j =0;j<this->coluna;j++){
               if( ui->tableWidget->item(i,j)){
                    aux = ui->tableWidget->item(i,j)->text().toInt();
                    if(aux == 0 && ui->tableWidget->item(i,j)->text() != "0") throw QString("Digito Invalido em" + QString::number(i+1)+" "+QString::number(j+1));
                    mat->setElemento(aux,i,j);
               }
               else{
                    QMessageBox::warning(this," ","Elemento não digitado em " + QString::number(i+1)+" "+QString::number(j+1));
                    return false;
               }
            }
        }
        return true;
    }
    catch(QString &erro){
        throw erro;
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

void inserirMatrizScream::on_pushButton_clicked(){
    try{
        if(!this->getElements())
            return;
        *cliked = 1;
        this->close();
    }
    catch(QString &aux){
        QMessageBox::warning(this," ",aux);
    }
}
