#include "TemplateMethodOrdenacao.h"

namespace TP2{//inicio
TemplateMethodOrdenacao::TemplateMethodOrdenacao(QString nomeDoArquivoNoDisco):
    dados(0)
{
    try {
        DadosDoArquivo aux(nomeDoArquivoNoDisco);
        dados = aux.obterDadosDoArquivo();
    } catch (QString &erro) {
        throw erro;
    }
}

void TemplateMethodOrdenacao::ordenar()const{
    for (int i = 0; i < dados->size(); i++) {
        for (int j = i; j < dados->size(); j++) {
            if (!ePrimeiro(dados->operator [](i), dados->operator [](j))) {
                std::swap(dados->operator [](i),dados->operator [](j));
            }
        }
    }
}

std::vector<Aluno>* TemplateMethodOrdenacao::obterDadosOrdenado()const{
    ordenar();
    return dados;
}


}//fim
