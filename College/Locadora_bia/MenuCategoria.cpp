#include "MenuCategoria.h"
#include "ui_MenuCategoria.h"

MenuCategoria::MenuCategoria(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::MenuCategoria)
{
  ui->setupUi(this);

  // seta os icones nos botoes
  setIcones("../Locadora_bia/Imagens/");

  // reseta tela
  this->clearAll();
  this->disableAll();

  ui->botaoBuscar->setEnabled(true);
  ui->botaoNovo->setEnabled(true);
}

MenuCategoria::~MenuCategoria()
{
  delete ui;
}

void MenuCategoria::setIcones(const QString& diretorio)
{
  // seta os icones
  ui->botaoSair->setIcon(QIcon(QPixmap(diretorio + "close-icon.png")));
  ui->botaoNovo->setIcon(QIcon(QPixmap(diretorio + "add-icon.png")));
  ui->botaoCadastrar->setIcon(QIcon(QPixmap(diretorio + "save-icon.png")));
  ui->botaoBuscar->setIcon(QIcon(QPixmap(diretorio + "search-icon.png")));
  //ui->botaoEditar->setIcon(QIcon(QPixmap(diretorio + "edit-icon.png")));
  //ui->botaoExcluir->setIcon(QIcon(QPixmap(diretorio + "remove-icon.png")));
}

void MenuCategoria::disableAll()
{
  // disabilita todos
  ui->botaoBuscar->setDisabled(true);
  ui->botaoCadastrar->setDisabled(true);
  //ui->botaoEditar->setDisabled(true);
  //ui->botaoExcluir->setDisabled(true);
  ui->botaoNovo->setDisabled(true);

  ui->lineCategoria->setDisabled(true);
  ui->spinValorComercial->setDisabled(true);
  ui->spinValorPessoal->setDisabled(true);

  ui->lineCategoria->setReadOnly(false);
  ui->spinValorComercial->setReadOnly(false);
  ui->spinValorPessoal->setReadOnly(false);
}

void MenuCategoria::clearAll()
{
  // limpa tela
  ui->lineCategoria->clear();
  ui->spinValorComercial->setValue(ui->spinValorComercial->minimum());
  ui->spinValorPessoal->setValue(ui->spinValorPessoal->minimum());
}

void MenuCategoria::on_botaoSair_clicked()
{
  if (ui->botaoCadastrar->isEnabled())
  { // tela de cadastro
    if (QMessageBox::question(this, "Cancelar", "Categoria não salva.\nDeseja cancelar?", "Não", "Sim") == 1)
    {
      // reseta tela
      ui->botaoCadastrar->setText("Cadastrar");
      ui->botaoSair->setText("Sair");

      this->clearAll();
      this->disableAll();

      ui->botaoBuscar->setEnabled(true);
      ui->botaoNovo->setEnabled(true);
    }
  }
  else
  { // tela normal
    this->close();
  }
}

void MenuCategoria::on_botaoNovo_clicked()
{
  // reseta tela
  this->disableAll();
  this->clearAll();

  ui->botaoCadastrar->setEnabled(true);
  ui->lineCategoria->setEnabled(true);
  ui->spinValorComercial->setEnabled(true);
  ui->spinValorPessoal->setEnabled(true);
  ui->botaoSair->setText("Cancelar");
}

void MenuCategoria::on_botaoCadastrar_clicked()
{
  try
  {
    // checa se digitou algo
    if (ui->lineCategoria->text().isEmpty())
      throw QString("Preencha todos os campos.");

    bia::CategoriaDoCarroDAO categoriaDao;

    if (ui->botaoCadastrar->text() == "Salvar")
    {
      // input
      categoriaAtual.setCategoria(ui->lineCategoria->text());
      categoriaAtual.setValorLocacaoPessoal(ui->spinValorPessoal->value());
      categoriaAtual.setValorLocacaoTrabalho(ui->spinValorComercial->value());

      categoriaDao.alterar(this->categoriaAtual);
      bia::Relatorio::append("Categoria \"" + ui->lineCategoria->text() + "\" alterada.");

      ui->botaoCadastrar->setText("Cadastrar");
    }
    else
    {
      bia::GeradorDeId gerador("data/idCategoria.dat");
      bia::CategoriaDoCarro categoria;

      // seta info categoria
      categoria.setId(gerador.getNovoId());
      categoria.setCategoria(ui->lineCategoria->text());
      categoria.setValorLocacaoPessoal(ui->spinValorPessoal->value());
      categoria.setValorLocacaoTrabalho(ui->spinValorComercial->value());

      // inclui categoria
      categoriaDao.incluir(categoria);

      bia::Relatorio::append("Categoria \"" + ui->lineCategoria->text() + "\" adicionada.");
    }

    // reseta tela
    this->clearAll();
    this->disableAll();

    ui->botaoBuscar->setEnabled(true);
    ui->botaoNovo->setEnabled(true);
    ui->botaoSair->setText("Sair");
  }
  catch (QString& erro)
  {
    QMessageBox::critical(this, "Erro", erro);
    return;
  }
}

