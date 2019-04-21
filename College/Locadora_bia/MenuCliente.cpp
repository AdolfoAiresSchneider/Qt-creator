#include "MenuCliente.h"
#include "ui_MenuCliente.h"
#include <qicon.h>
#include "ClienteDAO.h"
#include <QInputDialog>
#include <QMessageBox>
#include <iostream>
using namespace std;


MenuCliente::MenuCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuCliente)
{
    ui->setupUi(this);

    ui->botaoSair->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/close-icon.png")));
    ui->botaoNovo->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/add-icon.png")));
    ui->botaoCadastrar->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/save-icon.png")));
    ui->botaoBuscar->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/search-icon.png")));
    ui->botaoEditar->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/edit-icon.png")));
    ui->botaoExcluir->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/remove-icon.png")));

    setBotons(false,true,true,false,false);
    EnabledBotons(false);
}

MenuCliente::~MenuCliente()
{
    delete ui;
}

void MenuCliente::setBotons(const bool Cadastrar, const bool Novo, const bool Buscar, const bool Editar, const bool Excluir) const
{
    ui->botaoCadastrar->setEnabled(Cadastrar);
    ui->botaoNovo->setEnabled(Novo);
    ui->botaoBuscar->setEnabled(Buscar);
    ui->botaoEditar->setEnabled(Editar);
    ui->botaoExcluir->setEnabled(Excluir);
}

void MenuCliente::setInf(bia::Cliente &A) const
{
    ui->lineNome->setText(A.getNome());
    ui->lineCpf->setText(QString::number(A.getCpf().getCpf()));
    ui->lineRg->setText(QString::number(A.getRg()));
    bia::Endereco E = A.getEndereco();
    ui->lineBairro->setText(E.getBairro());
    ui->lineCidade->setText(E.getCidade());
    ui->lineLogradouro->setText(E.getLogradouro());
    ui->lineNumero->setText(QString::number(E.getNumero()));
    ui->lineCep->setText(QString::number(E.getCep()));
    ui->lineCredito->setText(QString::number(A.getCartaoDeCredito()));
    ui->lineEmail->setText(A.getEmail());

    std::vector<bia::Telefone> T = A.getTelefones();

    for(std::vector<bia::Telefone>::iterator it = T.begin() ; it != T.end() ; ++it){
        setTelefone(*it);
    }
}

void MenuCliente::setTelefone(bia::Telefone &T) const
{

    if(T.getTipo() == bia::Telefone::Celular){
        ui->lineCelular->setText(QString::number(T.getNumero()));
        ui->lineCelularDDD->setText(QString::number(T.getDDD()));
        ui->lineCelularDDI->setText(QString::number(T.getDDI()));
    }
    else{
        ui->lineTel->setText(QString::number(T.getNumero()));
        ui->lineTelDDD->setText(QString::number(T.getDDD()));
        ui->lineTelDDI->setText(QString::number(T.getDDI()));

        if(T.getTipo() == bia::Telefone::Comercial)
            ui->radioButtonCom->setChecked(true);
        else
            ui->radioButtontRes->setChecked(true);
    }

}

