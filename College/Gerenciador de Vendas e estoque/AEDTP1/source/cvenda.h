#ifndef CVENDA_H
#define CVENDA_H
#include "games.h"
#include <cstring>
#include <iostream>
using namespace std;


class CVenda
{
private:

    float valor;
    int codigo;
    char vendendor[30];
    int qtdvet;

public:
    games vet[10];

    void setvalor(float v);
    void setqtd(int q);
    void setgames(games *v);
    void setgame(games *v, int i);
    void setcod(int cod);
    void setvendedor(char *a);

    void getnome(int i, char *nome);
    int getcod();
    int getqtd();
    void getvendedor(char *a);
    float getvalor();

    CVenda();

};

#endif // CVENDA_H
