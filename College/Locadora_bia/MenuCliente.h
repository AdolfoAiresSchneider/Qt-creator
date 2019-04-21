#ifndef MENUCLIENTE_H
#define MENUCLIENTE_H

#include <QDialog>
#include "Pessoa.h"
#include "Cliente.h"
#include "Relatorio.h"

namespace Ui {
class MenuCliente;
}

class MenuCliente : public QDialog
{
    Q_OBJECT

public:
    explicit MenuCliente(QWidget *parent = 0);
    ~MenuCliente();

    void setBotons(const bool Cadastrar,const bool Novo, const bool Buscar,const bool Editar ,const bool Excluir)const;
    void LimpaCampos() const;
    void setInf(bia::Cliente &A) const;
    void setTelefone(bia::Telefone &T)const;
    void getinf(bia::Cliente &C) const;
    void EnabledBotons(const bool sit)const;
    void setDadosPessoa(bia::Pessoa &P);


private slots:
    void on_botaoSair_clicked();

    void on_botaoCadastrar_clicked();

    void on_botaoBuscar_clicked();

    void on_botaoNovo_clicked();

    void on_botaoEditar_clicked();

    void on_botaoExcluir_clicked();

    void on_pushButton_clicked();

private:
    Ui::MenuCliente *ui;
};

#endif // CLIENTE_H
