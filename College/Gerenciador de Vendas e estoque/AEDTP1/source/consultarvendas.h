#ifndef CONSULTARVENDAS_H
#define CONSULTARVENDAS_H
#include "ui_mainwindow.h"
#include "vindice.h"
#include <QListWidgetItem>
#include "aux.h"

#include <QDialog>

namespace Ui {
class consultarVendas;
}

class consultarVendas : public QDialog
{
    Q_OBJECT

public:
    explicit consultarVendas(QWidget *parent = 0);
    ~consultarVendas();

private slots:
    void on_pushButton_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_setcod_selectionChanged();

    void on_setcod_customContextMenuRequested(const QPoint &pos);

    void on_setcod_cursorPositionChanged(int arg1, int arg2);

    void on_setcod_textEdited(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::consultarVendas *ui;
    CVenda venda;

};

#endif // CONSULTARVENDAS_H
