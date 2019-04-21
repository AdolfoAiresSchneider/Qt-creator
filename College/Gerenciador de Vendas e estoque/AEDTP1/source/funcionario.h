#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <cstring>


class Funcionario
{

private:

    char nome[30];
    long long int cpf;
    char cargo[30];
    long long contato;
    bool validade;

public:

    Funcionario();

    void setnome(const char *a);
    bool setcpf(long long int a);
    bool setcpf(const char * a);
    void setcargo(const char *a);
    void setcontato(long int a);

    void valida();
    void invalida();
    bool validarcpf(const char *digitos);

    long long int getcpf();
    void getnome(char *a);
    long long getcontato();
    void getcargo(char *a);
    bool getv();

};

#endif // FUNCIONARIO_H
