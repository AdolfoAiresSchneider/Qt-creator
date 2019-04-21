#include "MenuCondutor.h"
#include "ui_MenuCondutor.h"
#include <QMessageBox>
#include "CondutorDAO.h"
#include <QInputDialog>
#include "Pessoa.h"
#include "PessoaDAO.h"

MenuCondutor::MenuCondutor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuCondutor)
{
    ui->setupUi(this);

    ui->botaoSair->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/close-icon.png")));
    ui->botaoNovo->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/add-icon.png")));
    ui->botaoCadastrar->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/save-icon.png")));
    ui->botaoBuscar->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/search-icon.png")));
    ui->botaoEditar->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/edit-icon.png")));
    ui->botaoExcluir->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/remove-icon.png")));
    setBotons(false,true,true,false,false);
    setEditMode(false);
    this->setWindowTitle("Menu Condutor");
}

MenuCondutor::~MenuCondutor()
{
    delete ui;
}

void MenuCondutor::setEditMode(const bool e)
{
    ui->lineNome->setEnabled(e);
    ui->lineRg->setEnabled(e);
    ui->lineLogradouro->setEnabled(e);
    ui->lineNumero->setEnabled(e);
    ui->lineBairro->setEnabled(e);
    ui->lineCidade->setEnabled(e);
    ui->lineCep->setEnabled(e);
    ui->lineCNH->setEnabled(e);
    ui->lineCelular->setEnabled(e);
    ui->lineCelularDDD->setEnabled(e);
    ui->lineCelularDDI->setEnabled(e);
    ui->lineTel->setEnabled(e);
    ui->lineTelDDD->setEnabled(e);
    ui->lineTelDDI->setEnabled(e);
    ui->dateExpiracao->setEnabled(e);
    ui->dateExpedicao->setEnabled(e);
    ui->lineEmail->setEnabled(e);
    ui->radioButtonCom->setEnabled(e);
    ui->radioButtonRes->setEnabled(e);
    ui->PushButtonInsertCpf->setEnabled(e);
}

void MenuCondutor::setBotons(const bool Cadrastrar, const bool Novo, const bool Buscar, const bool Editar, const bool Excluir) const
{
    ui->botaoCadastrar->setEnabled(Cadrastrar);
    ui->botaoNovo->setEnabled(Novo);
    ui->botaoBuscar->setEnabled(Buscar);
    ui->botaoEditar->setEnabled(Editar);
    ui->botaoExcluir->setEnabled(Excluir);
}

void MenuCondutor::getInf(bia::Condutor &C) const
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

    if(ui->lineEmail->text().isEmpty()) throw QString("O campo 'Email' esta vazio!");
    C.setEmail(ui->lineEmail->text());

    bia::Cnh CNH;

    if(ui->lineCNH->text().isEmpty() ) throw QString("O campo 'CNH' esta vazio!");
    CNH.setCnh(ui->lineCNH->text().toLongLong());

    if(!ui->dateExpedicao->date().isValid()) throw QString("Informe uma data de Emissão valida!");
    CNH.setemissao(ui->dateExpedicao->date());

    if(!ui->dateExpiracao->date().isValid()) throw QString("Informe uma data Expiração valida!");
    CNH.setexpiracao(ui->dateExpiracao->date());

    C.setCnh(CNH);

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
    else if(ui->radioButtonRes->isChecked())
        T.setTipo(bia::Telefone::Residencial);
    else throw QString("Selecione o tipo de telefone!");

    C.adicionaTelefone(T);

}

void MenuCondutor::setInf(bia::Condutor &A) const
{
        ui->lineNome->setText( A.getNome() );
        ui->lineCpf->setText(QString::number( A.getCpf().getCpf()) );
        ui->lineRg->setText(QString::number( A.getRg() ));
        bia::Endereco E = A.getEndereco();
        ui->lineBairro->setText(E.getBairro());
        ui->lineCidade->setText(E.getCidade());
        ui->lineLogradouro->setText(E.getLogradouro());
        ui->lineNumero->setText(QString::number(E.getNumero()));
        ui->lineCep->setText(QString::number(E.getCep()));
        ui->lineCNH->setText(QString::number(A.getCnh().getCnh()));
        ui->lineEmail->setText(A.getEmail());

        std::vector<bia::Telefone> T = A.getTelefones();

        for(std::vector<bia::Telefone>::iterator it = T.begin() ; it != T.end() ; ++it){
            setTelefone(*it);
        }
}

void MenuCondutor::setTelefone(bia::Telefone &T) const
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
            ui->radioButtonRes->setChecked(true);
    }
}

void MenuCondutor::limpaCampos() const
{
    ui->lineNome->clear();
    ui->lineCpf->clear();
    ui->lineRg->clear();
    ui->lineBairro->clear();
    ui->lineCidade->clear();
    ui->lineNumero->clear();
    ui->lineCidade->clear();
    ui->lineLogradouro->clear();
    ui->lineCep->clear();
    ui->lineCNH->clear();
    ui->lineEmail->clear();
    ui->dateExpedicao->clear();
    ui->dateExpiracao->clear();
    ui->lineCelular->clear();
    ui->lineCelularDDD->clear();
    ui->lineCelularDDI->clear();
    ui->lineTel->clear();
    ui->lineTelDDD->clear();
    ui->lineTelDDI->clear();
    ui->radioButtonCom->clearFocus();
    ui->radioButtonRes->clearFocus();
}


void MenuCondutor::setDadosPessoa(bia::Pessoa &P)
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

