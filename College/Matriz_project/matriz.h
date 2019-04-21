#ifndef MATRIZ_H
#define MATRIZ_H
#include <QMessageBox>
#include<QString>
#include <bits/stdc++.h>
using namespace std;


namespace TP2{//inicio
template <class Type>
class Matriz
{
private:
    int quantidadeDeLinhas;
    int quantidadeDeColunas;
    int *ptMatriz;
public:
    Matriz(int qLinhas, int qColunas);
   ~Matriz(){ if(ptMatriz) delete[] ptMatriz; }

    int getQuantidadeDeLinhas()const{  return quantidadeDeLinhas; }
    int getQuantidadeDeColunas()const{ return quantidadeDeColunas; }

    Type getElemento(int linha, int coluna)const;

    bool isTriangularSuperior()const;
    bool isOrtogonal();
    bool isTriangularInferior()const;
    bool isSimetrica();
    bool isIdentidade()const;
    bool operator ==(Matriz const * const mat)const;
    bool operator !=(Matriz const * const mat)const;

    void setElemento(Type elemento, int linha, int coluna)const;

    Matriz *copy() const;
    Matriz* operator + (Matriz const * const mat)const;
    Matriz* operator - (Matriz const * const mat)const;
    Matriz* operator * (float k)const;
    Matriz* operator * (Matriz const * const mat)const;
    Matriz* getTransposta();
    Matriz* Mpow (int k)const;

    int Mymemcmp(const Type *V1, const Type *V2, size_t n);
};

template <class Type>
Matriz<Type>::Matriz(int qLinhas, int qColunas):
    quantidadeDeLinhas(0),
    quantidadeDeColunas(0),
    ptMatriz(0)
{
    if(qLinhas<=0) throw QString("Quantidade de Linhas somente positiva");
    if(qColunas<=0) throw QString("Quantidade de Colunas somente positiva");

    try
    {
        ptMatriz = new int[qLinhas*qColunas];
    }
    catch(std::bad_alloc&)
    {
        throw QString("Vai comprar Memoria");
    }
    quantidadeDeLinhas = qLinhas;
    quantidadeDeColunas = qColunas;
}

template <class Type>
void Matriz<Type>::setElemento(Type elemento, int linha, int coluna)const{
    if(linha<0 || linha>=quantidadeDeLinhas)
        throw QString("Linha fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");
    int pos = linha*quantidadeDeColunas+coluna;
    *(ptMatriz+pos) = elemento;
}

template <class Type>
Matriz<Type> *Matriz<Type>::copy()const
{
    Matriz<Type> *aux = new Matriz<Type>(this->quantidadeDeLinhas,this->quantidadeDeColunas);
    memcpy(aux->ptMatriz,ptMatriz,quantidadeDeColunas*quantidadeDeLinhas*4);
    return aux;
}

template <class Type>
Type Matriz<Type>::getElemento(int linha, int coluna)const
{
    if(linha<0 || linha>=quantidadeDeLinhas)
        throw QString("Linha fora do intervalo valido");

    if(coluna<0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");

    int pos = linha*quantidadeDeColunas+coluna;
    return *(ptMatriz+pos);
}

template <class Type>
Matriz<Type> *Matriz<Type>::getTransposta()
{
    try{
         Matriz<Type> *aux = new Matriz<Type>(quantidadeDeColunas,quantidadeDeLinhas);
         for(int i =0; i<quantidadeDeLinhas;i++){
             for(int j =0; j<quantidadeDeColunas;j++){
                 aux->setElemento(this->getElemento(i,j),j,i);
             }
         }
         return aux;
    }
    catch(std::bad_alloc&)
    {
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro)
    {
        throw QString("Matriz auxiliar nao Criada nao podemos adicionar as matrizes");
    }
}

template <class Type>
bool Matriz<Type>::isTriangularSuperior() const
{
    int i,j,aux=1;
    if(this->quantidadeDeLinhas != this->quantidadeDeColunas)
        return false;
    for(i = 0;i<quantidadeDeLinhas;i++)
    {
        for(j=aux;j<quantidadeDeColunas;j++)
        {
            if(this->getElemento(i,j) != 0)
                return false;
        }
        aux++;
    }
    return true;
}

template <class Type>
bool Matriz<Type>::isOrtogonal()
{
    TP2::Matriz<Type> *aux1;
    TP2::Matriz<Type> *aux2;
    try{
        aux1 = getTransposta();
        aux2 = *this * aux1;
        delete aux1;
        if(aux2->isIdentidade()){
            delete aux2;
            return true;
        }
        delete aux2;
        return false;
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada nao verificar se e ortogonal");
    }
}

template <class Type>
bool Matriz<Type>::isSimetrica()
{
    TP2::Matriz<Type> *aux;
    try{
        aux = this->getTransposta();
        if(this->quantidadeDeLinhas != aux->quantidadeDeLinhas || this->quantidadeDeColunas != aux->quantidadeDeColunas)
            return false;
        if((*this) == aux)
        {
            delete aux;
            return true;
        }
        delete aux;
        return false;
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada Identidade nao confirmada");
    }
}

template <class Type>
bool Matriz<Type>::isIdentidade() const
{
    if(this->quantidadeDeLinhas != this->quantidadeDeColunas)
        return false;
    for(int i = 0;i<this->quantidadeDeLinhas;i++){
        for(int j = 0; j <this->quantidadeDeColunas;j++){
            if(i==j){
                if(this->getElemento(i,j)!=1)
                    return false;
            }
            else{
                if(this->getElemento(i,j)!=0 || this->getElemento(j,i)!=0)
                    return false;
            }
        }
    }
    return true;
}

template <class Type>
bool Matriz<Type>::operator == (Matriz  const * const mat) const
{

    if(mat->getQuantidadeDeLinhas() != this->quantidadeDeLinhas || mat->getQuantidadeDeColunas() != this->quantidadeDeColunas)
        return false;
    if(!memcmp(ptMatriz,mat->ptMatriz,4*quantidadeDeColunas*quantidadeDeLinhas))
        return true;
    return false;
}

template <class Type>
bool Matriz<Type>::operator != (const Matriz * const mat) const
{
    return !(*this == mat) ;
}

template <class Type>
bool Matriz<Type>::isTriangularInferior() const{
    int i,j,aux=1;
    if(this->quantidadeDeLinhas != this->quantidadeDeColunas)
        return false;
    for(i = 1;i<quantidadeDeLinhas;i++){
        for(j=0;j<aux;j++){
            if(this->getElemento(i,j) != 0)
                return false;
        }
        aux++;
    }
    return true;
}


template <class Type>
Matriz<Type>* Matriz<Type>::operator + (Matriz const * const mat)const
{
    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() || quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString("Nao pode ser adicionadas matriz de tamanhos diferentes");
    try{
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0; linha<quantidadeDeLinhas; linha++)
        {
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++)
            {
                int valor = this->getElemento(linha,coluna) + mat->getElemento(linha,coluna);
                aux->setElemento(valor,linha,coluna);
            }
        }
        return aux;
    }
    catch(std::bad_alloc&)
    {
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro)
    {
        throw QString("Matriz auxiliar nao Criada nao podemos adicionar as matrizes");
    }
}

