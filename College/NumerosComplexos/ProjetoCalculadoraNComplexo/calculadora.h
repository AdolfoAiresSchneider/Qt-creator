#ifndef CALCULADORA_H
#define CALCULADORA_H
#include<NComplexo.h>
#include <QMainWindow>
#include <QMessageBox>
#include <string.h>
#include "NComplexo.h"

namespace Ui {
class Calculadora;
}

class Calculadora : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculadora(QWidget *parent = 0);

    std::pair<float,float> getNumero(int n);

    void setResult(TP2::NComplexo resultado, char operacao);
    void basicOperations(int n);

    ~Calculadora();

private slots:

    void on_a1_clicked();

    void on_a3_clicked();

    void on_radioButton_clicked();

    void on_N2_clicked();

    void on_a2_clicked();

    void on_amais_clicked();

    void on_a4_clicked();

    void on_a5_clicked();

    void on_a6_clicked();

    void on_a0_clicked();

    void on_a7_clicked();

    void on_a8_clicked();

    void on_a9_clicked();

    void on_a0_2_clicked();

    void on_avezes_2_clicked();

    void on_avezes_clicked();

    void on_subtrcao_clicked();

    void on_divisao_clicked();

    void on_negativo_clicked();

    void on_igualdade_clicked();

    void on_back_clicked();

    void on_pushButton_clicked();

private:
    Ui::Calculadora *ui;
    int Numero;

};

#endif // CALCULADORA_H
