#ifndef CONTATO_H
#define CONTATO_H
#include<QString>
#include<vector>
#include<Telefone.h>
//teste:
namespace TP2{
class Contato
{
private:
    int identificador;
    QString nomeCompleto;
    std::vector<Telefone> *telefones;
public:
    Contato();
    Contato(int identificador, QString nomeCompleto,std::vector<Telefone> *telefones);

    int getIdentificador()const{return identificador;}
    QString getNomeCompleto()const{return nomeCompleto;}
    std::vector<Telefone>const * const getTelefone() const{return telefones;}

    void setIdentificador(unsigned int identificador){
        this->identificador = identificador;
    }
    void setNomeCompleto(QString nomeCompleto){
        this->nomeCompleto = nomeCompleto;
    }
    void setTelefones(std::vector<Telefone> *telefones){
        if(this->telefones) delete this->telefones;
        this->telefones = telefones;
    }

};
}
#endif // CONTATO_H
