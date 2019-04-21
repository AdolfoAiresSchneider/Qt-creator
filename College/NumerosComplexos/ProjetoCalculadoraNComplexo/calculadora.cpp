#include "calculadora.h"
#include "ui_calculadora.h"

Calculadora::Calculadora(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculadora)
{
    ui->setupUi(this);
    this->Numero = 1;
}

std::pair<float, float> Calculadora::getNumero(int n)
{
    QString conversor;
    std::string aux;
    std::pair<float,float> NC;  ///Numero complexo

    NC.first =0;
    NC.second = 0;

    if(n == 1)
        {aux = ui->NC1->text().toStdString().c_str();}
    else
    {
        if(n==2)
            {aux = ui->NC2->text().toStdString().c_str();}
        else
            {throw 2;}
    }

    if(aux.size() == 0)
        throw 3;

    aux.push_back('Z');///  flag

    while(!aux.empty())
    {
        while(aux.front() != '+' && aux.front() != '-' && aux.front() != 'i' && aux.front()!= 'Z')
        {
            conversor.push_back(aux.front());
            aux.erase(aux.begin());
        }

        switch (aux.front()) {
        case '+':

            NC.first += conversor.toFloat();
            aux.erase(aux.begin());

            if(aux.front() == '+'||aux.front() == '-')
                throw 5;

            conversor.clear();
            break;
        case '-':

            NC.first += conversor.toFloat();
            aux.erase(aux.begin());

             if(aux.front() == '+'||aux.front() == '-')
                 throw 5;

            conversor.clear();
            conversor.push_back('-');
            break;
        case 'i':

            if(conversor.size() == 0 || *conversor.begin() == '-')
            {
                conversor.push_back("1");
                NC.second += conversor.toFloat();
            }
            else
                NC.second += conversor.toFloat();
            aux.erase(aux.begin());

            if(aux.front() != '+' && aux.front() != '-' && aux.front() != 'Z'  )
                throw 5;

            conversor.clear();
            break;
        case 'Z':

            if(conversor.size() != 0)
                NC.first += conversor.toFloat();
            aux.clear();
            conversor.clear();
            break;
        default:
            break;
        }
    }
    return NC;
}

void Calculadora::setResult(TP2::NComplexo resultado,char operacao)
{
    QString exibir;
    std::pair<float,float> NC;

    NC = resultado.getNC();

    exibir.push_back(ui->NC1->text());
    exibir.push_back("  ");
    exibir.push_back(operacao);
    exibir.push_back("  ");
    exibir.push_back(ui->NC2->text());
    exibir.push_back("  =  ");
    exibir.push_back(QString::number(NC.first));
    exibir.push_back(" + (");
    exibir.push_back(QString::number(NC.second));
    exibir.push_back(") i ");

    ui->listWidget->insertItem(0,exibir);

}

void Calculadora::basicOperations(int n)
{
    TP2::NComplexo N1,N2,Result;
    std::pair<float,float> aux;
    char operacao;

    aux = this->getNumero(1);
    N1.set(aux.first,aux.second);
    aux = this->getNumero(2);
    N2.set(aux.first,aux.second);

    switch (n)
    {
        case 1:
            Result = N1+N2;
            operacao = '+';
            break;
        case 2:
            Result = N1-N2;
            operacao = '-';
            break;
        case 3:
            Result = N1*N2;
            operacao = '*';
            break;
        case 4:
            Result = N1/N2;
            operacao = '/';
            break;
        default:
            throw 1;
        break;
    }

    setResult(Result,operacao);
}


Calculadora::~Calculadora()
{
    delete ui;
}

void Calculadora::on_a1_clicked()
{

    if(this->Numero == 1)
    {
        ui->NC1->insert("1");
    }
    else
    {
        ui->NC2->insert("1");
    }
}

void Calculadora::on_a3_clicked()
{
    if(this->Numero == 1)
    {
        ui->NC1->insert("3");
    }
    else
    {
        ui->NC2->insert("3");
    }
}

void Calculadora::on_radioButton_clicked()
{
    this->Numero = 1;
}

void Calculadora::on_N2_clicked()
{
    this->Numero = 2;
}

