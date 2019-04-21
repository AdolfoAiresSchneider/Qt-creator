#include "funcionario.h"
#include <stdlib.h>
using namespace std;

Funcionario::Funcionario()
{
    validade = true;
}

void Funcionario::setnome(const char *a)
{
    strcpy(this->nome,a);
}

bool Funcionario::setcpf(long long int a)
{
    this->cpf = a;
}

bool Funcionario::setcpf(const char *a)
{
    if(!validarcpf(a))
        throw 10;
    cpf = atoll(a);
    return true;
}

void Funcionario::setcargo(const char *a)
{
    strcpy(cargo,a);
}

void Funcionario::setcontato(long a)
{
    contato = a;
}

void Funcionario::valida()
{
    validade = true;
}

void Funcionario::invalida()
{
    validade = false;
}

bool Funcionario::validarcpf(const char *digitos)
{

    int s=0,n,i;
            for(i = 0 ; digitos[i+1] == digitos[i] && i < 11; i++);

            if(i == 10)
            {

                return false; // tudo igual nesse cpf, invalido!
            }


                for(int i=10;i>=2;i--)
                {
                    n=digitos[10-i]-'0';
                    s+=i*n;
                }
                int s1=0;

                for(int i=11;i>=2;i--)
                {
                    n=digitos[11-i]-'0';
                    s1+=i*n;
                }


                if(s%11<2)
                { 	if(digitos[9]-'0' == 0)
                    {
                            if(s1%11<2)
                            {
                                    if(digitos[9]-'0' == 0)

                                    {
                                        return true;
                                    }
                                    return false;
                            }
                            else
                            {
                                if(digitos[10]-'0' == 11-(s1%11))
                                    return true;
                                return false;
                            }
                    }
                    return false;
                }
                else
                {

                    if(digitos[9]-'0' == 11-(s%11))
                    {
                            if(s1%11<2)
                            {
                                    if(digitos[9]-'0' == 0)

                                    {
                                        return true;
                                    }
                                    return false;
                            }
                            else
                            {
                                if(digitos[10]-'0' == 11-(s1%11))
                                    return true;
                                return false;
                            }
                    }
                        return false;
                }
}

void Funcionario::getnome(char *a)
{
    strcpy(a,nome);
}

long long Funcionario::getcontato()
{
    return contato;
}

void Funcionario::getcargo(char *a)
{
    strcpy(a,cargo);
}

bool Funcionario::getv()
{
    return validade;
}

long long int Funcionario::getcpf()
{
    return cpf;
}
