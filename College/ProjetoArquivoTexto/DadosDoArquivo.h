#ifndef DADOSDOARQUIVO_H
#define DADOSDOARQUIVO_H
#include<QString>
#include<fstream>
#include<vector>
#include<Aluno.h>
#include<QStringList>
#include<iostream>
namespace TP2{//inicio
class DadosDoArquivo
{
private:
    QString nomeDoArquivoNoDisco;
public:
    DadosDoArquivo(QString nomeDoArquivoNoDisco);
    std::vector<Aluno>* obterDadosDoArquivo()const;
};
}//fim
#endif // DADOSDOARQUIVO_H
