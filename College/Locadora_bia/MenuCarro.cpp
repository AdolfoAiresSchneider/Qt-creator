#include "MenuCarro.h"
#include "ui_MenuCarro.h"
#include <QFileDialog>
#include <QPicture>
#include <QPixmap>

#include <iostream>
using namespace std;

MenuCarro::MenuCarro(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::MenuCarro)
{

  ui->setupUi(this);
  flag = 0;

  // seta os icones nos botoes
  setIcones("../Locadora_bia/Imagens/");

  // desabilita todos os botoes exceto sair
  disableAll();

  // habilita apenas os que serao usados
  ui->botaoNovo->setEnabled(true);
  ui->botaoBuscar->setEnabled(true);
}

MenuCarro::~MenuCarro()
{
  delete ui;
}

void MenuCarro::on_botaoSair_clicked()
{
  if (ui->botaoCadastrar->isEnabled())
  { // esta na tela de cadastro
    if (QMessageBox::question(this, "Tem certeza?", "Cliente não salvo.\nDeseja cancelar?") == QMessageBox::Yes)
    { // quer cancelar
      // limpa tudo
      this->clearAll();
      this->disableAll();

      // reseta botoes
      ui->botaoBuscar->setEnabled(true);
      ui->botaoNovo->setEnabled(true);

      // muda texto
      ui->botaoSair->setText("Sair");
    }
  }
  else
  { // esta na tela normal
    // fecha janela
    this->close();
  }
}

void MenuCarro::on_botaoNovo_clicked()
{
  try
  {
    bia::MarcaDAO marcaDao;
    if (marcaDao.isEmpty())
      throw QString("Não existem marcas.\nInsira-as primeiro.");

    bia::CategoriaDoCarroDAO categoriaDao;
    if (categoriaDao.isEmpty())
      throw QString("Não existem categorias.\nInsira-as primeiro.");

    // desabilita todos os botoes
    this->disableAll();

    // habilita os que serao usados
    ui->botaoCadastrar->setEnabled(true);

    ui->lineCor->setEnabled(true);
    ui->linePlaca->setEnabled(true);

    ui->boxMarca->setEnabled(true);
    ui->boxModelo->setEnabled(true);
    ui->boxCategoria->setEnabled(true);

    // reinicia os valores da tela
    this->clearAll();

    // seta info
    setMarcas ();
    setCategorias ();

    // muda texto do botao sair para cancelar
    ui->botaoSair->setText("Cancelar");
  }
  catch (QString& erro)
  {
    QMessageBox::critical(this, "Erro", erro);
    return;
  }
}

void MenuCarro::on_botaoBuscar_clicked()
{
  try
  {
    bia::CarroDAO carroDao;

    // leitura da placa
    bia::Placa placa (QInputDialog::getText(this, "Busca", "Digite a placa do carro:"));

    // procura placa
    bia::Carro carro = carroDao.listar(placa);

    // ativa para uso
    ui->lineCor->setEnabled(true);
    ui->linePlaca->setEnabled(true);
    ui->boxMarca->setEnabled(true);
    ui->boxModelo->setEnabled(true);
    ui->boxCategoria->setEnabled(true);

    // limpa tela
    ui->boxMarca->clear();
    ui->boxModelo->clear();
    ui->boxCategoria->clear();

    // seta informacoes
    ui->lineCor->setText(carro.getCor());
    ui->linePlaca->setText(carro.getPlaca().getPlaca());
    ui->boxMarca->addItem(carro.getModelo().getMarca().getMarca());
    ui->boxModelo->addItem(carro.getModelo().getModelo());
    ui->boxCategoria->addItem(carro.getCategoria().getCategoria());
    ui->label_7->setPixmap(QPixmap("cars/"+carro.getPlaca().getPlaca()));
    ui->label_7->setScaledContents(true);

    // libera apenas para leitura
    ui->lineCor->setReadOnly(true);
    ui->linePlaca->setReadOnly(true);

    // libera opcoes de editar ou excluir
    ui->botaoEditar->setEnabled(true);
    ui->botaoExcluir->setEnabled(true);
  }
  catch (QString& erro)
  {
    QMessageBox::critical(this, "Erro", erro);
    return;
  }
}

