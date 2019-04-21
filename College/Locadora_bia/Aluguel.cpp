#include "Aluguel.h"

namespace bia{

Aluguel::Aluguel(int id, QDate retirada, QDate devolucao, QString finalidade) :
    dataRetirada(retirada),dataDevolucao(devolucao),Id(id)
{
    if(finalidade == "Pessoal")
    {
        this->finalidade = Pessoal;
    }
    else
    {
        this->finalidade = Trabalho;
    }
}

double Aluguel::getValorAlugel() const
{
    int dias  = this->dataDevolucao.toJulianDay() - this->dataRetirada.toJulianDay() + 1;
    if(this->finalidade == Pessoal)
        return dias*this->carro.getCategoria().getValorLocacaoPessoal();
    return dias*this->carro.getCategoria().getValorLocacaoTrabalho();
}

 Laudo Aluguel::getLaudo()
{
    QString aux = "CÓDIGO DO ALUGUEL ( " + QString::number(this->Id) + "  )\n\n" ;
    aux += "Cliente : " + cliente.getNome() + " : CPF : " + QString::number(cliente.getCpf().getCpf()) + " \n";
    aux += "Condutor : " + condutor.getNome() + " : CNH : " + QString::number(this->condutor.getCnh().getCnh()) +" \n";
    aux +="-------------------------------------------------------------------------------------------\n";
    aux += "\nOCORRENCIAS :\n\n";

    double valorMultas = 0;

    for(int i = 0; i < (int)this->ocorrencias.size();i++)
    {
        aux += ocorrencias[i].getDescricao() + " \n  -->> Valor : R$ ";
        aux += QString::number(ocorrencias[i].getValor()) + "  \n";
        valorMultas += ocorrencias[i].getValor();
    }
    aux +="\n-------------------------------------------------------------------------------------------\n";
    aux += "\nValor original : R$ " + QString::number(this->getValorAlugel())+"\n";
    aux += "Valor das ocorrencias : R$ " + QString::number(valorMultas)+"\n";
    aux += "Valor Total : R$ " + QString::number(this->getValorAlugel() + valorMultas)+"\n";

    bia::Laudo laudo1;
    laudo1.setDescricao(aux);
    return laudo1;
}

}
