#ifndef TELALAUDO_H
#define TELALAUDO_H
#include <QString>
#include <QDialog>

namespace Ui {
class TelaLaudo;
}

class TelaLaudo : public QDialog
{
    Q_OBJECT

public:
    explicit TelaLaudo(QWidget *parent = 0);
    void setLaudo(QString * l){this->laudo = l;}
    ~TelaLaudo();
    void setTela();

private:
    Ui::TelaLaudo *ui;
    QString * laudo;
};

#endif // TELALAUDO_H
