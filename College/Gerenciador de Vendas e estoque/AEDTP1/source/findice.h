#ifndef FINDICE_H
#define FINDICE_H
#include "funcionario.h"
#include "flig.h"


class Findice
{
private:

    int qtd;
    Flig * idfuncionario;

public:

    Findice();
   ~Findice();//grava no destrutor

     int buscab(int pi,int pf,long long cpf);// utilitaria
     int buscabinaria(long long cpf);//retorna maior que zero caso encontre, e menor que zero caso nao exista
     int gravarid(Funcionario *p,int posicao);//gravar um jogo no indice
     int getqtda();//retorna quantos elementos tem no indice
     void ordenar(Flig *obj);//ordena o indice toda vez q coloca um jogo nele, caso nao ja exista
     int getposic(long long cpf);//retorna a posição no arquivao caso ache, caso nao ache retorna negativo
     long long getcpf(long long int p);//retorna o nome de um obj do vetor de indice
     void modposicao(long long cpf, int posic);//modifica a posição de um elemento no indice
     void removeid(long long cpf);//remove um elemento do indice
};

#endif // FINDICE_H
