#ifndef CADASTROF_H
#define CADASTROF_H
#include "funcionario.h"

#include <QDialog>

namespace Ui {
class cadastroF;
}

class cadastroF : public QDialog
{
    Q_OBJECT

public:
    explicit cadastroF(QWidget *parent = 0);
    void settela(const char *nome, const char * cpf,const char *cargo);

    ~cadastroF();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_Atualizar_clicked();

private:
    Ui::cadastroF *ui;
    Funcionario *funci;
};

#endif // CADASTROF_H