template <class Type>
Matriz<Type> *Matriz<Type>::operator - (const Matriz * const mat) const
{
    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() || quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString("Nao pode ser adicionadas matriz de tamanhos diferentes");
    try{
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0; linha<quantidadeDeLinhas; linha++)
        {
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++)
            {
                int valor = this->getElemento(linha,coluna) -mat->getElemento(linha,coluna);

                aux->setElemento(valor,linha,coluna);
            }
        }
        return aux;
    }
    catch(std::bad_alloc&)
    {
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro)
    {
        throw QString("Matriz auxiliar nao Criada nao podemos subtrair as matrizes");
    }

}

template <class Type>
Matriz<Type> *Matriz<Type>::operator *(float k) const
{
    try{
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int i = 0;i<quantidadeDeLinhas;i++)
            for(int j = 0;j<quantidadeDeColunas;j++)
                aux->setElemento(this->getElemento(i,j)*k,i,j);
        return aux;
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada nao podemos adicionar as matrizes");
    }
}

template <class Type>
Matriz<Type> *Matriz<Type>::operator *(const Matriz * const mat) const
{
    if(this->quantidadeDeColunas!=mat->quantidadeDeLinhas)
        throw QString("Multiplicação Impossivel");

    int linhas = this->quantidadeDeLinhas;
    int colunas = mat->quantidadeDeColunas;
    try{
            Matriz *aux = new Matriz(this->quantidadeDeLinhas,mat->quantidadeDeColunas);
            for(int i=0 ; i<linhas;i++){
                for(int j=0;j<colunas;j++){
                    aux->setElemento(0,i,j);
                    for(int k =0;k<quantidadeDeColunas;k++)
                        aux->setElemento(aux->getElemento(i,j)+(this->getElemento(i,k)*mat->getElemento(k,j)),i,j);
                }
            }
            return aux;

    }catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada nao lklkpodemos * as matrizes");
    }
}

template <class Type>
Matriz<Type> *Matriz<Type>::Mpow(int k) const
{
    if(quantidadeDeLinhas!=quantidadeDeColunas)
        throw QString("Matriz nao quadrada");
    try{
        if(k<0)
            throw QString("Numero menor que 0");
        if(k>0)
        {
            Matriz<Type> *aux ;
            Matriz<Type> *temp = 0 ;
            aux = this->copy();
            for(int i = 0;i<k-1;i++){
                temp = aux;
                aux = (*aux)*this;
                delete temp ;
            }
            return aux;
        }else{
            Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
            memset(aux->ptMatriz,0,quantidadeDeLinhas*quantidadeDeColunas*4);
            for(int i = 0;i < quantidadeDeLinhas;i++)
                aux->setElemento(1,i,i);
            return aux;
        }
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro){
        throw erro;
    }
}

template <class Type>
int Matriz<Type>::Mymemcmp(const Type *V1, const Type *V2, size_t n)
{
      size_t i;
      for (i = 0; i < n; i++, V1++, V2++)
      {
        if (*V1 < *V2)
          return -1;
        else
            if (*V1 > *V2)
                return 1;
      }
      return 0;
}
}//fim
#endif // MATRIZ_H
