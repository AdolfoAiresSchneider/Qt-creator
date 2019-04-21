#include "ordenarporsituacaonome.h"
namespace TP2{

OrdenarPorSituacaoNome::OrdenarPorSituacaoNome(QString nomeDoArquivoNoDisco):
    TemplateMethodOrdenacao(nomeDoArquivoNoDisco)
{

}

bool OrdenarPorSituacaoNome::ePrimeiro(Aluno a, Aluno b) const
{
    return a.getSituacao() > b.getSituacao() || !(a.getSituacao() > b.getSituacao()) && a.getNome()<b.getNome();

}


}
