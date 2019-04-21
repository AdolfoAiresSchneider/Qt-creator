#include "lig.h"
#include "games.h"


lig::lig()
{

}

void lig::setlig(games *p, int posic)
{

    p->getnome(this->nome);
    this->posicao=posic;

}