void MenuCategoria::on_botaoBuscar_clicked()
{
  std::map < bia::Id, bia::CategoriaDoCarro >* categorias = 0;
  std::map < bia::Id, bia::CategoriaDoCarro >::iterator itCateg;

  try
  {
    bia::CategoriaDoCarroDAO categoriaDao;

    QString nomeCategoria = QInputDialog::getText(this, "Buscar", "Digite o nome da categoria:");

    // busca id categoria
    categorias = categoriaDao.listar();
    for (itCateg = categorias->begin();
         itCateg != categorias->end() && itCateg->second.getCategoria() != nomeCategoria;
         ++itCateg);
    if (itCateg == categorias->end())
      throw QString("Categoria não encontrada.");

    bia::CategoriaDoCarro categoria = itCateg->second;
    delete categorias;
    categorias = 0;

    // seta na tela
    ui->lineCategoria->setText(categoria.getCategoria());
    ui->spinValorComercial->setValue(categoria.getValorLocacaoTrabalho());
    ui->spinValorPessoal->setValue(categoria.getValorLocacaoPessoal());

    // reseta tela
    //ui->botaoEditar->setEnabled(true);
    //ui->botaoExcluir->setEnabled(true);
    ui->lineCategoria->setEnabled(true);
    ui->spinValorComercial->setEnabled(true);
    ui->spinValorPessoal->setEnabled(true);

    ui->lineCategoria->setReadOnly(true);
    ui->spinValorComercial->setReadOnly(true);
    ui->spinValorPessoal->setReadOnly(true);
  }
  catch (QString& erro)
  {
    delete categorias;
    QMessageBox::critical(this, "Erro", erro);
    return;
  }
}
/*
void MenuCategoria::on_botaoEditar_clicked()
{
  std::map < bia::Id, bia::CategoriaDoCarro >* categorias = 0;
  std::map < bia::Id, bia::CategoriaDoCarro >::iterator itCateg;

  try
  {
    bia::CategoriaDoCarroDAO categoriaDao;

    // busca categoria
    categorias = categoriaDao.listar();
    for (itCateg = categorias->begin();
         itCateg != categorias->end() && itCateg->second.getCategoria() != ui->lineCategoria->text();
         ++itCateg);
    if (itCateg == categorias->end())
      throw QString("Editar: Erro de lógica: categoria não encontrada");

    categoriaAtual = itCateg->second;
    delete categorias;
    categorias = 0;

    // reseta tela
    this->disableAll();

    ui->botaoCadastrar->setEnabled(true);
    ui->lineCategoria->setEnabled(true);
    ui->spinValorComercial->setEnabled(true);
    ui->spinValorPessoal->setEnabled(true);

    ui->botaoCadastrar->setText("Salvar");
  }
  catch (QString& erro)
  {
    delete categorias;
    QMessageBox::critical(this, "Erro", erro);
    return;
  }
}
//*/
/*
void MenuCategoria::on_botaoExcluir_clicked()
{
  std::map < bia::Id, bia::CategoriaDoCarro >* categorias = 0;
  std::map < bia::Id, bia::CategoriaDoCarro >::iterator itCateg;

  try
  {
    bia::CategoriaDoCarroDAO categoriaDao;

    // busca categoria
    categorias = categoriaDao.listar();
    for (itCateg = categorias->begin();
         itCateg != categorias->end() && itCateg->second.getCategoria() != ui->lineCategoria->text();
         ++itCateg);
    if (itCateg == categorias->end())
      throw QString("Editar: Erro de lógica: categoria não encontrada");

    bia::CategoriaDoCarro categoria = itCateg->second;
    delete categorias;
    categorias = 0;

    // remove
    categoriaDao.excluir(categoria.getId());
    bia::Relatorio::append("");

    // reseta tela
    this->disableAll();
    this->clearAll();

    ui->botaoBuscar->setEnabled(true);
    ui->botaoNovo->setEnabled(true);
  }
  catch (QString& erro)
  {
    delete categorias;
    QMessageBox::critical(this, "Erro", erro);
    return;
  }
}
//*/
