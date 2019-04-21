#ifndef ARQUIVO_H
#define ARQUIVO_H
#include "games.h"
#include "funcionario.h"
#include "cvenda.h"

class arquivo
{
public:
    arquivo();

    void gravarF(games *p);///gravar um jogo no final do  arquivo
    void ler(games *p,int pos);/// le de uma posiçao do arquivo
    void sobrescrever(games *p, int pos);///sobrescreve um obj no arquivo
    int getqtda();


    void FgravarF(Funcionario *p);///gravar um jogo no final do  arquivo
    void Fler(Funcionario *p,int pos);/// le de uma posiçao do arquivo
    void Fsobrescrever(Funcionario *p, int pos);///sobrescreve um obj no arquivo
    int Fgetqtda();


    void VgravarF(CVenda *p);///gravar um jogo no final do  arquivo
    void Vler(CVenda *p,int pos);/// le de uma posiçao do arquivo
    void Vsobrescrever(CVenda *p, int pos);///sobrescreve um obj no arquivo
    int Vgetqtda();


    void criararq();


    void gravaraux(Funcionario *a);
};

#endif // ARQUIVO_H
