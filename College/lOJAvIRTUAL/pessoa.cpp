#include "pessoa.h"


float Adolfo::PessoaJuridica::GetImposto(float rendaAnual)
{
    if(rendaAnual < 1400) return 0;
    if(rendaAnual < 2100) return rendaAnual*0.10;
    if(rendaAnual < 2800) return rendaAnual*0.15;
    if(rendaAnual < 3600) return rendaAnual*0.25;
    return rendaAnual * 0.30;
}

float Adolfo::PessoaFisica::GetImposto(float rendaBruta)
{
  return rendaBruta*0.10;
}
