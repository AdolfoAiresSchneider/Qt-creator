#include "MenuMarca.h"
#include "ui_MenuMarca.h"

MenuMarca::MenuMarca(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::MenuMarca)
{
  ui->setupUi(this);

  // seta os icones nos botoes
  this->setIcones("../Locadora_bia/Imagens/");

  // disabilita tudo
  this->disableAll();

  // habilita apenas os que serao usados
  ui->botaoBuscar->setEnabled(true);
  ui->botaoNovo->setEnabled(true);
}

MenuMarca::~MenuMarca()
{
  delete ui;
}

void MenuMarca::setIcones(const QString &diretorio)
{
  // seta os icones
  ui->botaoSair->setIcon(QIcon(QPixmap(diretorio + "close-icon.png")));
  ui->botaoNovo->setIcon(QIcon(QPixmap(diretorio + "add-icon.png")));
  ui->botaoCadastrar->setIcon(QIcon(QPixmap(diretorio + "save-icon.png")));
  ui->botaoBuscar->setIcon(QIcon(QPixmap(diretorio + "search-icon.png")));
  //ui->botaoEditar->setIcon(QIcon(QPixmap(diretorio + "edit-icon.png")));
  //ui->botaoExcluir->setIcon(QIcon(QPixmap(diretorio + "remove-icon.png")));
}

void MenuMarca::disableAll()
{
  // disabilita tudo exceto sair
  ui->botaoBuscar->setDisabled(true);
  ui->botaoCadastrar->setDisabled(true);
  //ui->botaoEditar->setDisabled(true);
  //ui->botaoExcluir->setDisabled(true);
  ui->botaoNovo->setDisabled(true);

  ui->lineMarca->setReadOnly(false);
  ui->lineMarca->setDisabled(true);
}

void MenuMarca::clearAll()
{
  // limpa a tela
  ui->lineMarca->clear();
}

void MenuMarca::on_botaoSair_clicked()
{
  // checa qual o modo
  if (ui->botaoCadastrar->isEnabled())
  { // tela de novo
    if (QMessageBox::question(this, "Aviso", "Marca não salva.\nDeseja cancelar?") == QMessageBox::Yes)
    { // quer cancelar
      // reseta
      this->clearAll();
      this->disableAll();

      // ativa os necessarios
      ui->botaoBuscar->setEnabled(true);
      ui->botaoNovo->setEnabled(true);

      // volta texto normal
      ui->botaoCadastrar->setText("Cadastrar");
      ui->botaoSair->setText("Sair");
    }
  }
  else
  { // tela normal
    this->close();
  }
}

void MenuMarca::on_botaoNovo_clicked()
{
  // disabilita todos
  this->disableAll();
  this->clearAll();

  // habilita os necessarios
  ui->botaoCadastrar->setEnabled(true);
  ui->lineMarca->setEnabled(true);

  // muda o texto do sair
  ui->botaoSair->setText("Cancelar");
}

void MenuMarca::on_botaoCadastrar_clicked()
{
  // checa se digitou algo
  if (ui->lineMarca->text().isEmpty())
  {
    QMessageBox::warning(this, "Erro", "Marca vazia");
    return;
  }

  // leitura
  try
  {
    bia::MarcaDAO marcaDao;

    // checa se é para incluir ou atualizar
    if (ui->botaoCadastrar->text() == "Salvar")
    { // atualizar
      ui->botaoCadastrar->setText("Cadastrar");
      bia::Marca marca = marcaDao.listar(idMarcaBuscada);

      bia::Relatorio::append("Marca \"" + marca.getMarca() + "\" atualizada para \"" + ui->lineMarca->text() + "\".");

      marca.setMarca(ui->lineMarca->text());
      marcaDao.atualizar(marca);
    }
    else
    { // incluir
      bia::GeradorDeId gerador("data/idMarca.dat");

      // inclui uma nova
      marcaDao.incluir(bia::Marca(gerador.getNovoId(), ui->lineMarca->text()));

      bia::Relatorio::append("Marca \"" + ui->lineMarca->text() + "\" adicionada.");
    }

    // disabilita todos
    this->disableAll();
    this->clearAll();

    // habilita os necessarios
    ui->botaoBuscar->setEnabled(true);
    ui->botaoNovo->setEnabled(true);

    // volta o texto original
    ui->botaoSair->setText("Sair");
  }
  catch (QString& erro)
  { // erro
    QMessageBox::critical(this, "Erro", erro);
    return;
  }
}

void MenuMarca::on_botaoBuscar_clicked()
{
  QString marca;
  std::map < bia::Id, bia::Marca >* marcas = 0;

  try
  {
    marca = QInputDialog::getText(this, "Buscar", "Digite a marca:");
    if (marca.isEmpty())
      return;

    bia::MarcaDAO marcaDao;
    marcas = marcaDao.listar();
    std::map < bia::Id, bia::Marca >::iterator itMarca;

    for (itMarca = marcas->begin(); itMarca != marcas->end() && itMarca->second.getMarca() != marca; ++itMarca);
    if (itMarca == marcas->end())
      throw QString("Erro: Marca não encontrada");

    this->disableAll();

    ui->botaoNovo->setEnabled(true);
    ui->botaoBuscar->setEnabled(true);
    //ui->botaoEditar->setEnabled(true);
    //ui->botaoExcluir->setEnabled(true);
    ui->lineMarca->setEnabled(true);

    ui->lineMarca->setText(marca);
    ui->lineMarca->setReadOnly(true);

    this->idMarcaBuscada = itMarca->first;
  }
  catch (QString& erro)
  {
    delete marcas;
    QMessageBox::critical(this, "Erro", erro);
    return;
  }

  delete marcas;
}
/*
void MenuMarca::on_botaoEditar_clicked()
{
  this->disableAll();

  ui->botaoCadastrar->setEnabled(true);

  ui->botaoCadastrar->setText("Salvar");
  ui->botaoSair->setText("Cancelar");

  ui->lineMarca->setEnabled(true);
}
//*/
/*
void MenuMarca::on_botaoExcluir_clicked()
{
  if (QMessageBox::question(this, "Excluir", "Tem certeza?") == QMessageBox::Yes)
  {
    // exclui
    bia::MarcaDAO marcaDao;
    marcaDao.excluir(idMarcaBuscada);

    // reseta a tela
    this->disableAll();
    this->clearAll();

    ui->botaoNovo->setEnabled(true);
    ui->botaoBuscar->setEnabled(true);
  }
}
//*/
