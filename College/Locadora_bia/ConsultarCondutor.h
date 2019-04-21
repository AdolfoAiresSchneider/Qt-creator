#ifndef CONSULTARCONDUTOR_H
#define CONSULTARCONDUTOR_H

#include <QDialog>

namespace Ui {
class ConsultarCondutor;
}

class ConsultarCondutor : public QDialog
{
    Q_OBJECT

public:
    explicit ConsultarCondutor(QWidget *parent = 0);
    ~ConsultarCondutor();

private:
    Ui::ConsultarCondutor *ui;
};

#endif // CONSULTARCONDUTOR_H
