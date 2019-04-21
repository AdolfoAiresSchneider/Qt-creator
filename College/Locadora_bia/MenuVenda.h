#ifndef MENUVENDA_H
#define MENUVENDA_H
#include "listarcarros.h"
#include "listarclientes.h"
#include "Venda.h"
#include "VendaDAO.h"
#include "Carro.h"
#include "CarroDAO.h"
#include "Cliente.h"
#include "ClienteDAO.h"
#include "GeradorDeId.h"
#include "Relatorio.h"
#include <map>
#include <QDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <qicon.h>


namespace Ui {
class MenuVenda;
}

class MenuVenda : public QDialog
{
    Q_OBJECT

public:
    explicit MenuVenda(QWidget *parent = 0);
    ~MenuVenda();


private slots:
    void LimpaCampos()const;
    void setEditMode(const bool &cur);
    void setBottons(const bool &Novo, const bool &Buscar , const bool &Concluir ) const;
    void setVenda();
    void ValidaDados()const;

    void on_botaoSelecionaCliente_clicked();

    void on_botaoEscolheCarro_clicked();

    void on_botaoNovo_clicked();

    void on_botaoSair_clicked();

    void on_botaoBuscar_clicked();

    void on_botaoConcluir_clicked();

private:
    Ui::MenuVenda *ui;
    bia::GeradorDeId Id;
    bia::Venda venda;
    std::map<int,bia::Venda> *MapVendas;
};

#endif // MENUVENDA_H
