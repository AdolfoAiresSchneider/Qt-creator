#ifndef INSERIRMATRIZSCREAM_H
#define INSERIRMATRIZSCREAM_H
#include "matriz.h"
#include <QDialog>

namespace Ui {
class inserirMatrizScream;
}

class inserirMatrizScream : public QDialog
{
    Q_OBJECT

public:

    explicit inserirMatrizScream(QWidget *parent = 0);
    ~inserirMatrizScream();

    void setMat(TP2::Matriz<int> * mat);
    void setDimesion(int linha,int coluna);
    bool getElements();
    void setElements();
    void setcliked(int *i);


private slots:
    void on_pushButton_clicked();

private:
    Ui::inserirMatrizScream *ui;
    TP2::Matriz<int> * mat;
    int linhas;
    int coluna;
    int *cliked;
};

#endif // INSERIRMATRIZSCREAM_H
