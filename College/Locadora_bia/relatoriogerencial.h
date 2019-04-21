#ifndef RELATORIOGERENCIAL_H
#define RELATORIOGERENCIAL_H

#include <QDialog>

namespace Ui {
class RelatorioGerencial;
}

class RelatorioGerencial : public QDialog
{
    Q_OBJECT

public:
    explicit RelatorioGerencial(QWidget *parent = 0);
    ~RelatorioGerencial();

private:
    Ui::RelatorioGerencial *ui;
};

#endif // RELATORIOGERENCIAL_H
