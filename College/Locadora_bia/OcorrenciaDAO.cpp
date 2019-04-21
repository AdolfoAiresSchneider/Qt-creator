#include "OcorrenciaDAO.h"
#include <QStringList>
#include <iostream>
using namespace std;

void bia::OcorrenciaDAO::   incluir(std::vector<bia::Ocorrencia> & ocorrencias, int id)
{

    std::ofstream arquivo("data/ocorrencias.dat", std::ios_base::app);              // abre o arquivo
    if (!arquivo.is_open())                                               // checa se abriu
    {
      throw QString("Falha ao abrir arquivo de ocorrencias");  // nao abriu : excecao
    }

    for(int i = 0 ; i < (int) ocorrencias.size();i++)
    {
      arquivo << id << ";"<<ocorrencias[i].getDescricao().toStdString()<<";"<<ocorrencias[i].getValor()<<"\n";
    }
    arquivo.close();
}

void bia::OcorrenciaDAO:: incluir(bia::Ocorrencia ocorrencia, int id)
{

    std::ofstream arquivo("data/ocorrencias.dat", std::ios_base::app);              // abre o arquivo
    if (!arquivo.is_open())                                               // checa se abriu
    {
      throw QString("Falha ao abrir arquivo de ocorrencias");  // nao abriu : excecao
    }

      arquivo << id << ";"<<ocorrencia.getDescricao().toStdString()<<";"<<ocorrencia.getValor()<<"\n";
    arquivo.close();
}

std::vector<bia::Ocorrencia> * bia::OcorrenciaDAO::listar(int id)
{
    std::ifstream arquivo("data/ocorrencias.dat",std::ios::app);
    if(!arquivo.is_open())
        throw QString("Não foi possivel abrir o arquivo de ocorrencias");

    std::vector<bia::Ocorrencia>  * ocorrencias;
    try{

        std::string linha;
        bia::Ocorrencia ocorr;
        QStringList qstrl;

        ocorrencias = new  std::vector<bia::Ocorrencia>;

        std::getline(arquivo,linha );
        while(!arquivo.eof())
        {
            qstrl = QString::fromStdString(linha).split(';');
            if(qstrl.size()!=3)
            {
              throw QString("Dados dedd ocorrencia corrompidos");
            }

            if(qstrl[0].toInt() == id)
            {
                ocorr.setDescricao(qstrl[1]);
                ocorr.setValor(qstrl[2].toInt());
                ocorrencias->push_back(ocorr);
            }

            std::getline(arquivo,linha );
        }

    arquivo.close();
    return ocorrencias;

    }catch(std::exception & erro)
    {
        throw QString(erro.what());
    }
}
