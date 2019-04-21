#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H

#include <QMainWindow>
#include "CadastrarMarca.h"
#include "CadastrarModelo.h"
#include "MenuAluguel.h"
#include "Venda.h"
#include "MenuCarro.h"
#include <QMainWindow>
#include "CadastrarMarca.h"
#include "CadastrarModelo.h"
#include "MenuAluguel.h"
#include "Venda.h"
#include "MenuCarro.h"
#include "MenuCategoria.h"
#include "MenuModelo.h"
#include "Cliente.h"


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


    void on_botaoCliente_clicked();

    void on_botaoCarro_clicked();

    void on_botaoAlugar_clicked();

    void on_botaoCondutor_clicked();

    void on_botaoConsultarAlugueis_clicked();




    void on_botaoCadastrarCondutor_clicked();

    void on_botaoModelos_clicked();

    void on_botaoMarcas_clicked();

    void on_botaoCategoria_clicked();

    void on_botaoVenda_clicked();

private:
    Ui::TelaPrincipal *ui;
};

#endif // TELAPRINCIPAL_H
