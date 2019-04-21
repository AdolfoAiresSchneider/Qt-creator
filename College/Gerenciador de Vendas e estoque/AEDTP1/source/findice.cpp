#include "findice.h"
using namespace std;
#include <iostream>
#include "lig.h"
#include "arquivo.h"
#include <cstring>
#include <QMessageBox>

Findice::Findice()
{

    ifstream arq("Findice.dat",ios::binary|ios::app);//tenta abrir o arquivo, se nao existir cria

    if(!arq.is_open())///se mesmo assim nao abrir manda uma exceçao , memoria por exemplo
           throw 'a';

    qtd = getqtda();

    if(getqtda()>0)///se for maior que zero significa que existe algo para traser a memoria ram
    {
        this->idfuncionario= new Flig[qtd+1];

        arq.seekg(0);
        arq.read((char*)idfuncionario,sizeof(Flig)*qtd);
    }
    else///se for igual a zero , nao precisa copiar, porque nao tem nada no arquivo
        this->idfuncionario= new Flig[qtd+1];
    arq.close();

}

Findice::~Findice()
{
    ofstream arq("Findice.dat");
    for(int i = 0;i< qtd ;i++)
        arq.write((char*)&idfuncionario[i],sizeof(Flig));
    arq.close();
    delete [] idfuncionario;
}

int Findice::buscab(int pi, int pf, long long cpf)
{

    int meio;
    if(pi==pf)
        return pi;

    meio = (pi+pf)/2;
    if(cpf>idfuncionario[meio].getcpf())
        return buscab(meio+1,pf,cpf);
    return buscab(pi,meio,cpf);

}

int Findice::buscabinaria(long long cpf)
{
    int c = buscab(0,qtd,cpf);
    if(this->idfuncionario[c].getcpf() ==  cpf)
        return c;//caso encontres
    return -1;//caso nao encontre
}

int Findice::gravarid(Funcionario *p, int posicao)
{
    int c;

    c=buscabinaria(p->getcpf());

    if(c>=0) //se retornar maior que zero significa que ja existe e retorna a posicao no arquivo grande
        return this->idfuncionario[c].getposic();

    Flig aux;
    aux.setflig(p,posicao);

    ordenar(&aux);
    qtd++;
    return -2; //significa que gravou ok

}

int Findice::getqtda()
{
    fstream arq("Findice.dat",ios::in|ios::binary);
    arq.seekg(0,ios_base::end);
    return arq.tellg()/sizeof(Flig);
}

void Findice::ordenar(Flig *obj)
{

    int i=this->qtd-1;

    while(obj->getcpf()<idfuncionario[i].getcpf()&& i >= 0)
    {
            idfuncionario[i+1]=idfuncionario[i];
            i--;
    }
    idfuncionario[i+1] = *obj; //copia o i para i+1

}

int Findice::getposic(long long cpf)
{
    int c=buscabinaria(cpf);
     if(idfuncionario[c].getcpf() == cpf)
         return idfuncionario[c].getposic();
     return -1;
}

long long Findice::getcpf( long long p)
{
    return idfuncionario[p].getcpf();

}

void Findice::modposicao(long long cpf,int posic)
{
    int c = buscab(0,qtd-1,cpf);
    idfuncionario[c].setposic(posic);

}

void Findice::removeid(long long cpf)
{
    int c = buscab(0,qtd-1,cpf);
    int i;

    for(i=c;i<qtd-1;i++)
    {
        idfuncionario[i]=idfuncionario[i+1];
    }

    qtd--;

}