void Calculadora::on_a2_clicked()
{
    if(this->Numero == 1)
    {
        ui->NC1->insert("2");
    }
    else
    {
        ui->NC2->insert("2");
    }
}

void Calculadora::on_amais_clicked()
{
    if(this->Numero == 1)
    {
        ui->NC1->insert("+");
    }
    else
    {
        ui->NC2->insert("+");
    }
}

void Calculadora::on_a4_clicked()
{
    if(this->Numero == 1)
    {
        ui->NC1->insert("4");
    }
    else
    {
        ui->NC2->insert("4");
    }
}

void Calculadora::on_a5_clicked()
{
    if(this->Numero == 1)
    {
        ui->NC1->insert("5");
    }
    else
    {
        ui->NC2->insert("5");
    }
}

void Calculadora::on_a6_clicked()
{
    if(this->Numero == 1)
    {
        ui->NC1->insert("6");
    }
    else
    {
        ui->NC2->insert("6");
    }
}

void Calculadora::on_a0_clicked()
{
    if(this->Numero == 1)
    {
        ui->NC1->insert("0");
    }
    else
    {
        ui->NC2->insert("0");
    }
}

void Calculadora::on_a7_clicked()
{
    if(this->Numero == 1)
    {
        ui->NC1->insert("7");
    }
    else
    {
        ui->NC2->insert("7");
    }
}

void Calculadora::on_a8_clicked()
{
    if(this->Numero == 1)
    {
        ui->NC1->insert("8");
    }
    else
    {
        ui->NC2->insert("8");
    }
}

void Calculadora::on_a9_clicked()
{
    if(this->Numero == 1)
    {
        ui->NC1->insert("9");
    }
    else
    {
        ui->NC2->insert("9");
    }
}

void Calculadora::on_a0_2_clicked()
{
    if(this->Numero == 1)
    {
        ui->NC1->insert("i");
    }
    else
    {
        ui->NC2->insert("i");
    }
}

void Calculadora::on_avezes_2_clicked()
{
    try
    {
        this->basicOperations(1);
    }
    catch(int i)
    {
        QMessageBox::warning(this,"Erro","Numero inválido")    ;
    }
}

void Calculadora::on_avezes_clicked()
{
    try
    {
        this->basicOperations(3);
    }
    catch(int i)
    {
        QMessageBox::warning(this,"Erro","Numero inválido")    ;
    }
}

void Calculadora::on_subtrcao_clicked()
{
    try
    {
        this->basicOperations(2);
    }
    catch(int i)
    {
        QMessageBox::warning(this,"Erro","Numero inválido")    ;
    }
}

void Calculadora::on_divisao_clicked()
{
    try
    {
        this->basicOperations(4);
    }
    catch(int i)
    {
        if(i == 0)
            QMessageBox::warning(this,"Erro","Divisão por zero");
        else
            QMessageBox::warning(this,"Erro","Numero inválido");
    }
}

void Calculadora::on_negativo_clicked()
{
    if(this->Numero == 1)
    {
        ui->NC1->insert("-");
    }
    else
    {
        ui->NC2->insert("-");
    }
}

void Calculadora::on_igualdade_clicked()
{
    TP2::NComplexo N1,N2;
    std::pair<float,float> aux;

    try{
        aux = this->getNumero(1);
        N1.set(aux.first,aux.second);
        aux = this->getNumero(2);
        N2.set(aux.first,aux.second);
        if(N1 == N2)
            QMessageBox::information(this," ","Numeros iguais!");
        else
            QMessageBox::information(this," ","Numeros diferentes!");
    }
    catch(...)
    {
        QMessageBox::warning(this,"Erro","Numero inválido")    ;
    }
}

void Calculadora::on_back_clicked()
{
    QString aux;
    if(this->Numero == 1)
    {
        aux =ui->NC1->text();
        aux.remove(aux.size()-1,aux.size());
        ui->NC1->clear();
        ui->NC1->insert(aux);
    }
    else
    {
        aux =ui->NC2->text();
        aux.remove(aux.size()-1,aux.size());
        ui->NC2->clear();
        ui->NC2->insert(aux);
    }
}

void Calculadora::on_pushButton_clicked()
{
    ui->listWidget->clear();
}
