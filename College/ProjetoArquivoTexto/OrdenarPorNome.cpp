#include "OrdenarPorNome.h"
namespace TP2{//incio
OrdenarPorNome::OrdenarPorNome(QString nomeDoArquivoNoDisco):
    TemplateMethodOrdenacao(nomeDoArquivoNoDisco)
{
}

bool OrdenarPorNome::ePrimeiro(Aluno a, Aluno b)const{
    if(a.getNome() < b.getNome()) return true;
    else return false;
}

}//fim
