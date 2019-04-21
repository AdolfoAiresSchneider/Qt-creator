#include "ClienteDAO.h"
#include <iostream>
using namespace std;
void ClienteDAO::incluir(bia::Cliente &C)const
{
    std::ofstream arq_cliente;

    arq_cliente.open("data/_Clientes.txt",std::ios::out|std::ios::app);
    if(!arq_cliente.is_open()){
        throw QString("Houve um erro! Falha ao abrir arquivo '_Clientes.txt'...");
    }

    ///_____________________________________ GRAVA NO ARQUIVO '_Clientes.txt' ________________________________
    QString str = QString::number(C.getCpf().getCpf()) + ';' +  QString::number(C.getCartaoDeCredito()) + '\n';
    arq_cliente << str.toStdString();
    arq_cliente.close();

    PessoaDAO DAO;
    DAO.incluir(C); // se ele nao existir, ele cria...
}

void ClienteDAO::incluir(std::map<bia::Cpf::cpf_t, bia::Cliente> &M)const
{

    //EXCLUI SOMENTE DO ARQUIVO '_Clientes.txt' .... fora isso , a pessoa ainda existe no sistema!!!!

    std::ofstream arq_cliente;
    PessoaDAO DAO;
    std::map<bia::Cpf::cpf_t,bia::Pessoa> *Pessoas = DAO.listar();
    arq_cliente.open("data/_Clientes.txt",std::ios::out);
    if(!arq_cliente.is_open()){
        throw QString("Houve um erro! Falha ao abrir arquivo '_Clientes.txt'...");
    }

    for(std::map<bia::Cpf::cpf_t,bia::Cliente>::iterator it = M.begin() ; it != M.end() ; ++it){
        bia::Cliente C = it->second;
        QString str = QString::number(C.getCpf().getCpf()) + ';' +  QString::number(C.getCartaoDeCredito()) + '\n';
        arq_cliente << str.toStdString();
        Pessoas->operator [](C.getCpf().getCpf()) = C;
    }
    DAO.incluir(*Pessoas);
    arq_cliente.close();
}

std::map<bia::Cpf::cpf_t, bia::Cliente> *ClienteDAO::listar() const
{
    // abertura do fluxo de leitura
    std::ifstream arq_cliente;
    // valida abertura
    arq_cliente.open("data/_Clientes.txt",std::ios::app);
    if(!arq_cliente.is_open()){
        throw QString("Houve um erro! Falha ao abrir arquivo '_Clientes.txt'...");
    }
    // aloca ponteiro que serar posteriormente retornado
    std::map<bia::Cpf::cpf_t,bia::Cliente> *PtMap = new std::map<bia::Cpf::cpf_t,bia::Cliente>();

    PessoaDAO DAO;
    std::map<bia::Cpf::cpf_t,bia::Pessoa> * M = DAO.listar();

    // _____________________________ VARRE ARQUIVO '_Clientes.txt' ____________________________________
    std::string linha;
    std::getline(arq_cliente,linha);
    while( !arq_cliente.eof() ){
        QString str = QString::fromStdString(linha);
        QStringList camps = str.split(";");
        if(camps.length() != 2){
            throw QString ("Houve um erro! Leitura do arquivo '_Clientes.txt' fora do padrao!");
        }
        PtMap->operator []( camps[0].toLongLong() ) = M->operator [](camps[0].toLongLong() ); // sobreacarga
        PtMap->operator []( camps[0].toLongLong() ).setCartaoDeCredito(camps[1].toLongLong() );
        std::getline(arq_cliente,linha);
    }
    if(M) delete M;
    return PtMap;
}

bia::Cliente ClienteDAO::listar(const bia::Cpf::cpf_t &cpf) const
{
    // abertura do fluxo de leitura
    std::ifstream arq_cliente;
    // valida abertura
    arq_cliente.open("data/_Clientes.txt",std::ios::app);
    if(!arq_cliente.is_open()){
        throw QString("Houve um erro! Falha ao abrir arquivo '_Clientes.txt'...");
    }

    bia::Cliente retorno;

    PessoaDAO DAO;
    std::map<bia::Cpf::cpf_t,bia::Pessoa> * M = DAO.listar();

    // _____________________________ VARRE ARQUIVO '_Clientes.txt' ____________________________________
    std::string linha;
    std::getline(arq_cliente,linha);
    while( !arq_cliente.eof() ){
        QString str = QString::fromStdString(linha);
        QStringList camps = str.split(";");
        if(camps.length() != 2){
            throw QString ("Houve um erro! Leitura do arquivo '_Clientes.txt' fora do padrao!");
        }

        if(cpf == camps[0].toLongLong() ){
            retorno = M->operator [](camps[0].toLongLong());
            retorno.setCartaoDeCredito(camps[1].toLongLong() );
            if(M) delete M;
            arq_cliente.close();
            return retorno;
        }
        std::getline(arq_cliente,linha);
    }
    if(M) delete M;
    arq_cliente.close();
    return retorno;
}

void ClienteDAO::atualizar(const bia::Cliente &C) const
{
    std::map<bia::Cpf::cpf_t,bia::Cliente> *aux = listar();
    if(aux->find(C.getCpf().getCpf()) != aux->end()){
        aux->operator []( C.getCpf().getCpf() ) = C;
        incluir(*aux);
    }
    else
        throw QString("Houve um Erro! o cliente a ser atualizado não existe!");

    if(aux) delete aux;
}

void ClienteDAO::excluir(const bia::Cpf::cpf_t &cpf) const
{
    std::map<bia::Cpf::cpf_t,bia::Cliente> *aux = listar();
    aux->erase(aux->find(cpf));
    incluir(*aux);
    if(aux) delete aux;
}
