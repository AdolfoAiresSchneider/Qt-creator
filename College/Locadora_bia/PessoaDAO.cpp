/**
  NOME DOS ARQUIVOS:
  '_PessoaCpf.txt'
  '_Rgs.txt'
  '_Emails.txt'
  '_Telefones.txt'
  '_Enderecos.txt'
*/


#include "PessoaDAO.h"
#include <QStringList>

void PessoaDAO::incluir(bia::Pessoa &P) const
{
    std::ofstream arq_pessoacpf;
    std::ofstream arq_email;
    std::ofstream arq_rg;
    std::ofstream arq_telefones;
    std::ofstream arq_endereco;

    arq_pessoacpf.open("data/_PessoaCpf.txt",std::ios::out|std::ios::app);
    if(!arq_pessoacpf.is_open())
        throw QString("FALHA AO ABRIR ARQUIVO '_PessoaCpf' PARA GRAVACAO!");

    arq_email.open("data/_Emails.txt",std::ios::out|std::ios::app);
    if(!arq_email.is_open()){
        arq_pessoacpf.close();
        throw QString("FALHA AO ABRIR ARQUIVO '_Emails' PARA GRAVACAO!");
    }

    arq_rg.open("data/_Rgs.txt",std::ios::out|std::ios::app);
    if(!arq_rg.is_open()){
        arq_pessoacpf.close();
        arq_email.close();
        throw QString("FALHA AO ABRIR ARQUIVO '_Rgs' PARA GRAVACAO!");
    }

    arq_telefones.open("data/_Telefones.txt",std::ios::out|std::ios::app);
    if(!arq_telefones.is_open()){
        arq_pessoacpf.close();
        arq_email.close();
        arq_rg.close();
        throw QString("FALHA AO ABRIR ARQUIVO '_Telefones' PARA GRAVACAO!");
    }
    arq_endereco.open("data/_Enderecos.txt",std::ios::out|std::ios::app);
    if(!arq_endereco.is_open()){
        arq_pessoacpf.close();
        arq_email.close();
        arq_rg.close();
        arq_telefones.close();
        throw QString("FALHA AO ABRIR ARQUIVO '_Enderecos' PARA GRAVACAO!");
    }

    bia::Cpf::cpf_t CPF = P.getCpf().getCpf();


    QString str;
    ///____________  GRAVAR NO ARQUIVO '_PessoaCpf.txt'________ [CPF ; NOME]
    str = QString::number(CPF) + ';' + P.getNome() + '\n';
    arq_pessoacpf << str.toStdString();
    arq_pessoacpf.close();

    ///___________ GRAVAR NO ARQUIVO '_Emails.txt'__________ [CPF ; EMAIL]
    str = QString::number(CPF) + ';' + P.getEmail();
    arq_email << str.toStdString() << '\n';
    arq_email.close();

    ///___________ GRAVAR NO ARQUIVO '_Rgs.txt' _____________ [CPF ; RG]
    str = QString::number(CPF) + ';' + QString::number(P.getRg());
    arq_rg << str.toStdString() << '\n';
    arq_rg .close();

    ///___________ GRAVAR NO ARQUIVO '_Telefones.txt'___________ [CPF ; DDI ; DDD ; NUMERO ; TIPO]
    std::vector<bia::Telefone> aux = P.getTelefones();
    for(std::vector<bia::Telefone>::iterator it = aux.begin() ; it != aux.end() ; ++it){
        str = QString::number(CPF) + ';'+
              QString::number(it->getDDI()) + ';'+
              QString::number(it->getDDD()) + ';'+
              QString::number(it->getNumero()) + ';'+
              it->getTipoStr() + '\n';
        arq_telefones << str.toStdString();
    }
    arq_telefones.close();

    ///________GRAVAR NO ARQUIVO '_Enderecos.txt'_______ [CPF ; LOGRADOURO ; BAIRRO ; NUMERO ; CEP ; CIDADE ]
    bia::Endereco temp =  P.getEndereco();
    str = QString::number( CPF ) + ';' +
          temp.getLogradouro() + ';' +
          temp.getBairro() +';'+
          QString::number(temp.getNumero()) + ';' +
          QString::number(temp.getCep()) + ';' +
          temp.getCidade() + '\n';
    arq_endereco << str.toStdString();
    arq_endereco.close();
}

