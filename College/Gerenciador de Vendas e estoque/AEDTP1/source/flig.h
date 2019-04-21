#ifndef FLIG_H
#define FLIG_H
#include "funcionario.h"

class Flig
{
private:

    int posicao;
    long long cpf;

public:

    Flig();
    long long getcpf();
    int getposic();
    void setposic(int posic);
    void setflig(Funcionario *p,long long  posic);
};

#endif // FLIG_H
