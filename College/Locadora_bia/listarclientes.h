#ifndef LISTARCLIENTES_H
#define LISTARCLIENTES_H
#include <map>
#include "Cliente.h"
#include "ClienteDAO.h"
#include "Cpf.h"

#include <QModelIndex>
#include <QDialog>
#include <iostream>
using namespace std;
namespace Ui {
class ListarClientes;
}

class ListarClientes : public QDialog
{
    Q_OBJECT

public:

    explicit ListarClientes(QWidget *parent = 0);
    ~ListarClientes();

    /// setar um cliente no atributo da tela
    void setCliente(bia::Cliente * c,bool * f){this->cliente = c;flag = f;}

    /// listar os clientes na tela
    void ListarClientesTela();

private slots:

    void on_pushButtonSelecionar_clicked();
    void on_tableWidget_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_procurar_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

private:
    Ui::ListarClientes *ui;
    std::map<bia::Cpf::cpf_t,bia::Cliente> * clientes;
    bia::Cliente * cliente;
    bool * flag;
};

#endif // LISTARCLIENTES_H
