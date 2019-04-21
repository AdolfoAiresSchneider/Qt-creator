#ifndef MENUMODELO_H
#define MENUMODELO_H

#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>

#include "GeradorDeId.h"
#include "Modelo.h"
#include "ModeloDAO.h"
#include "Relatorio.h"


namespace Ui {
  class MenuModelo;
}

class MenuModelo : public QDialog
{
  Q_OBJECT

public:
  explicit MenuModelo(QWidget *parent = 0);
  ~MenuModelo();

private slots:

  void on_botaoSair_clicked();
  void on_botaoNovo_clicked();
  void on_botaoCadastrar_clicked();
  void on_botaoBuscar_clicked();
  //void on_botaoEditar_clicked();
  //void on_botaoExcluir_clicked();

private:
  Ui::MenuModelo *ui;

  bia::Modelo modeloAtual;

  /// seta os icones nos botoes
  void setIcones (const QString& diretorio);

  /// disabilita todos os botoes exceto sair
  void disableAll ();

  /// limpa a tela
  void clearAll ();

  /// seta as marcas na box
  void setMarcas ();

};

#endif // MENUMODELO_H
