#ifndef OCORRENCIADAO_H
#define OCORRENCIADAO_H
#include <fstream>
#include "Ocorrencia.h"
#include <vector>


namespace bia{


class OcorrenciaDAO
{
public:

    OcorrenciaDAO(){}

    /// gravar todas as ocorrencias de um aluguel
    void incluir (std::vector<Ocorrencia> &ocorrencias, int id);
    void incluir(bia::Ocorrencia ocorrencia, int id);

    /// lista todas as ocorrencias de um aluguel especifico
    std::vector<Ocorrencia> *listar(int id);

};
}

#endif // OCORRENCIADAO_H
