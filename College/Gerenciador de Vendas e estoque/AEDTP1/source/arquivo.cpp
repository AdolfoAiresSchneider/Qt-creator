#include "arquivo.h"
#include <fstream>
#include "games.h"
using namespace std;
#include <iostream>
#include "indice.h"
#include "cadastro.h"
#include <QMessageBox>

arquivo::arquivo()
{
    fstream arq("games.dat",ios::out|ios::binary|ios::app);
        if(!arq.is_open())//verifica se o arquivo ja existe
        {
          ofstream arq("games.dat");
          if(!arq.is_open())
            throw 'a';
          arq.close();
        }
        arq.close();
////---------------------------------------------------------------------------------------------------

    fstream farq("Funcionario.dat",ios::out|ios::binary|ios::app);
        if(!farq.is_open())//verifica se o arquivo ja existe
        {
          ofstream farq("Funcionario.dat");
          if(!farq.is_open())
            throw 'a';
          farq.close();
        }
        farq.close();
//-----------------------------------------------------------------------------------------------------

        fstream varq("vendas.dat",ios::out|ios::binary|ios::app);
            if(!varq.is_open())//verifica se o arquivo ja existe
            {
              ofstream varq("vendas.dat");
              if(!varq.is_open())
                throw 'a';
              varq.close();
            }
            varq.close();

}

void arquivo::gravarF(games *p)//grava apenas no final
{
    fstream arq("games.dat",ios::out|ios::binary|ios::app);
    arq.write((char*)p,sizeof(games));
    arq.close();

}

void arquivo::ler(games *p,int pos)
{
    fstream arq("games.dat",ios::in|ios::binary);
    if(pos >= getqtda())///tentar pegar de uma posiçao inexistente
        throw 7;
    arq.seekg((pos)*sizeof(games));
    arq.read((char*)p,sizeof(games));
    arq.close();

}

void arquivo::sobrescrever(games *p, int pos)
{
    fstream arq("games.dat",ios_base::binary|ios_base::in|ios_base::out);
    if(pos >= getqtda())///tentar gravar de uma posiçao inexistente
        throw 7;
    arq.seekp((pos)*sizeof(games),ios_base::beg);
    arq.write((char*)p,sizeof(games));
    arq.close();
}

int arquivo::getqtda()
{
    fstream arq("games.dat",ios::in|ios::binary);
    arq.seekg(0,ios_base::end);
    return arq.tellg()/sizeof(games);
}

///------------------------------------------------------------------------------------------------------------------------------------------

void arquivo::FgravarF(Funcionario *p)//grava apenas no final
{
    fstream arq("Funcionario.dat",ios::out|ios::binary|ios::app);
    arq.write((char*)p,sizeof(Funcionario));
    arq.close();
}

void arquivo::Fler(Funcionario *p,int pos)
{
    fstream arq("Funcionario.dat",ios::in|ios::binary);
    if(pos > Fgetqtda())///tentar pegar de uma posiçao inexistente
        throw 7;
    arq.seekg((pos)*sizeof(Funcionario));
    arq.read((char*)p,sizeof(Funcionario));
    arq.close();
}

void arquivo::Fsobrescrever(Funcionario *p, int pos)
{

    fstream arq("Funcionario.dat",ios_base::binary|ios_base::in|ios_base::out);
    if(pos >= Fgetqtda())///tentar gravar de uma posiçao inexistente
        throw 7;
    arq.seekp((pos)*sizeof(Funcionario),ios_base::beg);
    arq.write((char*)p,sizeof(Funcionario));
    arq.close();
}

int arquivo::Fgetqtda()
{
    fstream arq("Funcionario.dat",ios::in|ios::binary);
    arq.seekg(0,ios_base::end);
    return arq.tellg()/sizeof(Funcionario);
}

void arquivo::VgravarF(CVenda *p)
{
    fstream arq("vendas.dat",ios::out|ios::binary|ios::app);
    arq.write((char*)p,sizeof(CVenda));
    arq.close();
}

void arquivo::Vler(CVenda *p, int pos)
{
    fstream arq("vendas.dat",ios::in|ios::binary);
    if(pos > Vgetqtda())///tentar pegar de uma posiçao inexistente
        throw 7;
    arq.seekg((pos)*sizeof(CVenda));
    arq.read((char*)p,sizeof(CVenda));
    arq.close();
}

int arquivo::Vgetqtda()
{

    fstream arq("vendas.dat",ios::in|ios::binary);
    arq.seekg(0,ios_base::end);
    return arq.tellg()/sizeof(CVenda);
}

void arquivo::criararq()
{
    ofstream arq("arqaux.dat",ios::app);
    arq.close();
}

void arquivo::gravaraux(Funcionario *a)
{
    fstream arq("arqaux.dat",ios::app|ios::binary);
    arq.write((char*)a,sizeof(Funcionario));
    arq.close();

}

