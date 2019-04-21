/********************************************************************************
** Form generated from reading UI file 'calculadora.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULADORA_H
#define UI_CALCULADORA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculadora
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonAdicionar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Calculadora)
    {
        if (Calculadora->objectName().isEmpty())
            Calculadora->setObjectName(QStringLiteral("Calculadora"));
        Calculadora->resize(400, 300);
        centralWidget = new QWidget(Calculadora);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonAdicionar = new QPushButton(centralWidget);
        pushButtonAdicionar->setObjectName(QStringLiteral("pushButtonAdicionar"));
        pushButtonAdicionar->setGeometry(QRect(130, 100, 113, 32));
        Calculadora->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Calculadora);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        Calculadora->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Calculadora);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Calculadora->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Calculadora);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Calculadora->setStatusBar(statusBar);

        retranslateUi(Calculadora);

        QMetaObject::connectSlotsByName(Calculadora);
    } // setupUi

    void retranslateUi(QMainWindow *Calculadora)
    {
        Calculadora->setWindowTitle(QApplication::translate("Calculadora", "Calculadora", 0));
        pushButtonAdicionar->setText(QApplication::translate("Calculadora", "+", 0));
    } // retranslateUi

};

namespace Ui {
    class Calculadora: public Ui_Calculadora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULADORA_H
