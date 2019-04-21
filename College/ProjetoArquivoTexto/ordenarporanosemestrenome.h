#ifndef ORDENARPORANOSEMESTRENOME_H
#define ORDENARPORANOSEMESTRENOME_H
#include<TemplateMethodOrdenacao.h>

namespace TP2{
class OrdenarPorAnoSemestreNome : public TemplateMethodOrdenacao
{
public:
    OrdenarPorAnoSemestreNome(QString nomeDoArquivoNoDisco);
    bool ePrimeiro(Aluno a, Aluno b)const;
};
}

#endif // ORDENARPORANOSEMESTRENOME_H
