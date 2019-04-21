#ifndef MENUCONDUTOR_H
#define MENUCONDUTOR_H

#include <QDialog>
#include "Condutor.h"
#include "Relatorio.h"

namespace Ui {
class MenuCondutor;
}

class MenuCondutor : public QDialog
{
    Q_OBJECT

public:
    explicit MenuCondutor(QWidget *parent = 0);
    ~MenuCondutor();
    void setEditMode(const bool e);
    void setBotons(const bool Cadrastrar,const bool Novo, const bool Buscar, const bool Editar, const bool Excluir)const;
    void setInf(bia::Condutor &A)const;
    void getInf(bia::Condutor &C)const;
    void setTelefone(bia::Telefone &T)const;
    void limpaCampos()const;
    void setDadosPessoa(bia::Pessoa &P);
private slots:
    void on_botaoCadastrar_clicked();

    void on_botaoNovo_clicked();

    void on_botaoBuscar_clicked();

    void on_botaoEditar_clicked();

    void on_botaoExcluir_clicked();

    void on_botaoSair_clicked();

    void on_PushButtonInsertCpf_clicked();

private:
    Ui::MenuCondutor *ui;
};

#endif // MENUCONDUTOR_H