void MenuCarro::on_botaoEditar_clicked()
{
  // desabilita tudo exceto sair
  this->disableAll();

  // muda o texto no botao
  ui->botaoCadastrar->setText("Salvar");
  ui->botaoSair->setText("Cancelar");

  // ativa o necessario
  ui->botaoCadastrar->setEnabled(true);
  ui->lineCor->setEnabled(true);
  ui->linePlaca->setEnabled(true);
  ui->boxMarca->setEnabled(true);
  ui->boxModelo->setEnabled(true);
  ui->boxCategoria->setEnabled(true);

  ui->linePlaca->setReadOnly(true); // nao pode editar a placa

  this->setMarcas();
  this->setCategorias();
  ui->boxModelo->clear();
}

void MenuCarro::on_botaoExcluir_clicked()
{
  try
  {
    // exclui a placa
    bia::CarroDAO carroDao;
    carroDao.excluir(bia::Placa(ui->linePlaca->text()));

    bia::Relatorio::append("Carro \"" + ui->linePlaca->text() + "\" excluído.");
  }
  catch (QString& erro)
  {
    QMessageBox::critical(this, "Erro", erro);
    return;
  }

  // reseta tela
  this->disableAll();
  this->clearAll();

  ui->botaoBuscar->setEnabled(true);
  ui->botaoNovo->setEnabled(true);
}

void MenuCarro::on_botaoCadastrar_clicked()
{
  std::map < bia::Id, bia::CategoriaDoCarro >* categorias = 0;
  std::map < bia::Id, bia::CategoriaDoCarro >::iterator itCategoria;
  std::map < bia::Id, bia::Modelo >* modelos = 0;
  std::map < bia::Id, bia::Modelo >::iterator itModelo;

  try
  {
    if (ui->linePlaca->text().isEmpty())
      throw QString("Placa necessária para criação do carro.");

    if(!flag)
        throw QString("Selecione uma foto");

    bia::CategoriaDoCarroDAO categoriaDao;
    bia::ModeloDAO modeloDao;
    bia::CarroDAO carroDao;

    // busca o id da categoria
    categorias = categoriaDao.listar();
    for (itCategoria = categorias->begin();
         itCategoria != categorias->end() && itCategoria->second.getCategoria() != ui->boxCategoria->currentText();
         ++itCategoria);
    if (itCategoria == categorias->end())
      throw QString("Categoria: end alcançado");

    bia::CategoriaDoCarro categoria = itCategoria->second;
    delete categorias;
    categorias = 0;

    // busca o id do modelo
    modelos = modeloDao.listar();
    for (itModelo = modelos->begin();
         itModelo != modelos->end() && itModelo->second.getModelo() != ui->boxModelo->currentText();
         ++itModelo);
    if (itModelo == modelos->end())
      throw QString("Modelo: end alcançado");

    bia::Modelo modelo = itModelo->second;
    delete modelos;
    modelos = 0;

    if (ui->botaoCadastrar->text() == "Salvar")
    {
      bia::Carro carro = carroDao.listar(bia::Placa(ui->linePlaca->text()));
      carro.setPlaca(ui->linePlaca->text());
      carro.setCor(ui->lineCor->text());
      carro.setModelo(modelo);
      carro.setCategoria(categoria);

      carroDao.alterar(carro);

      bia::Relatorio::append("Carro \"" + ui->linePlaca->text() + "\" editado.");
      ui->label_7->clear();
      ui->botaoCadastrar->setText("Cadastrar");
    }
    else
    {
      bia::Carro inputCarro;

      // pega a entrada
      inputCarro.setKmRodados(0);
      inputCarro.setCor(ui->lineCor->text());
      inputCarro.setPlaca(ui->linePlaca->text());
      inputCarro.setCategoria(categoria);
      inputCarro.setSituacao(bia::Carro::Disponivel);
      inputCarro.setModelo(modelo);

      QFile::copy(end.toStdString().c_str(),"cars/"+inputCarro.getPlaca().getPlaca());
      bia::Relatorio::append("Carro \"" + ui->linePlaca->text() + "\" editado.");
      carroDao.incluir(inputCarro);
      bia::Relatorio::append("Carro \"" + ui->linePlaca->text() + "\" adicionado.");
      ui->label_7->clear();
    }

    // reseta a tela
    this->disableAll();
    this->clearAll();

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

void MenuCarro::setIcones(const QString &diretorio)
{
  // seta os icones
  ui->botaoSair->setIcon(QIcon(QPixmap(diretorio + "close-icon.png")));
  ui->botaoNovo->setIcon(QIcon(QPixmap(diretorio + "add-icon.png")));
  ui->botaoCadastrar->setIcon(QIcon(QPixmap(diretorio + "save-icon.png")));
  ui->botaoBuscar->setIcon(QIcon(QPixmap(diretorio + "search-icon.png")));
  ui->botaoEditar->setIcon(QIcon(QPixmap(diretorio + "edit-icon.png")));
  ui->botaoExcluir->setIcon(QIcon(QPixmap(diretorio + "remove-icon.png")));
}

void MenuCarro::disableAll()
{
  // desabilita todos
  ui->botaoCadastrar->setDisabled(true);
  ui->botaoEditar->setDisabled(true);
  ui->botaoExcluir->setDisabled(true);
  ui->botaoNovo->setDisabled(true);
  ui->botaoBuscar->setDisabled(true);

  ui->lineCor->setDisabled(true);
  ui->linePlaca->setDisabled(true);

  ui->boxMarca->setDisabled(true);
  ui->boxModelo->setDisabled(true);

  ui->boxCategoria->setDisabled(true);

  ui->lineCor->setReadOnly(false);
  ui->linePlaca->setReadOnly(false);
}

void MenuCarro::clearAll()
{
  // limpa todos
  ui->lineCor->clear();
  ui->linePlaca->clear();
  ui->boxCategoria->clear();
  ui->boxMarca->clear();
  ui->boxModelo->clear();

  // reseta o modo de apenas leitura
  ui->lineCor->setReadOnly(false);
  ui->linePlaca->setReadOnly(false);
}

void MenuCarro::setMarcas()
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

void MenuCarro::setCategorias()
{
  bia::CategoriaDoCarroDAO categoriaDao;
  std::map < bia::Id, bia::CategoriaDoCarro >* categorias = categoriaDao.listar();
  std::map < bia::Id, bia::CategoriaDoCarro >::iterator itCateg;

  ui->boxCategoria->setEnabled(true);
  ui->boxCategoria->clear();

  for (itCateg = categorias->begin(); itCateg != categorias->end(); ++itCateg)
    ui->boxCategoria->addItem(itCateg->second.getCategoria());

  delete categorias;
}

void MenuCarro::on_boxMarca_activated(const QString &arg1)
{
  std::map < bia::Id, bia::Marca >* marcas = 0;
  std::map < bia::Id, bia::Marca >::iterator itMarca;
  std::map < bia::Id, bia::Modelo >* modelos = 0;
  std::map < bia::Id, bia::Modelo >::iterator itModelo;

  try
  {
    bia::MarcaDAO marcaDao;
    bia::ModeloDAO modeloDao;

    // procura pelo id da marca selecionada
    marcas = marcaDao.listar();
    for (itMarca = marcas->begin(); itMarca != marcas->end() && itMarca->second.getMarca() != arg1; ++itMarca);
    if (itMarca == marcas->end())
      throw QString("Erro de lógica: id da marca nao encontrado");

    bia::Marca marca = itMarca->second;
    delete marcas;
    marcas = 0;

    // lista pela marca encontrada
    modelos = modeloDao.listarMarca(marca.getId());

    // remove modelos antigos
    ui->boxModelo->clear();

    // checa se existem modelos para a marca selecionada
    if (modelos->empty())
      throw QString("Nenhum modelo para esta marca: insira-os primeiro");

    // insere os modelos na tela
    for (itModelo = modelos->begin(); itModelo != modelos->end(); ++itModelo)
      ui->boxModelo->addItem(itModelo->second.getModelo());

    delete modelos;
    modelos = 0;
  }
  catch (QString& erro)
  {
    delete marcas;
    delete modelos;
    QMessageBox::warning(this, "Erro", erro);
    return;
  }
}

void MenuCarro::on_pushButton_clicked()
{

    try{
        end = QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Images(*.png *.jpeg *.bmp *.gif *.jpg)"));
        ui->label_7->setPixmap(QPixmap(end.toStdString().c_str()));
        ui->label_7->setScaledContents(true);
        flag = 1;

    }catch(...)
    {

    }
}

void MenuCarro::on_label_7_linkActivated(const QString &link)
{


}

void MenuCarro::on_botaoAddMarca_clicked()
{
    MenuMarca tela(this);
    tela.exec();
}

void MenuCarro::on_botaoAddModelo_clicked()
{
    MenuModelo tela(this);
    tela.exec();
}

void MenuCarro::on_botaoAddCategoria_clicked()
{
    MenuCategoria tela(this);
    tela.exec();
}
