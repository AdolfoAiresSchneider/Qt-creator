#ifndef DEVOLUCAO_H
#define DEVOLUCAO_H

#include <QDialog>

namespace Ui {
class Devolucao;
}

class Devolucao : public QDialog
{
    Q_OBJECT

public:
    explicit Devolucao(QWidget *parent = 0);
    ~Devolucao();

private:
    Ui::Devolucao *ui;
};

#endif // DEVOLUCAO_H
