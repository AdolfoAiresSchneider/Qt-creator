#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "matriz.h"
#include "inserirmatrizscream.h"
#include <QMainWindow>
#include <QtWidgets/QTableWidget>
#include <QInputDialog>
#include <QMessageBox>
#include <QtWidgets/QTextBrowser>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    void setTableDimension(int linhas, int coluna, QTableWidget * tableWidget );
    void setMatriz_Tela(TP2::Matriz<int> * mat, QTableWidget *tableWidget);
    int showInpuScrem(TP2::Matriz<int> *mat, int editar);
    void getInformationsMatrix(TP2::Matriz<int> * mat, QTextBrowser * textBrowserMat);
    void setEnableBotton();
    void setDesableBotton();


    ~MainWindow();

private slots:

    void on_criarA_botton_clicked();
    void on_criarB_botton_clicked();
    void on_comboBox_OpoesMatrizes_activated(const QString &arg1);
    void on_soma_clicked();
    void on_multiplicacao_activated(int index);
    void on_transopsta_activated(int index);
    void on_Escalar_activated(int index);
    void on_potencia_activated(int index);
    void on_subtracao_clicked();

private:
    Ui::MainWindow *ui;
    TP2::Matriz<int> *matA;
    TP2::Matriz<int> *matB;
};

#endif // MAINWINDOW_H
