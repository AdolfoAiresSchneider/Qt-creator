#ifndef VENDA_H
#define VENDA_H
#include "games.h"
#include "cvenda.h"
#include <QDialog>
#include "vindice.h"
#include <QMenuBar>
#include <QMouseEvent>

namespace Ui {
class venda;
}

class venda : public QDialog ,public games
{
    Q_OBJECT

public:
    explicit venda(QWidget *parent = 0);
    ~venda();

    void removerobjv(games *p);
public slots:

    int getposic(const char *nome1);
private slots:
    void on_fim_clicked();

    void on_adicionar_clicked();

    //Eu
    void on_tableWidget_customContextMenuRequested(const QPoint &pos);
    void cliqueiNaTabela();

    void on_fim_2_clicked();

private:

    Ui::venda *ui;
    int qtd;//qtd da venda em objs
    float soma;//valor total
    games v[15];//reescrever
    games v2[15];//comprados
    int p;//
    QMenu *meuMenu;

};

#endif // VENDA_H
