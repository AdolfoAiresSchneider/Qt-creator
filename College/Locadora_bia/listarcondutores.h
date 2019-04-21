#ifndef LISTARCONDUTORES_H
#define LISTARCONDUTORES_H
#include "Condutor.h"
#include "CondutorDAO.h"
#include <map>
#include <QModelIndex>
#include <QDialog>

namespace Ui {
class ListarCondutores;
}

class ListarCondutores : public QDialog
{
    Q_OBJECT

public:

    explicit ListarCondutores(QWidget *parent = 0);

    /// listar os contatos na tela
    void listarContatosTela();

    ///  setar o condutor no atributo tela
    void setCondutor(bia::Condutor * condutor,bool * flag){this->condut = condutor;this->flag = flag;}

    ~ListarCondutores();

private slots:

    void on_pushButtonSelecionar_clicked();
    void on_tableWidget_clicked(const QModelIndex &index);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_procurar_clicked();

private:

    Ui::ListarCondutores *ui;

    std::map<long long, bia::Condutor> * condutores;
    bia::Condutor * condut;
    bool * flag;

};

#endif // LISTARCONDUTORES_H

