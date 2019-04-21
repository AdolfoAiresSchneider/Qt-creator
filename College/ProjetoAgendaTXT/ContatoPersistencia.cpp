#include "ContatoPersistencia.h"
#include <bits/stdc++.h>
using namespace std;
namespace agenda{//inicio
ContatoPersistencia::ContatoPersistencia(QString nomeDoArquivoNoDisco):
    nomeDoArquivoNoDisco(nomeDoArquivoNoDisco)
{

}

void ContatoPersistencia::incluir(Contato &objeto) const{
    std::ofstream arquivoAgenda;
    arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str(),
                                   std::ios::out|std::ios::app);
    if(!arquivoAgenda.is_open()){
        throw QString("Arquivo de Agenda nao foi aberto - Metodo incluir");
    }
    arquivoAgenda<<objeto.desmontarObjeto().toStdString()+"\n";
    arquivoAgenda.close();
    cout<<"123"<<endl;
}

void ContatoPersistencia::excluir(QString nome) const{
    try {
        std::stack<agenda::Contato> pilha;
        std::ifstream arquivoAgenda;
        arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoAgenda.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto");
        }
        std::string linha;
        getline(arquivoAgenda,linha);
        while(!arquivoAgenda.eof()){
            agenda::Contato objeto;
            QString str = QString::fromStdString(linha);
            objeto.montarObjeto(str);
            if(objeto.getNome()!=nome)pilha.push(objeto);
            getline(arquivoAgenda,linha);
        }
        arquivoAgenda.close();
        std::ofstream arquivoAgenda2;
        arquivoAgenda2.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoAgenda2.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto");
        }
        while(!pilha.empty()){
            agenda::Contato objeto = pilha.top();
            arquivoAgenda2<<objeto.desmontarObjeto().toStdString()+"\n";
            pilha.pop();
        }
        cout<<"asd"<<endl;
        arquivoAgenda2.close();
    } catch (QString &erro) {
        throw(erro);
    }
}


void ContatoPersistencia::alterar(Contato &objeto) const
{
    try {
        this->excluir(objeto.getNome());
        this->incluir(objeto);
    }catch (QString &erro){
        throw(erro);
    }
}

// Metodo para comparação dos objetos Contatos a ser
// utilizado pelo metodo sort da list para ordenar
// os contatos da lista
bool operator < (agenda::Contato &p1, agenda::Contato &p2)
{
    if (p1.getNome()<p2.getNome())
        return true;
    else return false;
}

std::list<Contato>* ContatoPersistencia::listagem() const{
    try {
        std::ifstream arquivoAgenda;
        arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoAgenda.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto");
        }
        std::list<agenda::Contato> *lista = new std::list<Contato>();
        std::string linha;
        getline(arquivoAgenda,linha);
        while(!arquivoAgenda.eof()){
            agenda::Contato objeto;
            QString str = QString::fromStdString(linha);
            objeto.montarObjeto(str);
            lista->push_back(objeto);
            getline(arquivoAgenda,linha);
        }
        arquivoAgenda.close();
        lista->sort();
        return lista;
    } catch (QString &erro) {
        throw(erro);
    }
}


}//fim

