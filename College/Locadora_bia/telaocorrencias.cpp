#include "telaocorrencias.h"
#include <QMessageBox>
#include "ui_telaocorrencias.h"
#include <iostream>
using namespace std;

TelaOcorrencias::TelaOcorrencias(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaOcorrencias)
{
    ui->setupUi(this);
}

TelaOcorrencias::~TelaOcorrencias()
{
    delete ui;
}

void TelaOcorrencias::on_pushButton_clicked()
{
    try{
        if(ui->ocorrencia->text().isEmpty())
            throw QString("Ocorrencia invalida, digite alguma coisa");
        this->ocorrencia->setDescricao(ui->ocorrencia->text());
        this->ocorrencia->setValor(ui->doubleSpinBox->value());
        *flag = 1;
        this->close();

    }catch(QString & Erro)
    {
        QMessageBox::warning(this,"",Erro);
    }
}
