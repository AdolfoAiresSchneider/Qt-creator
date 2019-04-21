#ifndef MENUMARCA_H
#define MENUMARCA_H

#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>

#include "GeradorDeId.h"
#include "MarcaDAO.h"
#include "Relatorio.h"


namespace Ui {
  class MenuMarca;
}

class MenuMarca : public QDialog
{
  Q_OBJECT

public:
  explicit MenuMarca(QWidget *parent = 0);
  ~MenuMarca();

private slots:
  void on_botaoSair_clicked();
  void on_botaoNovo_clicked();
  void on_botaoCadastrar_clicked();
  void on_botaoBuscar_clicked();
  //void on_botaoEditar_clicked();
  //void on_botaoExcluir_clicked();

private:

  Ui::MenuMarca *ui;
  bia::Id idMarcaBuscada;

  /// seta os icones nos botoes
  void setIcones (const QString& diretorio);

  /// desabilita tudo exceto botao sair
  void disableAll ();

  /// limpa tudo
  void clearAll ();

};

#endif // MENUMARCA_H
