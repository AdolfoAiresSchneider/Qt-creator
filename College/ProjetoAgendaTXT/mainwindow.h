#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<TransformarDados.h>
#include <QMainWindow>
#include<Contato.h>
#include<QMessageBox>
#include<ContatoPersistencia.h>
#include<TelaDeListagem.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void limparTela()const;

private slots:
    void on_pushButtonIncluir_clicked();

    void on_pushButtonExcluir_clicked();

    void on_pushButtonListar_clicked();

    void on_pushButtonAlterar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
