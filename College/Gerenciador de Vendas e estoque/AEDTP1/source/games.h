#ifndef GAMES_H
#define GAMES_H
#include <fstream>




class games
{
protected:

    char nome[30];
    char console [15];
    long long int codigo;
    int faixa;
    char genero[30];
    float valor;
    int qtd;

public:

    games();

    void setnome(const char *n );
    void setconsole(const char *n);
    void setcod(long long int n);
    void setetaria(int n);
    void setgenero(const char *n);
    void setvalor(float n);
    void setqtd(int n);

    int getcod();
    int getetaria();
    int getqtd();
    float getvalor();
    void getnome(char *n);
    void getconsole(char *n);
    void getgenero(char *n);

};

#endif // GAMES_H
