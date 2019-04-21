#ifndef MENUCARRO_H
#define MENUCARRO_H

#include <map>

#include <QDialog>
#include <QMessageBox>
#include <QInputDialog>

#include "Carro.h"
#include "CarroDAO.h"
#include "CategoriaDoCarro.h"
#include "CategoriaDoCarroDAO.h"
#include "MenuCategoria.h"
#include "MenuMarca.h"
#include "MenuModelo.h"
#include "Relatorio.h"


namespace Ui
{
  class MenuCarro;
}

class MenuCarro : public QDialog
{
  Q_OBJECT

public:

  explicit MenuCarro(QWidget *parent = 0);
  ~MenuCarro();

private slots:

  void on_botaoSair_clicked();
  void on_botaoNovo_clicked();
  void on_botaoBuscar_clicked();
  void on_botaoEditar_clicked();
  void on_botaoExcluir_clicked();
  void on_botaoCadastrar_clicked();


  void on_boxMarca_activated(const QString &arg1);

  void on_pushButton_clicked();

  void on_label_7_linkActivated(const QString &link);

  void on_botaoAddMarca_clicked();

  void on_botaoAddModelo_clicked();

  void on_botaoAddCategoria_clicked();

private:

  int flag;

  Ui::MenuCarro *ui;
  QString end;

  /// seta os icones nos botoes
  void setIcones (const QString& diretorio);

  /// desabilita todos os botoes exceto o sair
  void disableAll ();

  /// reseta todos os valores na tela
  void clearAll ();

  void setMarcas ();

  void setCategorias ();

};

#endif // MENUCARRO_H
