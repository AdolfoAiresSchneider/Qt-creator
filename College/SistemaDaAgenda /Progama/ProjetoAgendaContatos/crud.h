#ifndef CRUD_H
#define CRUD_H
#include "Contato.h"
#include <vector>


class CRUD
{
public:
    virtual void incluir(TP2::Contato & obj) const  = 0;
    virtual std::vector<TP2::Contato> * listagem() const = 0;
};

#endif // CRUD_H
