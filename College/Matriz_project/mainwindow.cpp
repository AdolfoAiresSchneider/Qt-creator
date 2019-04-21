#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <bits/stdc++.h>
using namespace std;

///*
///  Coisas que faltam pra fazer que eu lembrei :
///     Validar dados na tabela vazia
///     Informações
///     Verificar todos os thorws
///     potencia
///     ortogonal
///     ordem logica dos botoes
///     igual e diferente
///     operaçoes sem matrizes ->>> null
///     caso aperte o cancelar na multiplicação constante
///     apertar o botao x na inserçao da matriz
///
///
///
/// simetrica
/// potencia
/// permutação
/// *


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    matA = matB= 0;
    ui->multiplicacao->setEnabled(false);
    ui->soma->setEnabled(false);
    ui->subtracao->setEnabled(false);
}

void MainWindow::setTableDimension(int linhas, int coluna, QTableWidget *tableWidget)
{
    tableWidget->clear();
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->setRowCount(linhas);
    tableWidget->setColumnCount(coluna);
    tableWidget->gridStyle();
}


void MainWindow::setMatriz_Tela(TP2::Matriz<int> *mat, QTableWidget *tableWidget)
{
    int linhas = mat->getQuantidadeDeLinhas();
    int colunas = mat->getQuantidadeDeColunas();
    this->setTableDimension(linhas,colunas,tableWidget);
    for(int i = 0;i<linhas;i++)
        for(int j = 0;j <colunas;j++)
            tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(mat->getElemento(i,j))));
}

int MainWindow::showInpuScrem(TP2::Matriz<int> * mat,int editar)
{
    inserirMatrizScream Tela;
    Tela.setMat(mat);
    Tela.setDimesion(mat->getQuantidadeDeLinhas(),mat->getQuantidadeDeColunas());
    int i = 0;
    Tela.setcliked(&i);
    if(editar)
        Tela.setElements();
    Tela.exec();
    Tela.show();
    return i;
}

void MainWindow::getInformationsMatrix(TP2::Matriz<int> *mat, QTextBrowser *textBrowserMat)
{
    QString aux;
    if(mat->isTriangularSuperior())
        aux.push_back("--> Triangular Superior\n");
    if(mat->isTriangularInferior())
        aux.push_back("--> Triangular Inferior\n");
    if(mat->isSimetrica())
        aux.push_back("--> Simetrica\n");
    if(mat->isIdentidade())
        aux.push_back("--> Identidade\n");
    if(mat->isOrtogonal())
        aux.push_back("--> Ortogonal\n");
    textBrowserMat->setText(aux);

}

void MainWindow::setEnableBotton()
{
    if(matA && matB){
        ui->subtracao->setEnabled(true);
        ui->soma->setEnabled(true);
        ui->multiplicacao->setEnabled(true);
    }
}

