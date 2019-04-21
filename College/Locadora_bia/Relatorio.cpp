#include "Relatorio.h"

namespace bia
{
  void Relatorio::append(const QString &info)
  {
    std::ofstream arquivo("data/relatorio.dat", std::ios_base::app);
    if (!arquivo.is_open())
      throw QString("Relatório: Não foi possível abrir o arquivo");

    arquivo << QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss").toStdString()
            << " " << info.toStdString() << "\n";
    arquivo.close();
  }

} /// \namespace bia
