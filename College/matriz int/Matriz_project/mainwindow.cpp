#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


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



void MainWindow::setTableDimension(int linhas, int coluna, QTableWidget *tableWidget){
    this->deleteTabela(tableWidget);
    tableWidget->clear();
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->setRowCount(linhas);
    tableWidget->setColumnCount(coluna);
}


void MainWindow::setMatriz_Tela(TP2::Matriz<int> *mat, QTableWidget *tableWidget,int id){
    int linhas = mat->getQuantidadeDeLinhas();
    int colunas = mat->getQuantidadeDeColunas();
    this->setTableDimension(linhas,colunas,tableWidget);
    for(int i = 0;i<linhas;i++)
        for(int j = 0;j <colunas;j++)
            tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(mat->getElemento(i,j))));
    getInformationsMatrix(mat,id);
}

int MainWindow::showInpuScrem(TP2::Matriz<int> *mat, int editar){
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

void MainWindow::getInformationsMatrix(TP2::Matriz<int> *mat,int id)
{
    if(id==1){
        if(mat->isTriangularSuperior())
            ui->TSA->setEnabled(true);
        if(mat->isTriangularInferior())
            ui->TIA->setEnabled(true);
        if(mat->isSimetrica())
            ui->SIA->setEnabled(true);
        if(mat->isIdentidade())
            ui->IDA->setEnabled(true);
        if(mat->isOrtogonal())
            ui->OTA->setEnabled(true);
        if(mat->isPermutacao())
            ui->PA->setEnabled(true);
    }
    if(id==2){
        if(mat->isTriangularSuperior())
            ui->TSB->setEnabled(true);
        if(mat->isTriangularInferior())
            ui->TIB->setEnabled(true);
        if(mat->isSimetrica())
            ui->SIB->setEnabled(true);
        if(mat->isIdentidade())
            ui->IDB->setEnabled(true);
        if(mat->isOrtogonal())
            ui->OTB->setEnabled(true);
        if(mat->isPermutacao())
            ui->PB->setEnabled(true);
    }
    if(id==3){
        if(mat->isTriangularSuperior())
            ui->TSR->setEnabled(true);
        if(mat->isTriangularInferior())
            ui->TIR->setEnabled(true);
        if(mat->isSimetrica())
            ui->SIR->setEnabled(true);
        if(mat->isIdentidade())
            ui->IDR->setEnabled(true);
        if(mat->isOrtogonal())
            ui->OTR->setEnabled(true);
        if(mat->isPermutacao())
            ui->PR->setEnabled(true);
    }

    if(matA&&matB && *matA == matB) ui->igualdade1->setEnabled(true),ui->igualdade2->setEnabled(true);
}

void MainWindow::setEnableBotton(){
    if(matA && matB){
        ui->subtracao->setEnabled(true);
        ui->soma->setEnabled(true);
        ui->multiplicacao->setEnabled(true);
    }
}

void MainWindow::setDesableBotton(int id, int edit){
    if(!edit){
        ui->subtracao->setEnabled(false);
        ui->soma->setEnabled(false);
        ui->multiplicacao->setEnabled(false);
    }
    if(id==1){
        ui->TSA->setEnabled(0);
        ui->TIA->setEnabled(0);
        ui->SIA->setEnabled(0);
        ui->IDA->setEnabled(0);
        ui->OTA->setEnabled(0);
        ui->PA->setEnabled(0);
    }
    if(id==2){
        ui->TSB->setEnabled(0);
        ui->TIB->setEnabled(0);
        ui->SIB->setEnabled(0);
        ui->IDB->setEnabled(0);
        ui->OTB->setEnabled(0);
        ui->PB->setEnabled(0);
    }
    ui->igualdade1->setDisabled(1);
    ui->igualdade2->setDisabled(1);
}

void MainWindow::deleteTabela(QTableWidget *tableWidget)
{
    for(int i =0;i<tableWidget->rowCount();i++)
        for(int j =0;j<tableWidget->columnCount();j++)
            delete tableWidget->item(i,j);
}

MainWindow::~MainWindow()
{
    delete matA;
    delete matB;
    delete ui;
}

void MainWindow::on_criarA_botton_clicked(){
    int linhas = QInputDialog::getInt(this,"Numero de Linhas","Linhas",QLineEdit::Normal);
    int colunas = QInputDialog::getInt(this,"Numero de Colunas","Colunas",QLineEdit::Normal);
    try{
        if(linhas >0 && colunas >0){
        this->matA = new TP2::Matriz<int>(linhas,colunas);
            if(!showInpuScrem(matA,0)){
                delete matA;
                matA=0;
                return;
            }
            this->setMatriz_Tela(matA,ui->tableWidget_MatA,1);
            int aux = ui->comboBox_OpoesMatrizes->findText("Excluir Matriz A");
            if(aux<0){
                ui->comboBox_OpoesMatrizes->insertItem(1,"Excluir Matriz A");
                ui->comboBox_OpoesMatrizes->insertItem(1,"Editar Matriz A");
            }
            ui->tabWidget->setCurrentIndex(0);
            ui->toolBoxResults->setCurrentIndex(1);
            ui->criarA_botton->setDisabled(true);
            setEnableBotton();
        }
        else{
            QMessageBox::warning(this," ","Dimesao inválida");
        }
    }
    catch(QString &erro){
           QMessageBox::warning(this," ",erro);
    }
     catch(std::bad_alloc&){
        QMessageBox::warning(this," ","Falta de memória");
    }
}

void MainWindow::on_criarB_botton_clicked(){
    int linhas = QInputDialog::getInt(this,"Numero de Linhas","Linhas",QLineEdit::Normal);
    int colunas = QInputDialog::getInt(this,"Numero de Colunas","Colunas",QLineEdit::Normal);
    try{
        if(linhas && colunas && linhas > 0 && colunas >0){
            this->matB = new TP2::Matriz<int>(linhas,colunas);
            if(!showInpuScrem(matB,0))
            {
                delete matB;
                matB=0;
                return;
            }
            this->setMatriz_Tela(matB,ui->tableWidget_MatB,2);
            if((int)ui->comboBox_OpoesMatrizes->findText("Excluir Matriz B")<0){//////mudei
                ui->comboBox_OpoesMatrizes->insertItem(1,"Excluir Matriz B");
                ui->comboBox_OpoesMatrizes->insertItem(1,"Editar Matriz B");
            }
            ui->tabWidget->setCurrentIndex(1);
            ui->toolBoxResults->setCurrentIndex(2);
            ui->criarB_botton->setDisabled(true);
            setEnableBotton();
        }
        else{
            QMessageBox::warning(this," ","Dimesao inválida");
        }
    }
    catch(QString &erro){
           QMessageBox::warning(this," ",erro);
    }
     catch(std::bad_alloc&){
        QMessageBox::warning(this," ","Falta de memória");
    }

}

void MainWindow::on_comboBox_OpoesMatrizes_activated(const QString &arg1)
{
    std::string aux;
    aux = arg1.toStdString();
    if(aux == "Excluir Matriz B"){
        delete matB;
        matB=0;
        ui->comboBox_OpoesMatrizes->removeItem(ui->comboBox_OpoesMatrizes->findText("Excluir Matriz B"));
        ui->comboBox_OpoesMatrizes->removeItem(ui->comboBox_OpoesMatrizes->findText("Editar Matriz B"));
        ui->criarB_botton->setDisabled(false);
        setTableDimension(1,1,ui->tableWidget_MatB);
        setDesableBotton(2,0);
    }else if(aux == "Editar Matriz B"){
            showInpuScrem(matB,1);
            setDesableBotton(2,1);
            this->setMatriz_Tela(matB,ui->tableWidget_MatB,2);
            ui->toolBoxResults->setCurrentIndex(2);
    }else if(aux == "Editar Matriz A"){
            showInpuScrem(matA,1);
            setDesableBotton(1,1);
            this->setMatriz_Tela(matA,ui->tableWidget_MatA,1);
            ui->toolBoxResults->setCurrentIndex(1);
    }else if(aux == "Excluir Matriz A"){
            delete matA;
            matA = 0;
            ui->comboBox_OpoesMatrizes->removeItem(ui->comboBox_OpoesMatrizes->findText("Excluir Matriz A"));
            ui->comboBox_OpoesMatrizes->removeItem(ui->comboBox_OpoesMatrizes->findText("Editar Matriz A"));
            ui->criarA_botton->setDisabled(false);
            setTableDimension(1,1,ui->tableWidget_MatA);
            setDesableBotton(1,0);
    }
}

void MainWindow::on_soma_clicked()
{
    try{
        TP2::Matriz<int> *aux;
        aux = *matA+matB;
        this->setMatriz_Tela(aux,ui->tableView_Result,3);
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
            this->setMatriz_Tela(aux,ui->tableView_Result,3);
            delete aux;
        }else if(index ==2){
            aux = *matB*matA;
            this->setMatriz_Tela(aux,ui->tableView_Result,3);
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
            this->setMatriz_Tela(aux,ui->tableView_Result,3);
            delete aux;
        }else if(index == 2){
            if(!matB)
                throw QString("Matriz B não criada");
            aux = matB->getTransposta();
            this->setMatriz_Tela(aux,ui->tableView_Result,3);
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
            aux = (*matA).escalar(k);
            this->setMatriz_Tela(aux,ui->tableView_Result,3);
            delete aux;

        }else if(index == 2){
            if(!matB)
                throw QString("Matriz B não criada");
            int k = QInputDialog::getInt(this,"Constante"," K ",QLineEdit::Normal);
            if(k<0)
                throw QString("Numero Negativo");
            aux = (*matB).escalar(k);
            this->setMatriz_Tela(aux,ui->tableView_Result,3);
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
    try{
        TP2::Matriz<int> *aux;
        if(index == 1){
            if(!matA)
                throw QString("Matriz A não criada");
            int n = QInputDialog::getInt(this,"Constante"," K ",QLineEdit::Normal);
            aux= matA->Mpow(n);
            this->setMatriz_Tela(aux,ui->tableView_Result,3);
            delete aux;
            ui->toolBoxResults->setCurrentIndex(0);
        }
        else if(index == 2){
            if(!matB)
                throw QString("Matriz B não criada");
            int n = QInputDialog::getInt(this,"Constante"," K ",QLineEdit::Normal);
            aux= matB->Mpow(n);
            this->setMatriz_Tela(aux,ui->tableView_Result,3);
            delete aux;
            ui->toolBoxResults->setCurrentIndex(0);
        }
    }
    catch(QString &erro){
        QMessageBox::warning(this,"Erro",erro);
    }
}

void MainWindow::on_subtracao_clicked()
{
    try{
        TP2::Matriz<int> *aux;
        aux = *matA-matB;
        this->setMatriz_Tela(aux,ui->tableView_Result,3);
        ui->toolBoxResults->setCurrentIndex(0);
        delete aux;
    }
    catch(QString &erro){
        QMessageBox::warning(this,"Erro",erro);
    }
}
void MainWindow::on_tabWidget_tabBarClicked(int index){
    if(index==1){
        ui->toolBoxResults->setCurrentIndex(2);
    }
    else{
        ui->toolBoxResults->setCurrentIndex(1);
    }
}
void MainWindow::on_tableView_Result_clicked()
{
    if(!ui->tableView_Result->item(0,0))
        QMessageBox::warning(this,"","Matriz não operada");
    else{
        int op = QMessageBox::question(this,"Opções matriz Resultante","","Cancelar","Limpar",0);
        if(op==0)
            return;
        ui->tableView_Result->clear();
        this->deleteTabela(ui->tableView_Result);
        ui->tableView_Result->setRowCount(1);
        ui->tableView_Result->setColumnCount(1);
        ui->tableWidget_MatA->setFocus();
    }
}
