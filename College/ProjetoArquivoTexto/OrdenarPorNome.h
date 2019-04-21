#ifndef ORDENARPORNOME_H
#define ORDENARPORNOME_H
#include<TemplateMethodOrdenacao.h>

namespace TP2{//incio
class OrdenarPorNome: public TemplateMethodOrdenacao
{
public:
    OrdenarPorNome(QString nomeDoArquivoNoDisco);
    bool ePrimeiro(Aluno a, Aluno b)const;
};
}//fim

#endif // ORDENARPORNOME_H
