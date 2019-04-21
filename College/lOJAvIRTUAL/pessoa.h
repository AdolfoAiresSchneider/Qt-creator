#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
using namespace std;

namespace Adolfo{

class Pessoa
{
    private:

        std::string nome;
        std::string endereco;
        long telefone;
        std::string email;

    public:

        Pessoa(){}

        void setNome( const string & nome ) {  this->nome = nome; }
        const string & getNome() const { return nome; }
        void setEndereco( string & endereco ) { this->endereco = endereco; }
        const string & getEndereco() const { return endereco; }
        void setEmail( string & email ) { this->email = email ; }
        const string & getEmail() const{ return email; }
        void setTelefone(long telefone) { this->telefone = telefone; }
        long & getTelefone(){ return telefone ; }
        virtual float GetImposto(float) = 0;

};


class PessoaFisica : public Pessoa
{
    private:
        string cpf;
        char sexo;
    public:
        void setCpf(const string & cpf ){this->cpf = cpf;}
        const string & getCpf()const{return cpf;}
        void setSexo(const char & sexo){this->sexo = sexo;}
        const char & getSexo()const {return sexo;}
        float GetImposto(float rendaBruta);
};


class PessoaJuridica : public Pessoa
{
    private:

        string cnpj;
        string razaoSocial;

    public:
        void setCnpj(const string & cnpj ){this->cnpj = cnpj;}
        const string & getCnpj()const {return cnpj;}
        void setRazaoSocial(const string & razaoSocial ){this->razaoSocial = razaoSocial;}
        const string & getRazaoSocial() const{return razaoSocial;}
        float GetImposto(float rendaAnual);

};
}
#endif // PESSOA_H
