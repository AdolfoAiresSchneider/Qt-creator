#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H
#include<QMessageBox>
#include<Telefone.h>
#include<Contato.h>
#include<vector>
#include<iostream>

#include <QMainWindow>

namespace Ui {
class TelaPrincipal;
}

class TelaPrincipal : public QMainWindow
{
    Q_OBJECT
public:
    explicit TelaPrincipal(QWidget *parent = 0);
    ~TelaPrincipal();
private slots:
    void on_pushButtonTeste_clicked();

private:
    Ui::TelaPrincipal *ui;
};

#endif // TELAPRINCIPAL_H
