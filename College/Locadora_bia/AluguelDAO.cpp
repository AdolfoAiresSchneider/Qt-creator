#include "AluguelDAO.h"
#include <fstream>
#include "Cliente.h"
#include "OcorrenciaDAO.h"
#include "TelaPrincipal.h"
#include "ClienteDAO.h"
#include <map>
#include <QStringList>
#include "CondutorDAO.h"
#include "CarroDAO.h"
#include "ClienteDAO.h"
#include <iostream>
using namespace std;



void bia::AluguelDAO::incluir(bia::Aluguel & aluguel)
{
      std::fstream arquivo("data/alugueis.dat", std::ios::out | std::ios_base::app);

      if (!arquivo.is_open())
      {
        throw QString("Falha ao abrir arquivo de alugueis na inclusao ");
      }

      /// ordem arquivo Id | CPF Cl | CPF Co | FINALIDADE | PLACA | DATA R | DATA D | FLAG
      bia::OcorrenciaDAO arqOcorrencias;

      // grava as informaçoes necessarias no arquivo
      arquivo<< aluguel.getIdentificador() << ";"
        << aluguel.getCliente().getCpf().getCpf() <<";"
           << aluguel.getCondutor().getCpf().getCpf() <<";"
              <<aluguel.getFinalidade().toStdString()<< ";"
                 << aluguel.getCarro().getPlaca().getPlaca().toStdString()<<";"
                   <<aluguel.getDataRetirada().toStdString()<<";"
                      <<aluguel.getDataDevolucao().toStdString()<<";"
                         <<aluguel.isAtivo()<<"\n";


      arqOcorrencias.incluir(aluguel.getOcorrencias(),aluguel.getIdentificador());
      arquivo.close();
}


void bia::AluguelDAO::incluir(std::map<int, bia::Aluguel> * alugueis)
{
    std::ofstream arquivo("data/alugueis.dat");
    arquivo.close();

    for(std::map<int,bia::Aluguel>::iterator it = alugueis->begin(); it!=alugueis->end();it++)
    {
        this->incluir(it->second);
    }
}


std::map<int, bia::Aluguel> * bia::AluguelDAO::listar() const
{
    std::ifstream arquivo("data/alugueis.dat",std::ios::app);

    if(!arquivo.is_open())
    {
      throw QString("Não foi possivel abrir o arquivo de ocorrencias na listagem");
    }

    try
    {
        std::vector<bia::Ocorrencia> * ocorrenciasVector;
        std::map<int,bia::Aluguel>  * alugueis;
        std::string linha;
        bia::OcorrenciaDAO arqOcorrencia;
        bia::Aluguel aluguel;
        bia::Carro carro;
        bia::Cliente cliente;
        bia::Condutor condutor;
        bia::CarroDAO ArqCarro;
        CondutorDAO ArqCondutor;
        ClienteDAO ArqCliente;
        QStringList qstrl,data;
        QDate data2;

        alugueis = new  std::map<int,bia::Aluguel>;

        std::getline(arquivo,linha );

        while(!arquivo.eof())
        {
            qstrl = QString::fromStdString(linha).split(';');

            if(qstrl.size()!=8)
            {
              throw QString("Dados de Aluguel corrompidos");
            }

            // Seta todos os atributos que sao procurados e carregados do arquivo repesctivo ao id correto
            aluguel.setId(qstrl[0].toLongLong());
            cliente = ArqCliente.listar(qstrl[1].toLongLong());
            aluguel.setCliente(cliente);
            condutor = ArqCondutor.listar(qstrl[2].toLongLong());
            aluguel.setCondutor(condutor);
            aluguel.setFinalidade(qstrl[3]);
            carro = ArqCarro.listar(qstrl[4]);
            aluguel.setCarro(carro);
            data = qstrl[5].split('/');
            data2.setDate(data[2].toInt(),data[1].toInt(),data[0].toInt());
            aluguel.setDataRetirada(data2);
            data = qstrl[6].split('/');
            data2.setDate(data[2].toInt(),data[1].toInt(),data[0].toInt());
            aluguel.setDataDevolucao(data2);
            ocorrenciasVector = arqOcorrencia.listar(aluguel.getIdentificador());
            aluguel.setOcorrencias(*ocorrenciasVector);

            if(qstrl[7].toInt() == 1)
                aluguel.AtivaAluguel();
            else
                aluguel.DesativaAluguel();
            alugueis->operator [](aluguel.getIdentificador()) = aluguel;

            std::getline(arquivo,linha );
        }

    arquivo.close();
    return alugueis;

    }catch(std::exception & erro)
    {
        arquivo.close();
        throw QString(erro.what());
    }
}

