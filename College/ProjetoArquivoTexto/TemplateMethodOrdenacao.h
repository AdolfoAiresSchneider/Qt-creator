#ifndef TEMPLATEMETHODORDENACAO_H
#define TEMPLATEMETHODORDENACAO_H
#include<DadosDoArquivo.h>

namespace TP2{//inicio
class TemplateMethodOrdenacao
{
private:
    std::vector<Aluno>* dados;
public:
    TemplateMethodOrdenacao(QString nomeDoArquivoNoDisco);
    virtual bool ePrimeiro(Aluno a, Aluno b)const=0;
    void ordenar()const;
    std::vector<Aluno>* obterDadosOrdenado()const;

};
}//fim
#endif // TEMPLATEMETHODORDENACAO_H
