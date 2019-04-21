#ifndef NCOMPLEXO_H
#define NCOMPLEXO_H
#include<QString>

namespace TP2{// inicio
class NComplexo
{
    //Atributos
private:
    int parteReal;
    int parteImaginaria;
public:
    NComplexo();
    void set(int parteReal, int parteImaginaria)
    {this->parteReal=parteReal;this->parteImaginaria=parteImaginaria;}

    std::pair<int,int> getNC();

    NComplexo Soma(NComplexo &numero)const;
    NComplexo Subtracao(NComplexo &numero)const;
    NComplexo Multiplicacao(NComplexo &numero)const;
    NComplexo Divisao(NComplexo &numero)const;

    NComplexo operator +(NComplexo &numero)const;
    NComplexo operator -(NComplexo &numero)const;
    NComplexo operator *(NComplexo &numero)const;
    NComplexo operator /(NComplexo &numero)const;

    bool operator == (NComplexo &numero)const;
    bool operator != (NComplexo &numero)const;


};

}//fim
#endif // NCOMPLEXO_H
