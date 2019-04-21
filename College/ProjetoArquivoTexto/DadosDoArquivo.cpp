#include "DadosDoArquivo.h"

namespace  TP2 {// Inicio

DadosDoArquivo::DadosDoArquivo(QString nomeDoArquivoNoDisco):
    nomeDoArquivoNoDisco(nomeDoArquivoNoDisco)
{
}

std::vector<Aluno>* DadosDoArquivo::obterDadosDoArquivo()const{
    try {
        std::vector<Aluno>* dadosDosAlunos = new std::vector<Aluno>();
        std::ifstream arquivo;
        arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivo.is_open()) throw QString("Erro na Abertura do Arquivo");

        std::string linha;
        std::getline(arquivo,linha);
        while(!arquivo.eof())
        {
            QString linhaAux=QString::fromStdString(linha);
            QStringList lista = linhaAux.split(';');
            if(lista.length()!=3) throw QString("Linha do arquivo faltando dados");
            TP2::Aluno aluno;
            aluno.setMatricula(lista[0]);
            aluno.setNome(lista[1]);
            aluno.setSituacao(lista[2]);
            dadosDosAlunos->push_back(aluno);
            std::getline(arquivo,linha);
        }
        arquivo.close();
        return dadosDosAlunos;
    } catch (QString &erro) {
        throw erro;
    }catch(std::bad_alloc&){
        throw QString("Estrutura de dados vector nao criada");
    }
}


}//fim
