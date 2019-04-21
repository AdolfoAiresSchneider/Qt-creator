#include "TelaPrincipal.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
  try
  {
    QApplication a(argc, argv);
    TelaPrincipal w;
    w.show();

    return a.exec();
  }
  catch (...)
  {
    QMessageBox::critical(0, "Erro fatal!", "Ocorreu um erro não esperado!\nEncerrando.");
  }
}
