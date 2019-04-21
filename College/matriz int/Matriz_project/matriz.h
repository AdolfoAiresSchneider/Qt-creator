#ifndef MATRIZ_H
#define MATRIZ_H
#include <QMessageBox>
#include<QString>


namespace TP2{//inicio

template<class type>
class Matriz
{
    private:

        int                     quantidadeDeLinhas;
        int                     quantidadeDeColunas;
        int*                    ptMatriz;

    public:

        Matriz(int qLinhas, int qColunas) ;             /// Construtor
       ~Matriz(){ if(ptMatriz) delete[] ptMatriz; }     /// Destrutor

        int                     getQuantidadeDeLinhas()const{  return quantidadeDeLinhas; }
        int                     getQuantidadeDeColunas()const{ return quantidadeDeColunas; }
        int                     getElemento(int linha, int coluna)const;
        bool                    isTriangularSuperior()const;
        bool                    isOrtogonal()const;
        bool                    isTriangularInferior()const;
        bool                    isSimetrica()const;
        bool                    isIdentidade()const;
        bool                    isPermutacao()const;
        bool                    operator ==(Matriz const * const mat)const;
        bool                    operator !=(Matriz const * const mat)const;
        void                    setElemento(int elemento, int linha, int coluna)const;
        Matriz*                 copy() const;
        Matriz*                 operator + (Matriz const * const mat)const;
        Matriz*                 operator - (Matriz const * const mat)const;
        Matriz*                 escalar(int k)const;
        Matriz*                 operator * (Matriz const * const mat)const;
        Matriz*                 getTransposta()const;
        Matriz*                 Mpow (int k)const;
};


template<class type>
TP2::Matriz<type>::Matriz(int qLinhas, int qColunas):
    quantidadeDeLinhas(0),
    quantidadeDeColunas(0),
    ptMatriz(0)
{
    if(qLinhas<=0) throw QString("Quantidade de Linhas somente positiva");
    if(qColunas<=0) throw QString("Quantidade de Colunas somente positiva");
    try{
        ptMatriz = new int[qLinhas*qColunas];
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    quantidadeDeLinhas = qLinhas;
    quantidadeDeColunas = qColunas;
}

template<class type>
void TP2::Matriz<type>::setElemento(int elemento, int linha, int coluna)const{
    if(linha<0 || linha>=quantidadeDeLinhas)
        throw QString("Linha fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");
    int pos = linha*quantidadeDeColunas+coluna;
    *(ptMatriz+pos) = elemento;
}

template<class type>
TP2::Matriz<type> *TP2::Matriz<type>::copy()const{
    Matriz *aux = new Matriz(this->quantidadeDeLinhas,this->quantidadeDeColunas);
    memcpy(aux->ptMatriz,ptMatriz,quantidadeDeColunas*quantidadeDeLinhas*4);
    return aux;
}
template<class type>
int TP2::Matriz<type>::getElemento(int linha, int coluna)const{
    if(linha<0 || linha>=quantidadeDeLinhas)
        throw QString("Linha fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");
    int pos = linha*quantidadeDeColunas+coluna;
    return *(ptMatriz+pos);
}

template<class type>
TP2::Matriz<type> *TP2::Matriz<type>::getTransposta()const{
    try{
         Matriz *aux = new Matriz(quantidadeDeColunas,quantidadeDeLinhas);
         for(int i =0; i<quantidadeDeLinhas;i++){
             for(int j =0; j<quantidadeDeColunas;j++){
                 aux->setElemento(this->getElemento(i,j),j,i);
             }
         }
         return aux;
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada impossivel calcular a transposta");
    }
}
template<class type>
bool TP2::Matriz<type>::isTriangularInferior()const {
    int i,j,aux=1;
    if(this->quantidadeDeLinhas != this->quantidadeDeColunas ||this->quantidadeDeColunas <= 1 || this->quantidadeDeLinhas<=1)
        return false;
    for(i = 0;i<quantidadeDeLinhas;i++){
        for(j=aux;j<quantidadeDeColunas;j++){
            if(this->getElemento(i,j) != 0)
                return false;
        }
        aux++;
    }
    return true;
}

template<class type>
bool TP2::Matriz<type>::isOrtogonal()const{
    bool flag;
    TP2::Matriz<type> *aux1;
    TP2::Matriz<type> *aux2;
    try{
        aux1 = getTransposta();
        aux2 = *this * aux1;
        delete aux1;
        flag = aux2->isIdentidade();
        delete aux2;
        return flag;
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada nao verificar se e ortogonal");
    }
}
template<class type>
bool TP2::Matriz<type>::isSimetrica() const{
    TP2::Matriz<type> *aux;
    try{
        aux = getTransposta();
        if(this->quantidadeDeLinhas != aux->quantidadeDeLinhas || this->quantidadeDeColunas != aux->quantidadeDeColunas){
            delete aux;
            return false;
        }
        bool flag =((*this) == aux);
        delete aux;
        return flag;
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada Simetria nao confirmada");
    }
}

template<class type>
bool TP2::Matriz<type>::isIdentidade() const{
    if(this->quantidadeDeLinhas != this->quantidadeDeColunas)
        return false;
    for(int i = 0;i<this->quantidadeDeLinhas;i++)
        if(this->getElemento(i,i)!=1)
            return false;
    if(isTriangularInferior()&&isTriangularSuperior())
        return true;
    return false;
}

template<class type>
bool TP2::Matriz<type>::isPermutacao() const{
    int soma;
    if(this->quantidadeDeColunas!=this->quantidadeDeLinhas)
        return false;
    for(int i = 0,soma=0;i<this->quantidadeDeLinhas;i++,soma=0){
        for(int j = 0;j<this->quantidadeDeColunas;j++){
            soma += getElemento(i,j) + getElemento(j,i);
            if(getElemento(i,j) != 0 && getElemento(i,j)!=1) return false;
        }
        if(soma!=2) return false;
    }
    return true;
}

template<class type>
bool TP2::Matriz<type>::operator == (Matriz  const * const mat) const{
    if(mat->getQuantidadeDeLinhas() != this->quantidadeDeLinhas || mat->getQuantidadeDeColunas() != this->quantidadeDeColunas)
        return false;
    if(!memcmp(ptMatriz,mat->ptMatriz,4*quantidadeDeColunas*quantidadeDeLinhas))
        return true;
    return false;
}

template<class type>
bool TP2::Matriz<type>::operator != (const Matriz * const mat) const{
    return !(*this == mat) ;
}

template<class type>
bool TP2::Matriz<type>::isTriangularSuperior() const{
    int i,j,aux=1;
    if(this->quantidadeDeLinhas != this->quantidadeDeColunas ||this->quantidadeDeColunas <= 1 || this->quantidadeDeLinhas<=1)
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


template<class type>
TP2::Matriz <type>* TP2::Matriz<type>::operator + (Matriz const * const mat)const
{
    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() || quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString("Nao pode ser adicionadas matriz de tamanhos diferentes");
    try{
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0; linha<quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
                int valor = this->getElemento(linha,coluna) + mat->getElemento(linha,coluna);
                aux->setElemento(valor,linha,coluna);
            }
        }
        return aux;
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada nao podemos adicionar as matrizes");
    }
}

template<class type>
TP2::Matriz<type> *TP2::Matriz<type>::operator - (const Matriz * const mat) const{
    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() || quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString("Nao pode ser adicionadas matriz de tamanhos diferentes");
    try{
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0; linha<quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
                int valor = this->getElemento(linha,coluna) -mat->getElemento(linha,coluna);
                aux->setElemento(valor,linha,coluna);
            }
        }
        return aux;
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada nao podemos subtrair as matrizes");
    }

}

template<class type>
TP2::Matriz<type> *TP2::Matriz<type>::escalar(int k) const
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
        throw QString("Matriz auxiliar nao Criada nao podemos multiplicar as matrizes");
    }
}

template<class type>
TP2::Matriz<type> *TP2::Matriz<type>::operator *(const Matriz * const mat) const{

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
        throw QString("Matriz auxiliar nao Criada nao multiplicar as matrizes");
    }
}
template<class type>
TP2::Matriz<type> *TP2::Matriz<type>::Mpow(int k) const{
    if(quantidadeDeLinhas!=quantidadeDeColunas)
        throw QString("Matriz nao quadrada");
    try{
        if(k<0)
            throw QString("Numero menor que 0");
        if(k>0){
            Matriz *aux = 0;
            Matriz *temp = 0 ;
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
        throw QString("Não foi possivel concluir a operação de potencia matricial ")+erro;
    }
}



}//fim
#endif // MATRIZ_H
