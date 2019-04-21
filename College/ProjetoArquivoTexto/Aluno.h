#ifndef ALUNO_H
#define ALUNO_H
#include<QString>

namespace TP2{//inicio
class Aluno
{
private:
    QString matricula;
    QString nome;
    QString situacao;
public:
    Aluno();
    QString getMatricula()const{return matricula;}
    QString getNome()const{return nome;}
    QString getSituacao()const{return situacao;}

    void setMatricula(QString matricula){this->matricula = matricula;}
    void setNome(QString nome){this->nome = nome;}
    void setSituacao(QString situacao){this->situacao = situacao;}
};
}//fim

#endif // ALUNO_H
