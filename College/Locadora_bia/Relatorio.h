#ifndef RELATORIO_H
#define RELATORIO_H

#include <fstream>

#include <QDate>
#include <QDateTime>
#include <QString>


namespace bia
{
  class Relatorio
  {
  public:

    static void append (const QString& info);

  };  /// \class Relatorio

} /// \namespace bia

#endif // RELATORIO_H
