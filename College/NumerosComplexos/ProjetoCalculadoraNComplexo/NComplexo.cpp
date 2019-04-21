#include "NComplexo.h"

namespace TP2{//inicio

NComplexo::NComplexo():
    parteReal(0),
    parteImaginaria(0)
{
}

NComplexo NComplexo::Soma(NComplexo &numero) const
{
    float real = this->parteReal + numero.parteReal;
    float imaginaria = this->parteImaginaria + numero.parteImaginaria;
    NComplexo aux;
    aux.set(real,imaginaria);
    return aux;
}

NComplexo NComplexo::Subtracao(NComplexo &numero) const
{
    float real = this->parteReal - numero.parteReal;
    float imaginaria = this->parteImaginaria - numero.parteImaginaria;
    NComplexo aux;
    aux.set(real,imaginaria);
    return aux;
}

NComplexo NComplexo::Multiplicacao(NComplexo &numero) const
{
    float real = this->parteReal*numero.parteReal - this->parteImaginaria*numero.parteImaginaria;

    float imaginaria = this->parteReal * numero.parteImaginaria +this->parteImaginaria*numero.parteReal;

    NComplexo aux;
    aux.set(real,imaginaria);
    return aux;
}

NComplexo NComplexo::Divisao(NComplexo &numero) const
{
    float numerador,denominador;

    numerador = (this->parteReal*numero.parteReal + this->parteImaginaria*numero.parteImaginaria);
    denominador = ((numero.parteReal)*(numero.parteReal)+(numero.parteImaginaria*(numero.parteImaginaria)));

    if(denominador == 0)
        throw 0;

    float real = numerador/denominador;

    numerador = (this->parteImaginaria*numero.parteReal - this->parteReal*numero.parteImaginaria);
    denominador =(numero.parteReal*numero.parteReal + numero.parteImaginaria*numero.parteImaginaria);

    if(denominador == 0)
        throw 0;

    float imaginaria =numerador/denominador;

    NComplexo aux;
    aux.set(real,imaginaria);
    return aux;
}

std::pair<int, int> NComplexo::getNC()
{
    return std::make_pair(this->parteReal,this->parteImaginaria);
}

NComplexo NComplexo::operator +(NComplexo &numero)const
{
    return Soma(numero);
}

NComplexo NComplexo::operator -(NComplexo &numero) const
{
    return Subtracao(numero);
}

NComplexo NComplexo::operator *(NComplexo &numero) const
{
   return Multiplicacao(numero);
}

bool NComplexo::operator ==(NComplexo &numero) const
{
    return numero.parteImaginaria == this->parteImaginaria && numero.parteReal == this->parteReal;
}

bool NComplexo::operator !=(NComplexo &numero) const
{
    return !(*this == numero);
}

NComplexo NComplexo::operator /(NComplexo &numero) const
{
   return Divisao(numero);
}

}//fim
