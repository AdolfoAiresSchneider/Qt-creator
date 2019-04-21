#ifndef PRODUTOS_H
#define PRODUTOS_H
#include <bits/stdc++.h>
using namespace std;


class Produtos
{

    private:

        long int codigo;
        string   descircao;
        float    precoDeVenda;
        string   tipo;

    public:

        void setCodigo(long int & cod) { this->codigo = cod; }
        long int getCodigo() const{return this->codigo ; }
        void setDescrcao(string & desc){this->descircao = desc;}
        const string & getDescricao()const{return this->descircao;}
        void setPrecoVenda(float & valor){this->precoDeVenda = valor;}
        const float & getPrecoVenda()   const{return this->precoDeVenda;}
        void setTipo(string & tipo){this->tipo = tipo;}
        const string & getTipo()        const{return this->tipo;}
        Produtos();
};


class Livros : public Produtos
{
    private:

        string autor;
        string tradutor;
        string editora;
        int anoDePublicacao;

    private:

       void setAutor(string & autor){this->autor = autor;}
       const string & getAutor()const{return this->autor;}
       void setTradutor(string & tradutor){this->tradutor = tradutor;}
       const string & getTradutor()const{return this->tradutor;}
       void setEditor(string & editora){this->editora = editora;}
       const string & getEditora()const{return this->editora;}
       void setAnoDePublicacao(const  int &  ano){this->anoDePublicacao = ano;}
       int getAnoDePublicacao()const{ return this->anoDePublicacao;}


};

class Cds : public Produtos
{
    private:

        string albumName;
        string banda;
        string cantor;
        string genero;

    public:

        void setAlbum(string & album){this->albumName = album;}
        const string & getAlbum()const{return this->albumName;}
        void setBanda(string & banda){this->banda = banda;}
        const string & getBanda()const{return this->banda;}
        void setCantor(string & cantor){this->cantor = cantor;}
        const string & getCantor()const{return this->banda;}
        void setGenero(string & genero){this->genero = genero;}
        const string & getGenero()const{return this->genero;}

};

class Notebook : public Produtos
{
    private:

        string modelo;
        string marca;
        int ram;
        int hd;
        string processador;
        float tela;
        string SO;

    public:

        void setmodelo(string & modelo){this->modelo = modelo;}
        const string & getmodelo()const{return this->modelo;}
        void setMarca(string & Marca){this->marca = Marca;}
        const string & getMarca()const{return this->marca;}
        void setProcessador(string & Processador){this->processador = Processador;}
        const string & getProcessador()const{return this->processador;}
        void setSo(string & So){this->SO = So;}
        const string & getSo()const{return this->SO;}
};
#endif // PRODUTOS_