void MenuCliente::getinf(bia::Cliente &C) const
{

    if(ui->lineNome->text().isEmpty()) throw QString("O campo 'Nome' esta vazio!");
    C.setNome( ui->lineNome->text() );

    if(ui->lineCpf->text().isEmpty()) throw QString("O campo 'CPF' esta vazio!");
    C.setCpf(ui->lineCpf->text().toLongLong());

    if(ui->lineRg->text().isEmpty()) throw QString("O campo 'RG' esta vazio!");
    C.setRg(ui->lineRg->text().toInt());

    bia::Endereco E;
    if(ui->lineBairro->text().isEmpty()) throw QString("O campo 'Bairro' esta vazio!");
    E.setBairro(ui->lineBairro->text());

    if(ui->lineNumero->text().isEmpty()) throw QString("O campo 'Numero' esta Vaxio!");
    E.setNumero(ui->lineNumero->text().toInt());

    if(ui->lineCidade->text().isEmpty()) throw QString("O campo 'Cidade' esta Vazio!");
    E.setCidade(ui->lineCidade->text());

    if(ui->lineCep->text().isEmpty()) throw QString("O campo 'Cep' esta vazio!");
    E.setCep(ui->lineCep->text().toInt());

    if(ui->lineLogradouro->text().isEmpty()) throw QString("O campo 'Logradouro' esta vazio!");
    E.setLogradouro(ui->lineLogradouro->text());
    C.setEndereco(E);

    if(ui->lineCredito->text().isEmpty()) throw QString("O campo 'Cartao de Credito' esta vazio!");
    C.setCartaoDeCredito( ui->lineCredito->text().toInt() );

    if(ui->lineEmail->text().isEmpty()) throw QString("O campo 'Email' esta vazio!");
    C.setEmail(ui->lineEmail->text());

    bia::Telefone T;

    if(ui->lineCelularDDD->text().isEmpty()) throw QString("Verifique o campo Celular!");
    T.setDDD(ui->lineCelularDDD->text().toInt());

    if(ui->lineCelularDDI->text().isEmpty()) throw QString("Verifique o campo Celular!");
    T.setDDI(ui->lineCelularDDI->text().toInt());

    if(ui->lineCelular->text().isEmpty()) throw QString("Verifique o campo Celular!");
    T.setNumero(ui->lineCelular->text().toInt());
    T.setTipo(bia::Telefone::Celular);

    C.adicionaTelefone(T);

    if(ui->lineTelDDD->text().isEmpty()) throw QString("Verifique o campo Telefone!");
    T.setDDD(ui->lineTelDDD->text().toInt());

    if(ui->lineTelDDI->text().isEmpty()) throw QString("Verifique o campo Telefone!");
    T.setDDI( ui->lineTelDDI->text().toInt());

    if(ui->lineTel->text().isEmpty()) throw QString("Verifique o campo Telefone!");
    T.setNumero( ui->lineTel->text().toInt() );

    if(ui->radioButtonCom->isChecked())
        T.setTipo(bia::Telefone::Comercial);
    else if(ui->radioButtontRes->isChecked())
        T.setTipo(bia::Telefone::Residencial);
    else throw QString("Selecione o tipo de telefone!");

    C.adicionaTelefone(T);

}

void MenuCliente::EnabledBotons(const bool sit) const
{
    ui->lineNome->setEnabled(sit);
    ui->lineRg->setEnabled(sit);
    ui->lineBairro->setEnabled(sit);
    ui->lineCidade->setEnabled(sit);
    ui->lineLogradouro->setEnabled(sit);
    ui->lineNumero->setEnabled(sit);
    ui->lineCep->setEnabled(sit);
    ui->lineCredito->setEnabled(sit);
    ui->lineEmail->setEnabled(sit);
    ui->lineCelular->setEnabled(sit);
    ui->lineCelularDDD->setEnabled(sit);
    ui->lineCelularDDI->setEnabled(sit);
    ui->lineTel->setEnabled(sit);
    ui->lineTelDDD->setEnabled(sit);
    ui->lineTelDDI->setEnabled(sit);
    ui->radioButtonCom->setEnabled(sit);
    ui->radioButtontRes->setEnabled(sit);
    ui->pushButton->setEnabled(sit);
}

void MenuCliente::setDadosPessoa(bia::Pessoa &P)
{
    ui->lineNome->setText(P.getNome());
    ui->lineEmail->setText(P.getEmail());
    ui->lineRg->setText(QString::number(P.getRg()));

    std::vector<bia::Telefone> T = P.getTelefones();

    for(std::vector<bia::Telefone>::iterator it = T.begin() ; it != T.end() ; ++it){
        setTelefone(*it);
    }
    bia::Endereco E = P.getEndereco();

    ui->lineBairro->setText(E.getBairro());
    ui->lineCidade->setText(E.getCidade());
    ui->lineLogradouro->setText(E.getLogradouro());
    ui->lineNumero->setText(QString::number(E.getNumero()));
    ui->lineCep->setText(QString::number(E.getCep()));
}

void MenuCliente::LimpaCampos() const
{
    ui->lineNome->clear();
    ui->lineCpf->clear();
    ui->lineRg->clear();
    ui->lineBairro->clear();
    ui->lineCidade->clear();
    ui->lineLogradouro->clear();
    ui->lineNumero->clear();
    ui->lineCep->clear();
    ui->lineCredito->clear();
    ui->lineEmail->clear();
    ui->lineCelular->clear();
    ui->lineCelularDDD->clear();
    ui->lineCelularDDI->clear();
    ui->lineTel->clear();
    ui->lineTelDDD->clear();
    ui->lineTelDDI->clear();
}

void MenuCliente::on_botaoSair_clicked()
{
    if(ui->botaoSair->text() == "Cancelar"){
      if(QMessageBox::question(this, "Cancelar", "Realmente Deseja Cancelar?", "Não", "Sim") == 1)
      {
        ui->botaoSair->setText("Sair");
        LimpaCampos();
        setBotons(false,true,true,false,false);
        EnabledBotons(false);
      }

    }
    else{
            this->close();
    }
}


