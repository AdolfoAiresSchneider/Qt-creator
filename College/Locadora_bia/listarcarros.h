#ifndef LISTARCARROS_H
#define LISTARCARROS_H
#include "CategoriaDoCarro.h"
#include "CategoriaDoCarroDAO.h"
#include "Carro.h"
#include "CarroDAO.h"
#include "Placa.h"
#include <QModelIndex>


#include <QDialog>

namespace Ui {
class ListarCarros;
}

class ListarCarros : public QDialog
{
    Q_OBJECT

public:

    explicit ListarCarros(QWidget *parent = 0);

    /// colocar carros no atributo da tela
    void setCarro(bia::Carro * carro,bool * b){  this->carro = carro;this->flag = b; *this->flag = false; }

    /// colocar categorias na tela
    void setCategorias();

    /// listar os carros na tela
    void setCarros(QString categoria);

    ~ListarCarros();

private slots:

    void on_comboBoxCategorias_activated(const QString &arg1);
    void on_tableWidget_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButtonSelecionar_clicked();

private:

    Ui::ListarCarros *ui;

    std::map<bia::Id,bia::CategoriaDoCarro>  * categorias;
    std::map<bia::Placa,bia::Carro> * carros;
    bia::Carro * carro;
    bool * flag;

};

#endif // LISTARCARROS_H
