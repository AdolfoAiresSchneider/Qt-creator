#include "flig.h"

void Flig::setflig(Funcionario *p, long long posic)
{
    this->cpf=p->getcpf();
    this->posicao=posic;
}

Flig::Flig()
{

}

long long Flig::getcpf()
{
    return cpf;

}

int Flig::getposic()
{
    return posicao;

}

void Flig::setposic(int posic)
{
    posicao = posic;

}












