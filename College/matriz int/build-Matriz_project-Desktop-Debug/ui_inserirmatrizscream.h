/********************************************************************************
** Form generated from reading UI file 'inserirmatrizscream.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERIRMATRIZSCREAM_H
#define UI_INSERIRMATRIZSCREAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_inserirMatrizScream
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *inserirMatrizScream)
    {
        if (inserirMatrizScream->objectName().isEmpty())
            inserirMatrizScream->setObjectName(QStringLiteral("inserirMatrizScream"));
        inserirMatrizScream->resize(624, 496);
        tableWidget = new QTableWidget(inserirMatrizScream);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(10, 10, 601, 411));
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableWidget->setTextElideMode(Qt::ElideMiddle);
        pushButton = new QPushButton(inserirMatrizScream);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 430, 601, 51));

        retranslateUi(inserirMatrizScream);

        QMetaObject::connectSlotsByName(inserirMatrizScream);
    } // setupUi

    void retranslateUi(QDialog *inserirMatrizScream)
    {
        inserirMatrizScream->setWindowTitle(QApplication::translate("inserirMatrizScream", "Dialog", 0));
        pushButton->setText(QApplication::translate("inserirMatrizScream", "Gravar Matriz", 0));
    } // retranslateUi

};

namespace Ui {
    class inserirMatrizScream: public Ui_inserirMatrizScream {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERIRMATRIZSCREAM_H
