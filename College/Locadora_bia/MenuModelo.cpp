#include "MenuModelo.h"
#include "ui_MenuModelo.h"

MenuModelo::MenuModelo(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::MenuModelo)
{
  ui->setupUi(this);

  // inicia
  this->setIcones("../Locadora_bia/Imagens/");

  // disabilita os botoes
  this->disableAll();

  // habilita apenas os necessarios
  ui->botaoBuscar->setEnabled(true);
  ui->botaoNovo->setEnabled(true);
}

MenuModelo::~MenuModelo()
{
  delete ui;
}

void MenuModelo::setIcones(const QString &diretorio)
{
  // seta os icones
  ui->botaoSair->setIcon(QIcon(QPixmap(diretorio + "close-icon.png")));
  ui->botaoNovo->setIcon(QIcon(QPixmap(diretorio + "add-icon.png")));
  ui->botaoCadastrar->setIcon(QIcon(QPixmap(diretorio + "save-icon.png")));
  ui->botaoBuscar->setIcon(QIcon(QPixmap(diretorio + "search-icon.png")));
  //ui->botaoEditar->setIcon(QIcon(QPixmap(diretorio + "edit-icon.png")));
  //ui->botaoExcluir->setIcon(QIcon(QPixmap(diretorio + "remove-icon.png")));
}

void MenuModelo::disableAll()
{
  // disabilita todos
  ui->botaoBuscar->setDisabled(true);
  ui->botaoCadastrar->setDisabled(true);
  //ui->botaoEditar->setDisabled(true);
  //ui->botaoExcluir->setDisabled(true);
  ui->botaoNovo->setDisabled(true);

  ui->boxMarca->clear();
  ui->boxMarca->setDisabled(true);

  ui->lineModelo->setReadOnly(false);
  ui->lineModelo->setDisabled(true);
}

void MenuModelo::clearAll()
{
  // limpa a tela
  ui->boxMarca->clear();
  ui->lineModelo->clear();
}

void MenuModelo::setMarcas()
{
  bia::MarcaDAO marcaDao;
  std::map < bia::Id, bia::Marca >* marcas = marcaDao.listar();
  std::map < bia::Id, bia::Marca >::iterator itMarca;

  ui->boxMarca->setEnabled(true);
  ui->boxMarca->clear();

  // insere na box
  for (itMarca = marcas->begin(); itMarca != marcas->end(); ++itMarca)
    ui->boxMarca->addItem(itMarca->second.getMarca());

  delete marcas;
}

void MenuModelo::on_botaoSair_clicked()
{
  if (ui->botaoCadastrar->isEnabled())
  {
    if (QMessageBox::question(this, "Cancelar", "Modelo não salvo.\nDeseja cancelar?", "Não", "Sim") == 1)
    {
      // disabilita todos
      this->disableAll();
      this->clearAll();

      // ativa o necessario
      ui->botaoBuscar->setEnabled(true);
      ui->botaoNovo->setEnabled(true);

      // volta texto ao normal
      ui->botaoCadastrar->setText("Cadastrar");
      ui->botaoSair->setText("Sair");
    }
  }
  else
  {
    this->close();
  }
}

void MenuModelo::on_botaoNovo_clicked()
{
  try
  {
    bia::MarcaDAO marcaDao;

    // verifica se existem marcas
    if (marcaDao.isEmpty())
      throw QString("Não existem marcas.\nInsira-as primeiro.");

    // disabilita
    this->disableAll();
    this->clearAll();

    // ativa os necessarios
    ui->boxMarca->setEnabled(true);
    ui->botaoCadastrar->setEnabled(true);
    ui->lineModelo->setEnabled(true);

    // muda o texto
    ui->botaoSair->setText("Cancelar");

    // seta as marcas
    this->setMarcas();
  }
  catch (QString& erro)
  {
    QMessageBox::critical(this, "Erro", erro);
    return;
  }
}

void MenuModelo::on_botaoCadastrar_clicked()
{
  // verifica se preencheu o modelo
  if (ui->lineModelo->text().isEmpty())
  {
    QMessageBox::warning(this, "Erro", "Preencha todos os campos.");
    return;
  }

  std::map < bia::Id, bia::Marca >* marcas = 0;
  std::map < bia::Id, bia::Marca >::iterator itMarca;

  try
  {
    bia::ModeloDAO modeloDao;
    bia::MarcaDAO marcaDao;
    marcas = marcaDao.listar();

    // procura o id
    for (itMarca = marcas->begin(); itMarca != marcas->end() && itMarca->second.getMarca() != ui->boxMarca->currentText(); ++itMarca);
    if (itMarca == marcas->end())
      throw QString("MenuModelo: Erro de lógica: end alcançado");

    if (ui->botaoCadastrar->text() == "Salvar")
    {
      modeloAtual.setMarca(itMarca->second);
      modeloAtual.setModelo(ui->lineModelo->text());

      bia::Relatorio::append("Modelo \"" + modeloAtual.getModelo() + "\" atualizado para \"" + ui->lineModelo->text() + "\".");

      modeloDao.atualizar(modeloAtual);

      ui->botaoCadastrar->setText("Cadastrar");
    }
    else
    {
      bia::GeradorDeId gerador("data/idModelo.dat");
      bia::Modelo modelo;

      // cria o modelo
      modelo.setId(gerador.getNovoId());
      modelo.setMarca(marcaDao.listar(itMarca->first));
      modelo.setModelo(ui->lineModelo->text());

      // inclui
      modeloDao.incluir(modelo);

      bia::Relatorio::append("Modelo \"" + ui->lineModelo->text() + "\" adicionado.");
    }

    // volta ao normal
    this->disableAll();
    this->clearAll();

    ui->botaoBuscar->setEnabled(true);
    ui->botaoNovo->setEnabled(true);

    ui->botaoSair->setText("Sair");
  }
  catch (QString& erro)
  {
    delete marcas;
    QMessageBox::critical(this, "Erro", erro);
    return;
  }

  delete marcas;
}

