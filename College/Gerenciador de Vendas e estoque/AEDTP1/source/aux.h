#ifndef AUX_H
#define AUX_H
#include "cvenda.h"
#include <QDialog>

namespace Ui {
class aux;
}

class aux : public QDialog
{
    Q_OBJECT

public:

    explicit aux(QWidget *parent = 0);
    void setgame(CVenda *aux, int i);
    ~aux();

private:
    Ui::aux *ui;
};

#endif // AUX_H
