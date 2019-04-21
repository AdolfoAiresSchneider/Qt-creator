#ifndef CRUD_H
#define CRUD_H
#include<Contato.h>
#include<list>
namespace agenda{//inicio
class CRUD
{
public:
    virtual void incluir(Contato &objeto) const = 0;
    virtual void excluir(QString nome) const =0;
    virtual void alterar(Contato &objeto) const =0;
    virtual std::list<Contato>* listagem() const = 0;
};
}//fim
#endif // CRUD_H
