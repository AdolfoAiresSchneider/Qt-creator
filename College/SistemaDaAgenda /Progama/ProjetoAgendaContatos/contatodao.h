#ifndef CONTATODAO_H
#define CONTATODAO_H
#include "crud.h"
#include <qstring.h>
#include<fstream>



class ContatoDAO : public CRUD
{
private:
    QString nomeaArqContatos;
public:

    ContatoDAO(QString nomeaArqContatos,QString nomeaArqTelefones);
    void incluir(TP2::Contato & obj)const;
    std::vector<TP2::Contato> * listagem() const;
};

#endif // CONTATODAO_H
