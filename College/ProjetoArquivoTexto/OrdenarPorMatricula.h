#ifndef ORDENARPORMATRICULA_H
#define ORDENARPORMATRICULA_H
#include<TemplateMethodOrdenacao.h>

namespace TP2{//incio

class OrdenarPorMatricula: public TemplateMethodOrdenacao
{
public:
    OrdenarPorMatricula(QString nomeDoArquivoNoDisco);
    bool ePrimeiro(Aluno a, Aluno b)const;
};
}//fim
#endif // ORDENARPORMATRICULA_H
