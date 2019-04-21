#ifndef MENUCATEGORIA_H
#define MENUCATEGORIA_H

#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>

#include "CategoriaDoCarro.h"
#include "CategoriaDoCarroDAO.h"
#include "GeradorDeId.h"
#include "Relatorio.h"


namespace Ui {
  class MenuCategoria;
}

class MenuCategoria : public QDialog
{
  Q_OBJECT

public:
  explicit MenuCategoria(QWidget *parent = 0);
  ~MenuCategoria();

private slots:

  void on_botaoSair_clicked();
  void on_botaoNovo_clicked();
  void on_botaoCadastrar_clicked();
  void on_botaoBuscar_clicked();
  //void on_botaoEditar_clicked();
  //void on_botaoExcluir_clicked();

private:

  Ui::MenuCategoria *ui;
  bia::CategoriaDoCarro categoriaAtual;

  /// seta os icones nos botoes
  void setIcones (const QString &diretorio);

  /// disabilita todos os botoes
  void disableAll ();

  /// limpa a tela
  void clearAll ();

};

#endif // MENUCATEGORIA_H
