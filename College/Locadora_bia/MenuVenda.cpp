#include "MenuVenda.h"
#include "ui_MenuVenda.h"

MenuVenda::MenuVenda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuVenda),Id("data/idVenda")
{
    ui->setupUi(this);
    ui->botaoSair->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/close-icon.png")));
    ui->botaoNovo->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/add-icon.png")));
    ui->botaoBuscar->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/search-icon.png")));
    ui->botaoConcluir->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/ok.png")));

    bia::VendaDAO DAOvendas;
    MapVendas = DAOvendas.listar();
    setEditMode(false);
    setBottons(true,true,false);
}

MenuVenda::~MenuVenda()
{
    delete ui;
    if(MapVendas) delete MapVendas;
}

void MenuVenda::LimpaCampos() const
{
    ui->lineEditCategoria->clear();
    ui->lineEditCorCarro->clear();
    ui->lineEditMarcaCarro->clear();
    ui->lineEditNomeCarro->clear();
    ui->lineEditPlaca->clear();
    ui->lineNomeCliente->clear();
    ui->textDescricao->clear();
    ui->SpinBoxPreco->setValue(0.00);
}

void MenuVenda::setEditMode(const bool &cur)
{
    ui->botaoSelecionaCliente->setEnabled(cur);
    ui->botaoEscolheCarro->setEnabled(cur);
    ui->SpinBoxPreco->setEnabled(cur);
    ui->textDescricao->setEnabled(cur);
    ui->lineCodVenda->setText(QString::number(Id.getNovoId()) );
    Id.removeUltimoId();
}

void MenuVenda::setBottons(const bool &Novo, const bool &Buscar, const bool &Concluir) const
{
    ui->botaoBuscar->setEnabled(Buscar);
    ui->botaoConcluir->setEnabled(Concluir);
    ui->botaoNovo->setEnabled(Novo);
}

void MenuVenda::setVenda()
{
    setEditMode(false);
    ui->lineNomeCliente->setText(venda.getCliente().getNome());
    ui->lineEditCategoria->setText(venda.getCarro().getCategoria().getCategoria());
    ui->lineEditCorCarro->setText(venda.getCarro().getCor());
    ui->lineEditMarcaCarro->setText(venda.getCarro().getModelo().getMarca().getMarca());
    ui->lineEditNomeCarro->setText(venda.getCarro().getModelo().getModelo());
    ui->lineEditPlaca->setText(venda.getCarro().getPlaca().getPlaca());
    ui->textDescricao->setText(venda.getDescricao());
    ui->lineCodVenda->setText(QString::number(venda.getId()));
    ui->SpinBoxPreco->setValue( venda.getValorDaVenda() );
}
void MenuVenda::ValidaDados() const
{
   if(ui->lineNomeCliente->text().isEmpty()) throw QString("Verifique o Cliente!");
   if(ui->SpinBoxPreco->value() == 0) throw QString("Verifique o valor do Carro!");
   if(ui->lineCodVenda->text().isEmpty()) throw QString("Verifique a escolha do carro!");
}

void MenuVenda::on_botaoSelecionaCliente_clicked()
{
    try{
        bia::Cliente *cliente = new bia::Cliente();
        ListarClientes Tela;
        bool flag = 0;

        Tela.setCliente(cliente,&flag);
        Tela.exec();

        if(flag)
        {

            this->venda.setCliente(*cliente);
            ui->lineNomeCliente->setText(venda.getCliente().getNome());
        }
        if(cliente) delete cliente;
    }catch(QString & error404){
        QMessageBox::warning(this," ",error404);
    }catch(std::bad_alloc & error404){
        QMessageBox::warning(this," ",error404.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}

void MenuVenda::on_botaoNovo_clicked()
{
    this->venda = bia::Venda();
    LimpaCampos();
    setEditMode(true);
    setBottons(true,true,true);
}

void MenuVenda::on_botaoEscolheCarro_clicked()
{
    try{

        bia::Carro * carro = new bia::Carro;
        bool flag = 0;
        ListarCarros Tela;
        Tela.setCarro(carro,&flag);
        Tela.exec();

        if(flag )
        {
            ui->lineEditCorCarro->setText(carro->getCor());
            ui->lineEditMarcaCarro->setText(carro->getModelo().getMarca().getMarca());
            ui->lineEditNomeCarro->setText(carro->getModelo().getModelo());
            ui->lineEditCategoria->setText(carro->getCategoria().getCategoria());
            ui->lineEditPlaca->setText(carro->getPlaca().getPlaca());

            this->venda.setCarro(*carro);
        }
        if(carro) delete carro;
    }catch(QString & erro){
        QMessageBox::warning(this," ",erro);
    }catch(std::bad_alloc & erro){
        QMessageBox::warning(this," ",erro.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}

void MenuVenda::on_botaoSair_clicked()
{
  this->close();
}

void MenuVenda::on_botaoBuscar_clicked()
{
    int id = 0;

    try{
        id = QInputDialog::getInt(this,"Codigo da Venda","Codigo da Venda : ");
        if(this->MapVendas->find(id) == this->MapVendas->end())
        {
            throw QString(" Codigo de aluguel Invalidosk ! ");
        }
        this->venda = this->MapVendas->operator [](id);

        setVenda();
        setBottons(true,true,false);
    }catch(QString & erro){
        QMessageBox::warning(this," ",erro);
    }catch(std::bad_alloc & erro){
        QMessageBox::warning(this," ",erro.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}

void MenuVenda::on_botaoConcluir_clicked() // botao que conclui venda
{
    bia::CarroDAO arqCarro;
    bia::Carro carro;

    try{
        ValidaDados();

        if(QMessageBox::question(this,"Concluir","Concluir venda?","Não", "Sim") == 1)
        {
          Id.getNovoId();
            bia::VendaDAO arqVenda;
            carro = venda.getCarro();
            carro.setSituacao(bia::Carro::Vendido);
            arqCarro.alterar(carro);

            this->venda.setCarro(carro);
            this->venda.setId ( ui->lineCodVenda->text().toInt());

            QString text = ui->textDescricao->toPlainText();
            QString Descricao;
            for(int i = 0 ; text[i] != '\0' ; ++i){
                if(text[i] != '\n') Descricao += text[i];
            }

            this->venda.setDescricao(Descricao);
            this->venda.setValorDaVenda(ui->SpinBoxPreco->text().toDouble());

            this->MapVendas->operator [](this->venda.getId()) = this->venda;            
            arqVenda.incluir( this->venda );

            bia::Relatorio::append("Carro \"" + this->venda.getCarro().getPlaca().getPlaca() +
                                   "\" vendido para \"" + this->venda.getCliente().getCpf().getCpf() + "\".");

            LimpaCampos();
            setEditMode(false);
        }
    }catch(QString & error404){
        QMessageBox::warning(this," ",error404);
    }catch(std::bad_alloc & error404){
        QMessageBox::warning(this," ",error404.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}

