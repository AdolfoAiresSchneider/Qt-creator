#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H

#include <QMainWindow>
#include<DadosDoArquivo.h>
#include<QMessageBox>
#include<OrdenarPorNome.h>
#include<OrdenarPorMatricula.h>
#include "ordenarporsituacaonome.h"
#include "ordenarporanosemestrenome.h"

namespace Ui {
class TelaPrincipal;
}

class TelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit TelaPrincipal(QWidget *parent = 0);
    ~TelaPrincipal();

private slots:
    void on_pushButtonNome_clicked();

    void on_pushButtonGeral_clicked();

    void on_pushButtonLimpar_clicked();

    void on_pushButtonMatricula_clicked();

    void on_pushButton_anosemestrenome_clicked();

    void on_pushButton_clicked();

private:
    //Metodos
    void MostrarDadosNaTela(std::vector<TP2::Aluno>* dados)const;
private:
    Ui::TelaPrincipal *ui;
    QString nomeDoArquivo;
};

#endif // TELAPRINCIPAL_H
