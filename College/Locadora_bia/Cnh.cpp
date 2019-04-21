#include "Cnh.h"

bia::Cnh::Cnh():
    numero(0)

{}

bia::Cnh::Cnh(long long numero, QDate emissao, QDate expiracao) :
    numero(numero),
    emissao(emissao),
    expiracao(expiracao)
{}
