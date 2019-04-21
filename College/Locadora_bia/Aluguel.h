#ifndef ALUGUEL_H
#define ALUGUEL_H
#include "Cliente.h"
#include "Condutor.h"
#include "Carro.h"
#include <QDate>
#include <vector>
#include "Ocorrencia.h"
#include "Laudo.h"


namespace bia{

class Aluguel
{

public:

    enum Finalidade
    {
      tipo_null = 0,
      Trabalho,
      Pessoal,
    };

    Aluguel(int id,QDate retirada, QDate devolucao, QString finalidade);

    Aluguel(){}

    // seta um vector de ocorrencias
    void setOcorrencias(std::vector<bia::Ocorrencia> & ocorrencias)
    {
      this->ocorrencias = ocorrencias;
    }

    // seta uma ocorrencia
    void setOcorrencia(bia::Ocorrencia const & ocorrencia)
    {
      this->ocorrencias.push_back(ocorrencia);
    }

    // seta o identificador
    void setId(long long const & identificador)
    {
      this->Id = identificador;
    }

    // retorna o identificador
    long long getIdentificador() const
    {
      return this->Id;
    }

    // retorna o valor do aluguel
    double getValorAlugel() const;

    // retorna a finalidade do aluguel
    QString const getFinalidade() const
    {
        if(this->finalidade == Trabalho) return QString("Trabalho");
        return QString("Pessoal");
    }

    // seta a finalidade do aluguel
    void setFinalidade(QString const & finalidade)
    {
        if(finalidade == "Pessoal") this->finalidade = Pessoal;
        else  this->finalidade = Trabalho;
    }

    // Retorna um laudo de todas as ocorrencias e seu valor total
     Laudo getLaudo();

    // seta e valida a data de retirada
    void setDataRetirada(QDate const & data )
    {
        if(!data.isValid()) throw QString("Data Invalida");
        this->dataRetirada = data;
    }

    // seta e valida a data de devolucao
    void setDataDevolucao(QDate const & data )
    {
        if(!data.isValid()) throw QString("Data Invalida");
        this->dataDevolucao = data;
    }

    // retorna a data de retirada em texto
    QString getDataRetirada() const
    {
      return this->dataRetirada.toString("d/M/yyyy");
    }

    // retorna a data de devoluçao em texto
    QString getDataDevolucao() const
    {
      return this->dataDevolucao.toString("d/M/yyyy");
    }

    // seta um unico carro
    void setCarro(bia::Carro const & carro)
    {
      this->carro = carro;
    }

    // retorna o carro do aluguel
    bia::Carro  const & getCarro() const
    {
      return this->carro;
    }

    // seta o cliente
    void setCliente(bia::Cliente const & cliente)
    {
      this->cliente = cliente;
    }

    // seta o condutor
    void setCondutor(bia::Condutor const & condutor)
    {
      this->condutor = condutor;
    }

    // retorna o condutor
    bia::Condutor getCondutor()
    {
      return this->condutor;
    }

    // retorna o cliente
    bia::Cliente getCliente()
    {
      return cliente;
    }

    // retorna todas as ocorrencias do aluguel
    std::vector<bia::Ocorrencia> & getOcorrencias()
    {
        return this->ocorrencias;
    }

    // ativa o aluguel
    void AtivaAluguel()
    {
      this->ativo = true;
    }

    // desativa o alguel
    void DesativaAluguel()
    {
      this->ativo = false;
    }

    // retorna se o aluguel esta ativo
    bool isAtivo()
    {
      return this->ativo;
    }

    // retorna a data de devoluçao
    QDate getDataDevolucaoQdate()
    {
      return this->dataDevolucao;
    }

    // retorna a data de retirada
    QDate getDataRetiradaQdate()
    {
      return this->dataRetirada;
    }


private:

    std::vector<bia::Ocorrencia> ocorrencias;   /// Ocorrencias de uma aluguel-------------------------------------

    Finalidade finalidade;                      /// Finalidade do aluguel------------------------------------------

    bia::Condutor condutor;                     /// Condutor-------------------------------------------------------
    bia::Cliente cliente;                       /// Cliente--------------------------------------------------------
    bia::Carro carro;                           /// Carros alugados------------------------------------------------

    QDate dataRetirada;                         /// Data do inicio do aluguel--------------------------------------
    QDate dataDevolucao;                        /// Data do fim do aluguel-----------------------------------------

    bool  ativo;                                /// Se o aluguel esta ativo ou nao---------------------------------

    int Id;                                     /// Identificação do aluguel---------------------------------------

};

}

#endif // ALUGUEL_H