void MenuModelo::on_botaoBuscar_clicked()
{
  // pega o texto
  QString modelo = QInputDialog::getText(this, "Buscar", "Digite o nome do modelo:");

  // verifica se deixou em branco
  if (modelo.isEmpty())
    return;

  std::map < bia::Id, bia::Modelo >* modelos = 0;
  std::map < bia::Id, bia::Modelo >::iterator itModelo;

  try
  {
    bool found = false;
    bia::ModeloDAO modeloDao;

    // lista modelos
    modelos = modeloDao.listar();

    // ativa botoes
    ui->boxMarca->setEnabled(true);
    //ui->botaoEditar->setEnabled(true);
    //ui->botaoExcluir->setEnabled(true);

    // limpa combo box
    ui->boxMarca->clear();

    // procura os modelos
    for (itModelo = modelos->begin(); itModelo != modelos->end(); ++itModelo)
      if (itModelo->second.getModelo() == modelo)
      {
        ui->boxMarca->addItem(itModelo->second.getMarca().getMarca());        // insere a marca
        found = true;                                                         // flag que encontrou
      }

    // checa se preencheu
    if (!found)
      throw QString("Modelo não encontrado");

    // seta o modelo
    ui->lineModelo->setEnabled(true);
    ui->lineModelo->setText(modelo);
    ui->lineModelo->setReadOnly(true);
  }
  catch (QString& erro)
  {
    // volta ao normal
    this->disableAll();
    ui->botaoBuscar->setEnabled(true);
    ui->botaoNovo->setEnabled(true);

    delete modelos;

    // mostra excecao
    QMessageBox::critical(this, "Erro", erro);
    return;
  }

  delete modelos;
}
/*
void MenuModelo::on_botaoEditar_clicked()
{
  std::map < bia::Id, bia::Marca >* marcas = 0;
  std::map < bia::Id, bia::Modelo >* modelos = 0;
  std::map < bia::Id, bia::Marca >::iterator itMarca;
  std::map < bia::Id, bia::Modelo >::iterator itModelo;
  QString marca = ui->boxMarca->currentText();
  QString modelo = ui->lineModelo->text();

  try
  {
    bia::MarcaDAO marcaDao;
    bia::ModeloDAO modeloDao;

    // procura a marca
    marcas = marcaDao.listar();
    for (itMarca = marcas->begin(); itMarca != marcas->end() && itMarca->second.getMarca() != marca; ++itMarca);
    if (itMarca == marcas->end())
      throw QString("MenuModelo: Erro de lógica: end alcançado: marca");

    bia::Marca marca = itMarca->second;
    delete marcas;
    marcas = 0;

    // procura o modelo
    modelos = modeloDao.listar();
    for (itModelo = modelos->begin();
         itModelo != modelos->end() && (itModelo->second.getModelo() != modelo || itModelo->second.getMarca() != marca);
         ++itModelo);
    if (itModelo == modelos->end())
      throw QString("MenuModelo: Erro de lógica: end alcançado: modelo");

    bia::Id idModelo = itModelo->first;
    delete modelos;
    modelos = 0;

    // salva modelo sendo editado
    modeloAtual.setId(idModelo);
    modeloAtual.setMarca(marca);
    modeloAtual.setModelo(modelo);

    // atualiza tela
    this->disableAll();

    ui->lineModelo->setEnabled(true);
    ui->botaoCadastrar->setEnabled(true);
    ui->botaoCadastrar->setText("Salvar");

    // seta as marcas na box
    this->setMarcas();
  }
  catch (QString& erro)
  {
    delete marcas;
    delete modelos;
    QMessageBox::critical(this, "Erro", erro);
    return;
  }
}
//*/
/*
void MenuModelo::on_botaoExcluir_clicked()
{
  std::map < bia::Id, bia::Marca >* marcas = 0;
  std::map < bia::Id, bia::Modelo >* modelos = 0;
  std::map < bia::Id, bia::Marca >::iterator itMarca;
  std::map < bia::Id, bia::Modelo >::iterator itModelo;
  QString marca = ui->boxMarca->currentText();
  QString modelo = ui->lineModelo->text();

  try
  {
    bia::MarcaDAO marcaDao;
    bia::ModeloDAO modeloDao;

    // procura a marca
    marcas = marcaDao.listar();
    for (itMarca = marcas->begin(); itMarca != marcas->end() && itMarca->second.getMarca() != marca; ++itMarca);
    if (itMarca == marcas->end())
      throw QString("MenuModelo: Erro de lógica: end alcançado: marca");

    bia::Marca marca = itMarca->second;
    delete marcas;
    marcas = 0;

    // procura o modelo
    modelos = modeloDao.listar();
    for (itModelo = modelos->begin();
         itModelo != modelos->end() && (itModelo->second.getModelo() != modelo || itModelo->second.getMarca() != marca);
         ++itModelo);
    if (itModelo == modelos->end())
      throw QString("MenuModelo: Erro de lógica: end alcançado: modelo");

    bia::Id idModelo = itModelo->first;
    delete modelos;
    modelos = 0;

    // exclui modelo
    modeloDao.excluir(idModelo);

    // atualiza tela
    this->disableAll();
    this->clearAll();

    ui->botaoBuscar->setEnabled(true);
    ui->botaoNovo->setEnabled(true);
  }
  catch (QString& erro)
  {
    delete marcas;
    delete modelos;
    QMessageBox::critical(this, "Erro", erro);
    return;
  }
}
//*/
