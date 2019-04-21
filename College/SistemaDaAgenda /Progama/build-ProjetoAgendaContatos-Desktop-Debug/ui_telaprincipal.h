/********************************************************************************
** Form generated from reading UI file 'telaprincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELAPRINCIPAL_H
#define UI_TELAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelaPrincipal
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonTeste;
    QTextEdit *textEditSaida;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TelaPrincipal)
    {
        if (TelaPrincipal->objectName().isEmpty())
            TelaPrincipal->setObjectName(QStringLiteral("TelaPrincipal"));
        TelaPrincipal->resize(708, 511);
        centralWidget = new QWidget(TelaPrincipal);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonTeste = new QPushButton(centralWidget);
        pushButtonTeste->setObjectName(QStringLiteral("pushButtonTeste"));
        pushButtonTeste->setGeometry(QRect(140, 20, 113, 32));
        textEditSaida = new QTextEdit(centralWidget);
        textEditSaida->setObjectName(QStringLiteral("textEditSaida"));
        textEditSaida->setGeometry(QRect(10, 100, 551, 341));
        TelaPrincipal->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TelaPrincipal);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 708, 22));
        TelaPrincipal->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TelaPrincipal);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TelaPrincipal->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TelaPrincipal);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TelaPrincipal->setStatusBar(statusBar);

        retranslateUi(TelaPrincipal);

        QMetaObject::connectSlotsByName(TelaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *TelaPrincipal)
    {
        TelaPrincipal->setWindowTitle(QApplication::translate("TelaPrincipal", "TelaPrincipal", 0));
        pushButtonTeste->setText(QApplication::translate("TelaPrincipal", "TESTE", 0));
    } // retranslateUi

};

namespace Ui {
    class TelaPrincipal: public Ui_TelaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELAPRINCIPAL_H