void PessoaDAO::incluir(const std::map<bia::Cpf::cpf_t, bia::Pessoa> &M) const
{
    std::ofstream arq_pessoacpf;
    std::ofstream arq_email;
    std::ofstream arq_rg;
    std::ofstream arq_telefones;
    std::ofstream arq_endereco;

    arq_pessoacpf.open("data/_PessoaCpf.txt",std::ios::out);
    if(!arq_pessoacpf.is_open())
        throw QString("FALHA AO ABRIR ARQUIVO '_PessoaCpf' PARA GRAVACAO!");

    arq_email.open("data/_Emails.txt",std::ios::out);
    if(!arq_email.is_open()){
        arq_pessoacpf.close();
        throw QString("FALHA AO ABRIR ARQUIVO '_Emails' PARA GRAVACAO!");
    }

    arq_rg.open("_Rgs.txt",std::ios::out);
    if(!arq_rg.is_open()){
        arq_pessoacpf.close();
        arq_email.close();
        throw QString("FALHA AO ABRIR ARQUIVO '_Rgs' PARA GRAVACAO!");
    }

    arq_telefones.open("data/_Telefones.txt",std::ios::out);
    if(!arq_telefones.is_open()){
        arq_pessoacpf.close();
        arq_email.close();
        arq_rg.close();
        throw QString("FALHA AO ABRIR ARQUIVO '_Telefones' PARA GRAVACAO!");
    }
    arq_endereco.open("_Enderecos.txt",std::ios::out);
    if(!arq_endereco.is_open()){
        arq_pessoacpf.close();
        arq_email.close();
        arq_rg.close();
        arq_telefones.close();
        throw QString("FALHA AO ABRIR ARQUIVO '_Enderecos' PARA GRAVACAO!");
    }

    for(std::map<bia::Cpf::cpf_t,bia::Pessoa>::const_iterator it = M.begin() ; it != M.end() ; ++it){
        bia::Pessoa P = it->second;
        bia::Cpf::cpf_t CPF = P.getCpf().getCpf();
        QString str;
        ///____________  GRAVAR NO ARQUIVO '_PessoaCpf.txt'________ [CPF ; NOME]
        str = QString::number(CPF) + ';' + P.getNome() + '\n';
        arq_pessoacpf << str.toStdString();

        ///___________ GRAVAR NO ARQUIVO '_Emails.txt'__________ [CPF ; EMAIL]
        str = QString::number(CPF) + ';' + P.getEmail();
        arq_email << str.toStdString() << '\n';

        ///___________ GRAVAR NO ARQUIVO '_Rgs.txt' _____________ [CPF ; RG]
        str = QString::number(CPF) + ';' + QString::number(P.getRg());
        arq_rg << str.toStdString() << '\n';

        ///___________ GRAVAR NO ARQUIVO '_Telefones.txt'___________ [CPF ; DDI ; DDD ; NUMERO ; TIPO]
        std::vector<bia::Telefone> aux = P.getTelefones();
        for(std::vector<bia::Telefone>::iterator it = aux.begin() ; it != aux.end() ; ++it){
            str = QString::number(CPF) + ';'+
                  QString::number(it->getDDI()) + ';'+
                  QString::number(it->getDDD()) + ';'+
                  QString::number(it->getNumero()) + ';'+
                  it->getTipoStr() + '\n';
            arq_telefones << str.toStdString();
        }

        ///________GRAVAR NO ARQUIVO '_Enderecos.txt'_______ [CPF ; LOGRADOURO ; BAIRRO ; NUMERO ; CEP ; CIDADE ]
        bia::Endereco temp =  P.getEndereco();
        str = QString::number( CPF ) + ';' +
              temp.getLogradouro() + ';' +
              temp.getBairro() +';'+
              QString::number(temp.getNumero()) + ';' +
              QString::number(temp.getCep()) + ';' +
              temp.getCidade() + '\n';
        arq_endereco << str.toStdString();
    }
    // fecha todos os fluxos abertos
    arq_email.close();
    arq_endereco.close();
    arq_pessoacpf.close();
    arq_rg.close();
    arq_telefones.close();
}