void MenuCondutor::on_botaoCadastrar_clicked()
{
    ui->botaoEditar->setText("Editar");
    try{
        bia::Condutor C;
        getInf(C);

            ui->botaoSair->setText("Sair");
            setBotons(false,true,true,false,false);
            CondutorDAO DAO;
            DAO.incluir(C);
            bia::Relatorio::append("Condutor CPF \"" + QString::number(C.getCpf().getCpf()) + "\" cadastrado.");
            limpaCampos();
            setEditMode(false);
            QMessageBox::information(this,"","Condutor Cadastrado Com Sucesso!");
    }
    catch(QString &error404){
        QMessageBox::information(this,"",error404);
    }
}

void MenuCondutor::on_botaoNovo_clicked()
{
    ui->botaoEditar->setText("Editar");
    setBotons(true,true,false,false,false);
    limpaCampos();
    setEditMode(false);
    ui->PushButtonInsertCpf->setEnabled(true);
    ui->botaoSair->setText("Cancelar");
}

void MenuCondutor::on_botaoBuscar_clicked()
{
    try{
        QInputDialog cpf;
        QString text(cpf.getText(this,"CPF do Condutor:",""));
        bia::Cpf::cpf_t x = text.toLongLong();
        CondutorDAO DAO;
        std::map<bia::Cpf::cpf_t,bia::Condutor> * aux = DAO.listar();

        if(aux->find(x) != aux->end()){
            bia::Condutor C = aux->operator [](x);
            setInf(C);
            setBotons(false,true,true,true,true);
            setEditMode(false);
            ui->botaoEditar->setText("Editar");
            ui->botaoSair->setText("Cancelar");
            if(aux) delete aux;
        }
        else{
            QMessageBox::critical(this,"Atenção!","CPF nao encontrado ou grafia incorreta, siga o exemplo:\n\n EX: 555555555555");
            if(aux) delete aux;
        }
    }
    catch(QString &error){
        QMessageBox::information(this,"",error);
    }
}

void MenuCondutor::on_botaoEditar_clicked()
{
    if(ui->botaoEditar->text() == "Editar"){
        setEditMode(true);
        ui->lineCpf->setEnabled(false);
        ui->PushButtonInsertCpf->setEnabled(false);
        ui->botaoEditar->setText("Salvar");
        ui->botaoSair->setText("Cancelar");
    }
    else{

        try{
            bia::Condutor C;
            getInf(C);

            if(QMessageBox::question(this, "Editar","Realmente deseja Atualizar o cadrastro deste Condutor?" ,"Não", "Sim") == 1)
            {
                CondutorDAO DAO;
                DAO.atualizar(C);
                bia::Relatorio::append("Condutor CPF \"" + QString::number(C.getCpf().getCpf()) + "\" atualizado.");
                ui->botaoEditar->setText("Editar");
                ui->botaoSair->setText("Sair");
                limpaCampos();
            }
        }
        catch(QString &error404){
            QMessageBox::critical(this, "Erro",error404);
        }
    }
}

void MenuCondutor::on_botaoExcluir_clicked()
{
    if(QMessageBox::question(this, "Excluir", "Realmente deseja Excluir este Condutor?", "Não", "Sim") == 1){
        CondutorDAO DAO;
        DAO.excluir(ui->lineCpf->text().toLongLong());
        bia::Relatorio::append("Condutor \"" + QString::number(ui->lineCpf->text().toLongLong()) + "\" removido.");
        QMessageBox::information(this,"SUCESSO!","Cliente excluido Com sucesso!!");
        limpaCampos();
    }
}

void MenuCondutor::on_botaoSair_clicked()
{
    if(ui->botaoSair->text() == "Cancelar")
    {
      if(QMessageBox::question(this, "Cancelar", "Qualquer alteração realizada não será salva.\nRealmente Deseja Cancelar?", "Não", "Sim") == 1)
      {
        setBotons(false,true,true,false,false);
        setEditMode(false);
        ui->botaoEditar->setText("Editar");
        ui->botaoSair->setText("Sair");
        limpaCampos();
      }
    }
    else{
      this->close();
    }
}

void MenuCondutor::on_PushButtonInsertCpf_clicked()
{
    try{
        QInputDialog cpf;
        QString text(cpf.getText(this, "CPF", "CPF do Condutor:"));
        bia::Cpf::cpf_t x = text.toLongLong();
        ui->lineCpf->setText(QString::number(x));
        setEditMode(true);

        CondutorDAO DAOC;
        std::map<bia::Cpf::cpf_t,bia::Condutor> * auxC = DAOC.listar();
        if(auxC->find(x) != auxC->end()){
            QMessageBox::critical(this,"EPA!","Esse CPF já esta cadrastrado com alguns dos nossos Condutores!\nPor favor verifique inconsistencias com nosso gerente!");
            if(auxC) delete auxC;
            return;
        }
        if(auxC) delete auxC;



        PessoaDAO DAO;

        std::map<bia::Cpf::cpf_t,bia::Pessoa> *aux = DAO.listar();

        if(aux->find(x) != aux->end()){
            QMessageBox::information(this,"Opa!","CPF encontrado no nosso banco de dados!\nPara atualizar modifique os dados!");
            bia::Pessoa P = aux->operator [](x);
            setDadosPessoa(P);
        }
         if(aux) delete aux;
    }
    catch(QString &error404){
        QMessageBox::information(this,"Ishe!",error404);
    }
}
