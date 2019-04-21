#ifndef CONTATOPERSISTENCIA_H
#define CONTATOPERSISTENCIA_H
#include<QString>
#include<Crud.h>
#include<fstream>
#include<list>
#include<stack>
namespace agenda{//inicio
class ContatoPersistencia:public CRUD
{
private:
    QString nomeDoArquivoNoDisco;
public:
    ContatoPersistencia(QString nomeDoArquivoNoDisco);
    void incluir(Contato &objeto) const;
    void excluir(QString nome) const;
    void alterar(Contato &objeto) const;
    std::list<Contato>* listagem() const;
};
}//fim
#endif // CONTATOPERSISTENCIA_H