void MainWindow::setDesableBotton()
{
    ui->subtracao->setEnabled(false);
    ui->soma->setEnabled(false);
    ui->multiplicacao->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_criarA_botton_clicked()
{
    int linhas = QInputDialog::getInt(this,"Numero de Linhas","Linhas",QLineEdit::Normal);
    int colunas = QInputDialog::getInt(this,"Numero de Colunas","Colunas",QLineEdit::Normal);

    if(linhas >0 && colunas >0){
        this->matA = new TP2::Matriz<int>(linhas,colunas);
        if(!showInpuScrem(matA,0))
            return;
        this->setMatriz_Tela(matA,ui->tableWidget_MatA);
        int aux = ui->comboBox_OpoesMatrizes->findText("Excluir Matriz A");
        if(aux<0){
            ui->comboBox_OpoesMatrizes->insertItem(1,"Excluir Matriz A");
            ui->comboBox_OpoesMatrizes->insertItem(1,"Editar Matriz A");
        }
        ui->tabWidget->setCurrentIndex(0);
        ui->toolBoxResults->setCurrentIndex(1);
        ui->criarA_botton->setDisabled(true);
        this->getInformationsMatrix(matA,ui->textBrowserMatA);
        setEnableBotton();
    }
    else{
        QMessageBox::warning(this," ","Dimesao inválida");
    }
}

void MainWindow::on_criarB_botton_clicked()
{
    int linhas = QInputDialog::getInt(this,"Numero de Linhas","Linhas",QLineEdit::Normal);
    int colunas = QInputDialog::getInt(this,"Numero de Colunas","Colunas",QLineEdit::Normal);
    if(linhas && colunas && linhas > 0 && colunas >0){
        this->matB = new TP2::Matriz<int>(linhas,colunas);
        if(!showInpuScrem(matB,0))  return;
        this->setMatriz_Tela(matB,ui->tableWidget_MatB);
        if((int)ui->comboBox_OpoesMatrizes->findText("Excluir Matriz B")<0){//////mudei
            ui->comboBox_OpoesMatrizes->insertItem(1,"Excluir Matriz B");
            ui->comboBox_OpoesMatrizes->insertItem(1,"Editar Matriz B");
        }
        ui->tabWidget->setCurrentIndex(1);
        ui->toolBoxResults->setCurrentIndex(2);
        ui->criarB_botton->setDisabled(true);
        this->getInformationsMatrix(matB,ui->textBrowserMatB);
        setEnableBotton();
    }
    else{
        QMessageBox::warning(this," ","Dimesao inválida");
    }
}

void MainWindow::on_comboBox_OpoesMatrizes_activated(const QString &arg1)
{
    string aux;
    aux = arg1.toStdString();
    if(aux == "Excluir Matriz B"){
        delete matB;
        matB=0;
        ui->comboBox_OpoesMatrizes->removeItem(ui->comboBox_OpoesMatrizes->findText("Excluir Matriz B"));
        ui->comboBox_OpoesMatrizes->removeItem(ui->comboBox_OpoesMatrizes->findText("Editar Matriz B"));
        ui->criarB_botton->setDisabled(false);
        ui->textBrowserMatB->clear();
        setTableDimension(1,1,ui->tableWidget_MatB);
        setDesableBotton();

    }else if(aux == "Editar Matriz B"){
            showInpuScrem(matB,1);
            this->setMatriz_Tela(matB,ui->tableWidget_MatB);
            this->getInformationsMatrix(matB,ui->textBrowserMatB);
    }else if(aux == "Editar Matriz A"){
            showInpuScrem(matA,1);
            this->setMatriz_Tela(matA,ui->tableWidget_MatA);
            this->getInformationsMatrix(matA,ui->textBrowserMatA);
    }else if(aux == "Excluir Matriz A"){
            delete matA;
            matA = 0;
            ui->comboBox_OpoesMatrizes->removeItem(ui->comboBox_OpoesMatrizes->findText("Excluir Matriz A"));
            ui->comboBox_OpoesMatrizes->removeItem(ui->comboBox_OpoesMatrizes->findText("Editar Matriz A"));
            ui->criarA_botton->setDisabled(false);
            ui->textBrowserMatA->clear();
            setTableDimension(1,1,ui->tableWidget_MatA);
            setDesableBotton();
    }
}

void MainWindow::on_soma_clicked()
{
    try{
        TP2::Matriz<int> *aux;
        aux = *matA+matB;
        this->setMatriz_Tela(aux,ui->tableView_Result);
        ui->toolBoxResults->setCurrentIndex(0);
        delete aux;
    }
    catch(QString &erro){
        QMessageBox::warning(this,"Erro",erro);
    }
}

void MainWindow::on_multiplicacao_activated(int index)
{
    TP2::Matriz<int> *aux;
    try{
        if(index == 1){
            aux = *matA*matB;
            this->setMatriz_Tela(aux,ui->tableView_Result);
            delete aux;
        }else if(index ==2){
            aux = *matB*matA;
            this->setMatriz_Tela(aux,ui->tableView_Result);
            delete aux;
        }
    }catch(QString &erro){
        QMessageBox::warning(this,"Erro",erro);
    }
    ui->toolBoxResults->setCurrentIndex(0);
}

void MainWindow::on_transopsta_activated(int index)
{
    TP2::Matriz<int> *aux;
    try{
        if(index == 1){
            if(!matA)
                throw QString("Matriz A não criada");
            aux = matA->getTransposta();
            this->setMatriz_Tela(aux,ui->tableView_Result);
            delete aux;
        }else if(index == 2){
            if(!matB)
                throw QString("Matriz B não criada");
            aux = matB->getTransposta();
            this->setMatriz_Tela(aux,ui->tableView_Result);
            delete aux;
        }
    }
    catch(QString &erro){
        QMessageBox::warning(this,"Erro",erro);
    }
    ui->toolBoxResults->setCurrentIndex(0);
}

void MainWindow::on_Escalar_activated(int index)
{
    TP2::Matriz<int> *aux;
    try{
        if(index == 1){
            if(!matA)
                throw QString("Matriz A não criada");
            int k = QInputDialog::getDouble(this,"Constante"," K ",QLineEdit::Normal);
            aux = (*matA)*k;
            this->setMatriz_Tela(aux,ui->tableView_Result);
            delete aux;

        }else if(index == 2){
            if(!matB)
                throw QString("Matriz B não criada");
            int k = QInputDialog::getDouble(this,"Constante"," K ",QLineEdit::Normal);
            if(k<0)
                throw QString("Numero Negativo");
            aux = (*matB)*k;
            this->setMatriz_Tela(aux,ui->tableView_Result);
            delete aux;
        }
    }
    catch(QString &erro){
        QMessageBox::warning(this,"Erro",erro);
    }
    ui->toolBoxResults->setCurrentIndex(0);
}

void MainWindow::on_potencia_activated(int index)
{
    try
    {
        TP2::Matriz<int> *aux;
        if(index == 1)
        {
            if(!matA)
                throw QString("Matriz A não criada");
            int n = QInputDialog::getInt(this,"Constante"," K ",QLineEdit::Normal);
            aux= matA->Mpow(n);
            this->setMatriz_Tela(aux,ui->tableView_Result);
            delete aux;
            ui->toolBoxResults->setCurrentIndex(0);
        }
        else if(index == 2)
        {
            if(!matB)
                throw QString("Matriz B não criada");
            int n = QInputDialog::getInt(this,"Constante"," K ",QLineEdit::Normal);
            aux= matB->Mpow(n);
            this->setMatriz_Tela(aux,ui->tableView_Result);
            delete aux;
            ui->toolBoxResults->setCurrentIndex(0);
        }

    }
    catch(QString &erro)
    {
        QMessageBox::warning(this,"Erro",erro);
    }
}



void MainWindow::on_subtracao_clicked()
{
    try{
        TP2::Matriz<int> *aux;
        aux = *matA-matB;
        this->setMatriz_Tela(aux,ui->tableView_Result);
        ui->toolBoxResults->setCurrentIndex(0);
        delete aux;
    }
    catch(QString &erro){
        QMessageBox::warning(this,"Erro",erro);
    }
}
