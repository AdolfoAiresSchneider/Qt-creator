#include "cvenda.h"
#include <cstring>

CVenda::CVenda()
{

}

void CVenda::setvalor(float v)
{
    valor =v;

}

void CVenda::setqtd(int q)
{
    qtdvet=q;

}

void CVenda::setgames(games *v)
{
    for(int i=0;i<qtdvet;i++)
    {
        vet[i]=v[i];
    }

}

void CVenda::setgame(games *v, int i)
{
    vet[i] = *v;

}

void CVenda::setcod(int cod)
{
    codigo =cod;

}

void CVenda::setvendedor(char *a)
{
    strcpy(this->vendendor,a);

}

void CVenda::getnome(int i,char *nome)
{

    vet[i].getnome(nome);

}

void CVenda::getvendedor(char *a)
{
    strcpy(a,this->vendendor);

}

float CVenda::getvalor()
{
    return valor;

}

int CVenda::getcod()
{
    return this->codigo;
}

int CVenda::getqtd()
{
    return qtdvet;
}
