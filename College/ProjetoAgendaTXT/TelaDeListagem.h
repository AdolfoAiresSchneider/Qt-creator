#ifndef TELADELISTAGEM_H
#define TELADELISTAGEM_H

#include <QDialog>
#include<ContatoPersistencia.h>
#include<Contato.h>
#include<list>
#include<QMessageBox>
namespace Ui {
class TelaDeListagem;
}

class TelaDeListagem : public QDialog
{
    Q_OBJECT

public:
    explicit TelaDeListagem(QWidget *parent = 0);
    ~TelaDeListagem();

private slots:
    void on_pushButtonVoltar_clicked();

    void on_pushButtonListar_clicked();

private:
    Ui::TelaDeListagem *ui;
};

#endif // TELADELISTAGEM_H