void MenuCliente::on_botaoCadastrar_clicked()
{
    ui->botaoEditar->setText("Editar");
    try{
        bia::Cliente C;
        getinf(C);

            ui->botaoSair->setText("Sair");
            ClienteDAO DAO;
            DAO.incluir(C);
            bia::Relatorio::append("Cliente CPF \"" + QString::number(C.getCpf().getCpf()) + "\" cadastrado.");
            LimpaCampos();

            QMessageBox::information(this,"","Cliente Cadastrado Com Sucesso!");
            setBotons(false,true,true,false,false);
            EnabledBotons(false);
            LimpaCampos();
    }
    catch(QString error404){
        QMessageBox::information(this,"",error404);
    }

}

void MenuCliente::on_botaoBuscar_clicked()
{

    try{

        QInputDialog cpf;
        QString text(cpf.getText(this,"CPF do cliente:",""));
        bia::Cpf::cpf_t x = text.toLongLong();
        ClienteDAO DAO;
        std::map<bia::Cpf::cpf_t,bia::Cliente> * aux = DAO.listar();

        if(aux->find(x) != aux->end()){
            bia::Cliente C = aux->operator [](x);
            setInf(C);
            setBotons(false,true,true,true,true);
            EnabledBotons(false);
            ui->botaoEditar->setText("Editar");
        }
        else{
            QMessageBox::critical(this,"Atenção!","CPF nao encontrado ou grafia incorreta, siga o exemplo:\n\n EX: 555555555555");
        }

        if(aux) delete aux;
    }
    catch(QString error){
        QMessageBox::information(this,"",error);
    }
}

void MenuCliente::on_botaoNovo_clicked()
{
    LimpaCampos();
    EnabledBotons(true);
    setBotons(true,false,true,false,false);
    ui->botaoEditar->setText("Editar");
    ui->botaoSair->setText("Cancelar");
}

void MenuCliente::on_botaoEditar_clicked()
{
    if(ui->botaoEditar->text() == "Editar"){
        EnabledBotons(true);
        ui->lineCpf->setEnabled(false);
        ui->pushButton->setEnabled(false);
        ui->botaoEditar->setText("Salvar");
    }
    else{

        try{
            bia::Cliente C;
            getinf(C);

            if(QMessageBox::question(this, "Atualizar", "Realmente deseja Atualizar o cadrastro deste Cliente?","Não", "Sim") == 1)
            {
                ClienteDAO DAO;

                DAO.atualizar(C);
                bia::Relatorio::append("Cliente CPF \"" + QString::number(C.getCpf().getCpf()) + "\" atualizado.");
                cout << C.getNome().toStdString() << endl;
                ui->botaoEditar->setText("Editar");
                LimpaCampos();
            }
        }
        catch(QString &error404){
            QMessageBox::critical(this,"",error404);
        }
    }
}

void MenuCliente::on_botaoExcluir_clicked()
{
    if(QMessageBox::question(this, "Excluir", "Realmente deseja Excluir este Cliente?", "Não", "Sim") == 1){
        ClienteDAO DAO;
        DAO.excluir(ui->lineCpf->text().toLongLong());
        bia::Relatorio::append("Cliente CPF \"" + QString::number(ui->lineCpf->text().toLongLong()) + "\" removido.");
        QMessageBox::information(this,"SUCESSO!","Cliente excluido Com sucesso!!");
        LimpaCampos();
    }
}

void MenuCliente::on_pushButton_clicked()
{
    try{
        QInputDialog cpf;
        QString text(cpf.getText(this,"CPF do Cliente:",""));
        bia::Cpf::cpf_t x = text.toLongLong();

        ClienteDAO DAOC;
        std::map<bia::Cpf::cpf_t,bia::Cliente> * auxC = DAOC.listar();
        if(auxC->find(x) != auxC->end()){
            QMessageBox::critical(this,"EPA!","Esse CPF já esta cadrastrado com alguns dos nossos Clientes! Por favor verifique inconsistencias com nosso gerente!");
            if(auxC) delete auxC;
            return;
        }
        if(auxC) delete auxC;
        PessoaDAO DAO;
        std::map<bia::Cpf::cpf_t,bia::Pessoa> *aux = DAO.listar();

        if(aux->find(x) != aux->end()){
            QMessageBox::information(this,"Opa!","CPF encontrado no nosso banco de dados!\nIremos preencher os campos, casos mude iremos atualizar!");
            bia::Pessoa P = aux->operator [](x);
            setDadosPessoa(P);
            ui->lineCpf->setText(QString::number(x));
        }

        ui->lineCpf->setText(QString::number(x));
        if(aux) delete aux;





    }
    catch(QString &error404){
        QMessageBox::information(this,"Ishe!",error404);
    }
}
