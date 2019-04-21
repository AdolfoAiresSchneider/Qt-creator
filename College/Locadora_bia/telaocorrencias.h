#ifndef TELAOCORRENCIAS_H
#define TELAOCORRENCIAS_H
#include "Ocorrencia.h"
#include "OcorrenciaDAO.h"

#include <QDialog>

namespace Ui {
class TelaOcorrencias;
}

class TelaOcorrencias : public QDialog
{
    Q_OBJECT

public:
    explicit TelaOcorrencias(QWidget *parent = 0);
    void setOcorrenciaTela(bia::Ocorrencia * o,bool * f){ this->ocorrencia = o;flag = f;}
    ~TelaOcorrencias();

private slots:
    void on_pushButton_clicked();

private:

    Ui::TelaOcorrencias *ui;
    bia::Ocorrencia * ocorrencia;
    bool * flag;
};

#endif // TELAOCORRENCIAS_H
