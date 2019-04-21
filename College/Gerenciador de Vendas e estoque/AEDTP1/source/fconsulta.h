#ifndef FCONSULTA_H
#define FCONSULTA_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cadastro.h"
#include "arquivo.h"
#include "consulta.h"
#include "ui_consulta.h"
#include "fconsulta.h"

#include <QDialog>

namespace Ui {
class Fconsulta;
}

class Fconsulta : public QDialog
{
    Q_OBJECT

public:
    explicit Fconsulta(QWidget *parent = 0);
    ~Fconsulta();

private slots:
    void on_sair_clicked();

    void on_procurar_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_update_clicked();

private:
    Ui::Fconsulta *ui;
};

#endif // FCONSULTA_H



