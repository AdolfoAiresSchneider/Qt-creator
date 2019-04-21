#ifndef CADASTRARCONDUTOR_H
#define CADASTRARCONDUTOR_H

#include <QDialog>

namespace Ui {
class CadastrarCondutor;
}

class CadastrarCondutor : public QDialog
{
    Q_OBJECT

public:
    explicit CadastrarCondutor(QWidget *parent = 0);
    ~CadastrarCondutor();

private:
    Ui::CadastrarCondutor *ui;
};

#endif // CADASTRARCONDUTOR_H
