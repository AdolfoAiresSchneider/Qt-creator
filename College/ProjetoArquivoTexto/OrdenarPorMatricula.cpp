#include "OrdenarPorMatricula.h"
namespace TP2{//inicio

OrdenarPorMatricula::OrdenarPorMatricula(QString nomeDoArquivoNoDisco):
    TemplateMethodOrdenacao(nomeDoArquivoNoDisco)
{

}

bool OrdenarPorMatricula::ePrimeiro(Aluno a, Aluno b)const{
    if(a.getMatricula() < b.getMatricula()) return true;
    else return false;
}

}//fim