std::map<bia::Cpf::cpf_t, bia::Pessoa> *PessoaDAO::listar() const
{
    ///\abertura dos arquivos para LEITURA
    std::ifstream arq_pessoacpf;
    std::ifstream arq_email;
    std::ifstream arq_rg;
    std::ifstream arq_telefones;
    std::ifstream arq_endereco;

    arq_pessoacpf.open("data/_PessoaCpf.txt",std::ios::app);
    if(!arq_pessoacpf.is_open())
        throw QString("FALHA AO ABRIR ARQUIVO '_PessoaCpf' PARA GRAVACAO!");

    arq_email.open("data/_Emails.txt",std::ios::app);
    if(!arq_email.is_open()){
        arq_pessoacpf.close();
        throw QString("FALHA AO ABRIR ARQUIVO '_Emails' PARA GRAVACAO!");
    }

    arq_rg.open("data/_Rgs.txt",std::ios::app);
    if(!arq_rg.is_open()){
        arq_pessoacpf.close();
        arq_email.close();
        throw QString("FALHA AO ABRIR ARQUIVO '_Rgs' PARA GRAVACAO!");
    }

    arq_telefones.open("data/_Telefones.txt",std::ios::app);
    if(!arq_telefones.is_open()){
        arq_pessoacpf.close();
        arq_email.close();
        arq_rg.close();
        throw QString("FALHA AO ABRIR ARQUIVO '_Telefones' PARA GRAVACAO!");
    }
    arq_endereco.open("data/_Enderecos.txt",std::ios::app);
    if(!arq_endereco.is_open()){
        arq_pessoacpf.close();
        arq_email.close();
        arq_rg.close();
        arq_telefones.close();
        throw QString("FALHA AO ABRIR ARQUIVO '_Enderecos' PARA GRAVACAO!");
    }

    std::string linha;
    std::map<bia::Cpf::cpf_t,bia::Pessoa> * PtMap = new std::map<bia::Cpf::cpf_t,bia::Pessoa>();


    /// ___________________________________ VARRE ARQUIVO '_PessoaCpf.txt' ___________________________
    std::getline(arq_pessoacpf,linha);
    while(!arq_pessoacpf.eof())
    {
        QString str = QString::fromStdString(linha);

        QStringList camps = str.split(";");

        if(camps.length() != 2){
            throw QString ("Houve um erro! Leitura do arquivo '_PessoaCpf.txt' fora do padrao!");
        }

        PtMap->operator []( camps[0].toLongLong() ).setCpf( bia::Cpf( camps[0].toLongLong() ) );
        PtMap->operator []( camps[0].toLongLong() ).setNome( camps[1] );
        std::getline(arq_pessoacpf,linha);
    }
    arq_pessoacpf.close();

    /// ____________________________________ VARRE ARQUIVO '_Emails.txt' ____________________________
    std::getline(arq_email,linha);
    while(!arq_email.eof()){
        QString str = QString::fromStdString(linha);
        QStringList camps = str.split(";");

        if(camps.length() != 2){
            throw QString ("Houve um erro! Leitura do arqruivo '_Emails.txt' fora do padrao!");
        }
        PtMap->operator [](camps[0].toLongLong()).setEmail(camps[1]);
        std::getline(arq_email,linha);
    }
    arq_email.close();

    /// ___________________________________ VARRE ARQUIVO '_Rgs.txt'________________________________
    std::getline(arq_rg,linha);
    while(!arq_rg.eof()){

        QString str = QString::fromStdString(linha);
        QStringList camps = str.split(";");
        if(camps.length() != 2){
            throw QString("Houve um erro! Leitura do arquivo '_Rgs.txt' fora do Padrao!");
        }
        PtMap->operator []( camps[0].toLongLong() ).setRg( camps[1].toInt() );
        std::getline(arq_rg,linha);
    }
    arq_rg.close();

    /// __________________________________VARRE ARQUIVOS '_Telefones.txt' _________[CPF ; DDI ; DDD ; NUMERO ; TIPO]_
    std::getline(arq_telefones,linha);
    while(!arq_telefones.eof()){
        QString str = QString::fromStdString(linha);
        QStringList camps = str.split(";");
        if(camps.length() != 5 ){
            throw QString("Houve um erro! Leitura do arquivo '_Telefones.txt' fora do padrao!");
        }
        bia::Telefone T;
        T.setDDI(camps[1].toInt() );
        T.setDDD(camps[2].toInt() );
        T.setNumero(camps[3].toInt() );
        T.setTipo(camps[4]);
        PtMap->operator [](camps[0].toLongLong()).adicionaTelefone(T);
        std::getline(arq_telefones,linha);
    }
    arq_telefones.close();

    /// __________________________________ VARRE ARQUIVOS '_Enderecos.txt___ [CPF ; LOGRADOURO ; BAIRRO ; NUMERO ; CEP ; CIDADE ]
    std::getline(arq_endereco,linha);
    while(!arq_endereco.eof()){
        QString str = QString::fromStdString(linha);
        QStringList camps = str.split(";");
        if(camps.length() != 6){
            throw QString("Houve um erro! Leitura do Arquivo '_Enderecos.txt' fora do Padrao!");
        }
        bia::Endereco E;
        E.setLogradouro(camps[1]);
        E.setBairro(camps[2]);
        E.setNumero(camps[3].toInt());
        E.setCep(camps[4].toInt());
        E.setCidade(camps[5]);

        PtMap->operator [](camps[0].toLongLong()).setEndereco(E);
        std::getline(arq_endereco,linha);
    }
    arq_endereco.close();
    return PtMap;
}

void PessoaDAO::atualizar(bia::Pessoa &P) const
{
    std::map<bia::Cpf::cpf_t,bia::Pessoa> *AUX = listar();
    AUX->operator [](P.getCpf().getCpf()) = P;
    incluir(*AUX);
    if(AUX) delete AUX;
}

void PessoaDAO::excluir(const bia::Cpf::cpf_t &cpf) const
{
    std::map<bia::Cpf::cpf_t,bia::Pessoa> * AUX = listar();
    AUX->erase(AUX->find(cpf));
    incluir(*AUX);
}
