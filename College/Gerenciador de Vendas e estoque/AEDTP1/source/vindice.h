#ifndef VINDICE_H
#define VINDICE_H
#include "cvenda.h"


class no
{
public:
    int posic;
    int cod;

};

class Vindice
{
private:
    int qtd;
    no *vet;

public:
    Vindice();


    int buscab(int pi,int pf,int cod);// utilitaria
    int buscabinaria(int cod);//retorna maior que zero caso encontre, e menor que zero caso nao exista
    int gravarid(CVenda *p,int posicao);//gravar um jogo no indice
    int getqtda();//retorna quantos elementos tem no indice
    void ordenar(no *obj);//ordena o indice toda vez q coloca um jogo nele, caso nao ja exista
    int getposic(int cod);//retorna a posição no arquivao caso ache, caso nao ache retorna negativo
    int getcod(int p);//retorna o nome de um obj do vetor de indice
    void setqtd(int i);


    ~Vindice();
};

#endif // VINDICE_H
