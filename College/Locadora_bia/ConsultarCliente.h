#ifndef CONSULTARCLIENTE_H
#define CONSULTARCLIENTE_H

#include <QDialog>

namespace Ui {
class ConsultarCliente;
}

class ConsultarCliente : public QDialog
{
    Q_OBJECT

public:
    explicit ConsultarCliente(QWidget *parent = 0);
    ~ConsultarCliente();

private slots:
    void on_pushButtonPesquisar_clicked();

private:
    Ui::ConsultarCliente *ui;
};

#endif // CONSULTARCLIENTE_H
