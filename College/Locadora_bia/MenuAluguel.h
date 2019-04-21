#ifndef MENUALUGUEL_H
#define MENUALUGUEL_H

#include "Condutor.h"
#include "CondutorDAO.h"
#include "Relatorio.h"

#include "Aluguel.h"
#include "AluguelDAO.h"

#include "Relatorio.h"

#include "GeradorDeId.h"
#include "telaocorrencias.h"
#include <QDialog>

namespace Ui {
class MenuAluguel;
}

class MenuAluguel : public QDialog
{
    Q_OBJECT

public:

    explicit MenuAluguel(QWidget *parent = 0);
    ~MenuAluguel();
    void setAluguelTela();
    void setAtributeAluguel(bia::Aluguel * al){this->aluguelAtual = *al;}
    void setSearchMode();
    void setCarImageTela(QString Placa);

private slots:

    void on_botaoNovo_clicked();
    void on_botaoSair_clicked();
    void on_pushButtonSelecionarCondutor_clicked();
    void on_pushButtonSelecionarCLiente_clicked();
    void on_calendarWidget_Retirada_activated(const QDate &date);
    void on_calendarWidget_activated(const QDate &date);
    void on_calendarWidget_clicked(const QDate &date);
    void on_calendarWidget_Retirada_clicked(const QDate &date);
    void on_comboBox_Finaldade_activated(const QString &arg1);
    void on_botaoComfirmar_clicked();
    void on_pushButtonEcolherCarro_clicked();
    void on_botaoBuscar_clicked();
    void on_botaoEncerrarAluguel_clicked();
    void LimparTela();
    void setEditMode(bool current);
    void updateValor();
    void validaDados();
    void updateValorTotal();
    void on_Ocorrencia_clicked();
    void on_dateEditRetirada_dateChanged(const QDate &date);
    void on_dateEditDevolucao_dateChanged(const QDate &date);
    void on_botaoLaudo_clicked();

private:

    Ui::MenuAluguel *ui;
    std::map<bia::Cnh::cnh_t , bia::Condutor > * condutores;
    bia::Aluguel  aluguelAtual;
    bia::GeradorDeId Id;
    std::map<int,bia::Aluguel> * alugueis;

};

#endif // ALUGUEL_H
