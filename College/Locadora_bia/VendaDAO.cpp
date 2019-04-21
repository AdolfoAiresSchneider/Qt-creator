#include "VendaDAO.h"

#include <iostream>
using namespace std;

void bia::VendaDAO::incluir(bia::Venda &venda)
{
    std::fstream arquivo("data/vendas.txt", std::ios::out | std::ios_base::app);

    if (!arquivo.is_open()){
        throw QString("Falha ao abrir arquivo de vendas na inclusao ");
    }

    /// ordem arquivo Id | CPF | PLACA | DESCRICAO | VALOR

    // GRAVA NO ARQUIVO VENDAS DENTRO DA PASTA 'data'
    arquivo << venda.getId() << ";"
        << venda.getCliente().getNome().toStdString() << ";"
        << venda.getCarro().getPlaca().getPlaca().toStdString() << ";"
        << venda.getDescricao().toStdString() << ";"
        << venda.getValorDaVenda() << "\n";
    arquivo.close();
}

void bia::VendaDAO::incluir(std::map<int, bia::Venda> *Vendas)
{
    std::ofstream arquivo("data/vendas.txt");
    arquivo.close();
    for(std::map<int,bia::Venda>::iterator it = Vendas->begin() ; it != Vendas->end() ; ++it ){
        this->incluir(it->second);
    }
}

std::map<int, bia::Venda> *bia::VendaDAO::listar() const
{
    std::ifstream arquivo("data/vendas.txt",std::ios::app);

    if(!arquivo.is_open())
    {
      throw QString("Não foi possivel abrir o arquivo de vendas na listagem");
    }

    try
    {
        std::map<int,bia::Venda>  *Vendas;
        std::string linha;
        bia::Venda venda;
        bia::Carro carro;
        bia::Cliente cliente;
        bia::CarroDAO ArqCarro;
        ClienteDAO ArqCliente;
        QStringList camps;

        Vendas = new  std::map<int,bia::Venda>;

        std::getline(arquivo,linha );

        while(!arquivo.eof())
        {
            camps = QString::fromStdString(linha).split(';');

            cout << camps.length() << endl;

            if(camps.length() != 5 )
            {
              throw QString("Arquivo de Vendas corrompidos");
            }

            /// ordem arquivo Id | CPF | PLACA | DESCRICAO | VALOR

            cliente = ArqCliente.listar(camps[1].toLongLong());
            carro = ArqCarro.listar(camps[2]);

            venda.setId(camps[0].toInt());
            venda.setCliente(cliente);
            venda.setCarro(carro);
            venda.setDescricao(camps[3]);
            venda.setValorDaVenda(camps[4].toDouble());

            Vendas->operator [](venda.getId()) = venda;

            std::getline(arquivo,linha );
        }

    arquivo.close();
    return Vendas;

    }catch(std::exception & erro)
    {
        arquivo.close();
        throw QString(erro.what());
    }
    catch(...)
    {
        arquivo.close();
        throw QString("Erro desconhecido!");
    }
}

bia::Venda bia::VendaDAO::listar(const int &id) const
{
    bia::Venda venda;
    std::map<int,bia::Venda> * aux = this->listar();
    venda = aux->operator [](id);
    if(aux) delete aux;

    if(aux->find(id) != aux->end()){
        return venda;
    }
    throw QString("Não há vendas com este código: " + QString::number(id) + "!");
    return venda;
}
