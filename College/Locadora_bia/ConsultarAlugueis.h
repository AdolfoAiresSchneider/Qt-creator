#ifndef CONSULTARALUGUEIS_H
#define CONSULTARALUGUEIS_H
#include "Aluguel.h"
#include "AluguelDAO.h"
#include <QDialog>

namespace Ui {
class ConsultarAlugueis;
}

class ConsultarAlugueis : public QDialog
{
    Q_OBJECT

public:
    explicit ConsultarAlugueis(QWidget *parent = 0);
    ~ConsultarAlugueis();

private slots:
    void on_pushButtonPesquisar_clicked();
    void listarAlugueisTela();
    void listarAlugueisTela(QString nome);

    void on_tableWidget_Alugueis_clicked(const QModelIndex &index);

private:
    Ui::ConsultarAlugueis *ui;
    std::map<int,bia::Aluguel> * alugueis;

};

#endif // CONSULTARALUGUEIS_H

