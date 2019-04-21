#include "ordenarporanosemestrenome.h"


namespace TP2{

OrdenarPorAnoSemestreNome::OrdenarPorAnoSemestreNome(QString nomeDoArquivoNoDisco):
    TemplateMethodOrdenacao(nomeDoArquivoNoDisco)
{

}

bool OrdenarPorAnoSemestreNome::ePrimeiro(Aluno a, Aluno b) const
{
    int anoA = a.getMatricula().remove(4,10).toInt();
    int anoB = b.getMatricula().remove(4,10).toInt();
    return anoA<anoB || (!(anoA>anoB)&&a.getMatricula()[4]<b.getMatricula()[4]) ||
            ((!(anoA>anoB) && !(a.getMatricula()[4]>b.getMatricula()[4])) && a.getNome()<b.getNome());
}
}
