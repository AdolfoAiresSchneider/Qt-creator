#include "vindice.h"

Vindice::Vindice()
{

    ifstream arq("Vindice.dat",ios::binary|ios::app);//tenta abrir o arquivo, se nao existir cria

    if(!arq.is_open())///se mesmo assim nao abrir manda uma exceçao , memoria por exemplo
           throw 'a';

    qtd = getqtda();

    if(getqtda()>0)///se for maior que zero significa que existe algo para traser a memoria ram
    {
        this->vet= new no[qtd+1];
        arq.seekg(0);
        arq.read((char*)vet,sizeof(no)*qtd);
    }
    else///se for igual a zero , nao precisa copiar, porque nao tem nada no arquivo
        this->vet= new no[qtd+1];
    arq.close();

}
Vindice::~Vindice()
{
    ofstream arq("Vindice.dat");
    for(int i = 0;i< qtd ;i++)
        arq.write((char*)&vet[i],sizeof(no));
    arq.close();
    delete [] vet;
}

int Vindice::buscab(int pi, int pf, int cod)
{

    int meio;
    if(pi==pf)
        return pi;

    meio = (pi+pf)/2;
    if(cod>vet[meio].cod)
        return buscab(meio+1,pf,cod);
    return buscab(pi,meio,cod);

}

int Vindice::buscabinaria(int cod)
{
    int c = buscab(0,qtd-1,cod);
    if(this->vet[c].cod ==  cod)
        return c;//caso encontres
    return -1;//caso nao encontre

}

int Vindice::gravarid(CVenda *p, int posicao)
{

    int c;
    c=buscabinaria(p->getcod());

    if(c>=0) //se retornar maior que zero significa que ja existe e retorna a posicao no arquivo grande
        return this->vet[c].posic;

    no aux;
    aux.posic=posicao;
    aux.cod=p->getcod();

    ordenar(&aux);
    qtd++;
    return -2; //significa que gravou ok

}

int Vindice::getqtda()
{


    fstream arq("Vindice.dat",ios::in|ios::binary);
    arq.seekg(0,ios_base::end);
    return arq.tellg()/sizeof(no);

}

void Vindice::ordenar(no *obj)
{
    int i=this->qtd-1;

    while(obj->cod < vet->cod&& i >= 0)
    {
         vet[i+1]=vet[i];
            i--;
    }

    vet[i+1] = *obj; //copia o i para i+1
}

int Vindice::getposic(int cod)
{
    int c = buscabinaria(cod);
     if(vet[c].cod == cod)
         return vet[c].posic;
     return -1;
}

int Vindice::getcod( int p)
{
    return vet[p].cod;
}

void Vindice::setqtd(int i)
{
    qtd=i;
}
