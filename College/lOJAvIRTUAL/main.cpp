#include "pessoa.h"
# include <bits/stdc++.h>
#include "pessoa.h"


using namespace std;

int main()
{

    Adolfo::PessoaJuridica p1;
    Adolfo::PessoaFisica s;

    s.setNome("Lucas");
    s.setTelefone(123456);
    p1.setNome("King");
    p1.setTelefone(2323432);

    cout<<s.getNome()<<' '<<s.GetImposto(10000)<<endl;
    cout<<p1.getNome()<<' '<<p1.GetImposto(10000)<<endl;

}
