#ifndef CADASTRARMODELO_H
#define CADASTRARMODELO_H

#include <QDialog>

namespace Ui {
class CadastrarModelo;
}

class CadastrarModelo : public QDialog
{
    Q_OBJECT

public:
    explicit CadastrarModelo(QWidget *parent = 0);
    ~CadastrarModelo();

private:
    Ui::CadastrarModelo *ui;
};

#endif // CADASTRARMODELO_H
