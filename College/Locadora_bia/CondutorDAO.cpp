/**
  NOME DO ARQUIVO CONDUTOR: "_Condutor.txt"
  NOME DO ARQUIVO cnh
 */

#include "CondutorDAO.h"
#include <QStringList>
#include <iostream>
using namespace std;

void CondutorDAO::incluir(bia::Condutor &C) const /// cpf ; cnh ; data emissao(dia;mes;ano) ; data expiracao (dia;mes;ano)
{
    std::ofstream arq_condutor;
    arq_condutor.open("data/_Condutor.txt",std::ios::out|std::ios::app);
    if(!arq_condutor.is_open()){
        throw QString("Houve um erro! Falha ao abrir arquivo '_Condutor.txt'...");
    }

    bia::Cnh cnh = C.getCnh();

    QString str = QString::number(C.getCpf().getCpf()) +
            ';' + QString::number(C.getCnh().getCnh()) +

            ';' + QString::number(cnh.getemissao().day()) +
            ';' + QString::number(cnh.getemissao().month()) +
            ';' + QString::number(cnh.getemissao().year()) +

            ';' + QString::number(cnh.getexpiracao().day()) +
            ';' + QString::number(cnh.getexpiracao().month()) +
            ';' + QString::number(cnh.getexpiracao().year()) +
            '\n';

    arq_condutor << str.toStdString();
    arq_condutor.close();

    PessoaDAO DAO;
    DAO.atualizar(C);
}

void CondutorDAO::incluir(std::map<bia::Cnh::cnh_t, bia::Condutor> &M) const
{
    PessoaDAO DAO;
    std::map<bia::Cnh::cnh_t,bia::Pessoa> *PtMapPessoa = DAO.listar();
    std::ofstream arq_condutor;
    arq_condutor.open("data/_Condutor.txt",std::ios::out);
    if(!arq_condutor.is_open()){
        throw QString("Houve um erro! Falha ao abrir arquivo '_Condutor'...");
    }

    for(std::map<bia::Cnh::cnh_t,bia::Condutor>::iterator it = M.begin() ; it != M.end() ; ++it){
        bia::Condutor C = it->second;
        bia::Cnh cnh = C.getCnh();

        QString str = QString::number(C.getCpf().getCpf()) +
                ';' + QString::number(C.getCnh().getCnh()) +

                ';' + QString::number(cnh.getemissao().day()) +
                ';' + QString::number(cnh.getemissao().month()) +
                ';' + QString::number(cnh.getemissao().year()) +

                ';' + QString::number(cnh.getexpiracao().day()) +
                ';' + QString::number(cnh.getexpiracao().month()) +
                ';' + QString::number(cnh.getexpiracao().year()) +
                '\n';
        arq_condutor << str.toStdString();
        PtMapPessoa->operator [](C.getCpf().getCpf()) = C;
    }

    DAO.incluir( *PtMapPessoa );
    arq_condutor.close();
}

void CondutorDAO::atualizar(const bia::Condutor &C) const
{
    std::map<bia::Cnh::cnh_t,bia::Condutor> * aux = listar();
    aux->operator []( C.getCnh().getCnh() ) = C;
    incluir(*aux);
    if(aux) delete aux;
}

void CondutorDAO::excluir(const bia::Cnh::cnh_t &cnh) const
{
    std::map<bia::Cpf::cpf_t,bia::Condutor > *aux = listar();
    aux->erase(aux->find(cnh));
    incluir(*aux);
    if(aux) delete aux;
}

std::map<bia::Cnh::cnh_t, bia::Condutor> *CondutorDAO::listar() const
{
    std::ifstream arq_condutor;
    arq_condutor.open("data/_Condutor.txt",std::ios::app);
    if(!arq_condutor.is_open()){
        throw QString("Houve um erro! falha ao abrir arquivo '_Condutor.txt'...");
    }

    std::map<bia::Cnh::cnh_t,bia::Condutor >* PtMap = new std::map<bia::Cnh::cnh_t,bia::Condutor>();

    PessoaDAO DAO;
    std::map<bia::Cnh::cnh_t,bia::Pessoa> *M = DAO.listar();


    /// __________________________ VARRE ARQUIVOS '_Condutor.txt' _____________
    std::string linha;
    std::getline(arq_condutor,linha);
    while(!arq_condutor.eof()){
        QString str = QString::fromStdString(linha);
        QStringList camps = str.split( ";" );
        if(camps.length() != 8){
            throw QString("Houve um erro ao ler o arquivo '_Condutor.txt'...");
        }
        bia::Cnh cnh;   /// 2,3,4
                        /// 5,6,7
        QDate aux;
        aux.addDays(camps[2].toInt());
        aux.addMonths(camps[3].toInt());
        aux.addYears(camps[4].toInt());
        cnh.setemissao(aux);

        aux.addDays(camps[5].toInt());
        aux.addMonths(camps[6].toInt());
        aux.addYears(camps[7].toInt());
        cnh.setexpiracao(aux);

        cnh.setCnh(camps[1].toLongLong());

        PtMap->operator []( camps[0].toLongLong() ) = M->operator [](camps[0].toLongLong()); // sobrecarga
        PtMap->operator []( camps[0].toLongLong() ).setCnh(cnh);
        std::getline(arq_condutor,linha);
    }
    if(M) delete M;
    return PtMap;
}

bia::Condutor CondutorDAO::listar(const bia::Cpf::cpf_t &cpf) const
{
    std::ifstream arq_condutor;
    arq_condutor.open("data/_Condutor.txt",std::ios::app);
    if(!arq_condutor.is_open()){
        throw QString("Houve um erro! falha ao abrir arquivo '_Condutor.txt'...");
    }

    bia::Condutor retorno;

    PessoaDAO DAO;
    std::map<bia::Cnh::cnh_t,bia::Pessoa> *M = DAO.listar();


    /// __________________________ VARRE ARQUIVOS '_Condutor.txt' _____________
    std::string linha;
    std::getline(arq_condutor,linha);
    while(!arq_condutor.eof()){
        QString str = QString::fromStdString(linha);
        QStringList camps = str.split( ";" );
        if(camps.length() != 8){
            throw QString("Houve um erro ao ler o arquivo '_Condutor.txt'...");
        }

        if(cpf == camps[0].toLongLong() ){


            bia::Cnh cnh;   /// 2,3,4
                            /// 5,6,7
            QDate aux;
            aux.addDays(camps[2].toInt());
            aux.addMonths(camps[3].toInt());
            aux.addYears(camps[4].toInt());
            cnh.setemissao(aux);

            aux.addDays(camps[5].toInt());
            aux.addMonths(camps[6].toInt());
            aux.addYears(camps[7].toInt());
            cnh.setexpiracao(aux);

            cnh.setCnh(camps[1].toLongLong());

            retorno = M->operator [](camps[0].toLongLong()); // sobrecarga
            retorno.setCnh(cnh);
            arq_condutor.close();
            if(M) delete M;
            return retorno;
        }
        std::getline(arq_condutor,linha);
    }
    if(M) delete M;
    arq_condutor.close();
    return bia::Condutor();

}


