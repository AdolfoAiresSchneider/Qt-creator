#ifndef ORDENARPORSITUACAONOME_H
#define ORDENARPORSITUACAONOME_H
#include<TemplateMethodOrdenacao.h>

namespace TP2{//incio
class OrdenarPorSituacaoNome: public TemplateMethodOrdenacao
{
public:

    OrdenarPorSituacaoNome(QString nomeDoArquivoNoDisco);
    bool ePrimeiro(Aluno a, Aluno b)const;
};
}
#endif // ORDENARPORSITUACAONOME_H
