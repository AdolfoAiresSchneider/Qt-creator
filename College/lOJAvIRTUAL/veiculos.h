#ifndef VEICULOS_H
#define VEICULOS_H
#include <bits/stdc++.h>
using namespace std;


class Veiculos
{

private:

    int velocidadeMaxima;
    string combustivel;
    string tipo;
    string modelo;
    string marca;
    int ano;

public:

    void setVelocidade(int v){this->velocidadeMaxima = v;}
    int getVelocidade()const {return this->velocidadeMaxima;}
    void setCombustivel(string c){this->combustivel = c;}
    string getCombustivel(){return this->combustivel;}
    void setTipo(string c){this->tipo = c;}
    string getTipo(){return this->tipo;}
    void setModelo(string c){this->modelo = c;}
    string getModelo(){return this->modelo;}
    void setMarca(string c){this->marca = c;}
    string getMarca(){return this->marca;}
    void setAno(int ano){this->ano  = ano;}
    int getAno(){return this->ano;}

    Veiculos();
};


class barco
{
  private:

  public:

};

class aviao
{
  private:
    string companhiaAeria;
  public:
    void setCompanhia(string comp){this->companhiaAeria = comp;}
    string getCompanhia(){return this->companhiaAeria;}

};
class automovel
{
  private:
    int qtdPortas;
  public:
    void setQtdPortas(int qtd){this->qtdPortas = qtd;}
    int getQtdPortas(){return this->qtdPortas;}

};

#endif // VEICULOS_H
