#include "games.h"
#ifndef LIG_H
#define LIG_H



class lig
{
public:

    int posicao;
    char nome[30];

public:

      lig();
      void setlig(games *p,int posic);///cria um lig

};
#endif // LIG_H
