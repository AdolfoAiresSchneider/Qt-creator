/********************************************************************************
** Form generated from reading UI file 'calculadora.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULADORA_H
#define UI_CALCULADORA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculadora
{
public:
    QWidget *centralWidget;
    QPushButton *a1;
    QPushButton *a2;
    QPushButton *a3;
    QPushButton *a4;
    QPushButton *a5;
    QPushButton *a6;
    QPushButton *a7;
    QPushButton *a9;
    QPushButton *a8;
    QPushButton *a0;
    QPushButton *amais;
    QPushButton *subtrcao;
    QPushButton *divisao;
    QPushButton *avezes;
    QLineEdit *NC1;
    QLineEdit *NC2;
    QRadioButton *radioButton;
    QRadioButton *N2;
    QListWidget *listWidget;
    QPushButton *a0_2;
    QPushButton *avezes_2;
    QPushButton *igualdade;
    QFrame *line;
    QPushButton *negativo;
    QPushButton *back;
    QPushButton *pushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Calculadora)
    {
        if (Calculadora->objectName().isEmpty())
            Calculadora->setObjectName(QStringLiteral("Calculadora"));
        Calculadora->resize(310, 394);
        Calculadora->setMinimumSize(QSize(200, 300));
        Calculadora->setMaximumSize(QSize(320, 400));
        centralWidget = new QWidget(Calculadora);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        a1 = new QPushButton(centralWidget);
        a1->setObjectName(QStringLiteral("a1"));
        a1->setGeometry(QRect(10, 200, 41, 51));
        a2 = new QPushButton(centralWidget);
        a2->setObjectName(QStringLiteral("a2"));
        a2->setGeometry(QRect(60, 200, 41, 51));
        a3 = new QPushButton(centralWidget);
        a3->setObjectName(QStringLiteral("a3"));
        a3->setGeometry(QRect(110, 200, 41, 51));
        a4 = new QPushButton(centralWidget);
        a4->setObjectName(QStringLiteral("a4"));
        a4->setGeometry(QRect(10, 260, 41, 51));
        a5 = new QPushButton(centralWidget);
        a5->setObjectName(QStringLiteral("a5"));
        a5->setGeometry(QRect(60, 260, 41, 51));
        a6 = new QPushButton(centralWidget);
        a6->setObjectName(QStringLiteral("a6"));
        a6->setGeometry(QRect(110, 260, 41, 51));
        a7 = new QPushButton(centralWidget);
        a7->setObjectName(QStringLiteral("a7"));
        a7->setGeometry(QRect(10, 320, 41, 51));
        a9 = new QPushButton(centralWidget);
        a9->setObjectName(QStringLiteral("a9"));
        a9->setGeometry(QRect(110, 320, 41, 51));
        a8 = new QPushButton(centralWidget);
        a8->setObjectName(QStringLiteral("a8"));
        a8->setGeometry(QRect(60, 320, 41, 51));
        a0 = new QPushButton(centralWidget);
        a0->setObjectName(QStringLiteral("a0"));
        a0->setGeometry(QRect(160, 260, 41, 51));
        amais = new QPushButton(centralWidget);
        amais->setObjectName(QStringLiteral("amais"));
        amais->setGeometry(QRect(160, 200, 41, 21));
        subtrcao = new QPushButton(centralWidget);
        subtrcao->setObjectName(QStringLiteral("subtrcao"));
        subtrcao->setGeometry(QRect(240, 200, 61, 41));
        divisao = new QPushButton(centralWidget);
        divisao->setObjectName(QStringLiteral("divisao"));
        divisao->setGeometry(QRect(240, 160, 61, 41));
        avezes = new QPushButton(centralWidget);
        avezes->setObjectName(QStringLiteral("avezes"));
        avezes->setGeometry(QRect(240, 240, 61, 41));
        NC1 = new QLineEdit(centralWidget);
        NC1->setObjectName(QStringLiteral("NC1"));
        NC1->setGeometry(QRect(10, 124, 191, 31));
        NC1->setReadOnly(true);
        NC2 = new QLineEdit(centralWidget);
        NC2->setObjectName(QStringLiteral("NC2"));
        NC2->setGeometry(QRect(10, 160, 191, 31));
        NC2->setReadOnly(true);
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(210, 130, 16, 20));
        N2 = new QRadioButton(centralWidget);
        N2->setObjectName(QStringLiteral("N2"));
        N2->setGeometry(QRect(210, 160, 16, 20));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 291, 101));
        a0_2 = new QPushButton(centralWidget);
        a0_2->setObjectName(QStringLiteral("a0_2"));
        a0_2->setGeometry(QRect(160, 320, 41, 51));
        avezes_2 = new QPushButton(centralWidget);
        avezes_2->setObjectName(QStringLiteral("avezes_2"));
        avezes_2->setGeometry(QRect(240, 280, 61, 41));
        igualdade = new QPushButton(centralWidget);
        igualdade->setObjectName(QStringLiteral("igualdade"));
        igualdade->setGeometry(QRect(240, 330, 61, 41));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(210, 200, 16, 171));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        negativo = new QPushButton(centralWidget);
        negativo->setObjectName(QStringLiteral("negativo"));
        negativo->setGeometry(QRect(160, 230, 41, 21));
        back = new QPushButton(centralWidget);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(240, 120, 61, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 10, 81, 22));
        Calculadora->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Calculadora);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Calculadora->setStatusBar(statusBar);

        retranslateUi(Calculadora);

        QMetaObject::connectSlotsByName(Calculadora);
    } // setupUi

    void retranslateUi(QMainWindow *Calculadora)
    {
        Calculadora->setWindowTitle(QApplication::translate("Calculadora", "Calculadora", 0));
        a1->setText(QApplication::translate("Calculadora", "1", 0));
        a2->setText(QApplication::translate("Calculadora", "2", 0));
        a3->setText(QApplication::translate("Calculadora", "3", 0));
        a4->setText(QApplication::translate("Calculadora", "4", 0));
        a5->setText(QApplication::translate("Calculadora", "5", 0));
        a6->setText(QApplication::translate("Calculadora", "6", 0));
        a7->setText(QApplication::translate("Calculadora", "7", 0));
        a9->setText(QApplication::translate("Calculadora", "9", 0));
        a8->setText(QApplication::translate("Calculadora", "8", 0));
        a0->setText(QApplication::translate("Calculadora", "0", 0));
        amais->setText(QApplication::translate("Calculadora", "+", 0));
        subtrcao->setText(QApplication::translate("Calculadora", "-", 0));
        divisao->setText(QApplication::translate("Calculadora", "/", 0));
        avezes->setText(QApplication::translate("Calculadora", "*", 0));
        radioButton->setText(QString());
        N2->setText(QString());
        a0_2->setText(QApplication::translate("Calculadora", "i", 0));
        avezes_2->setText(QApplication::translate("Calculadora", "+", 0));
        igualdade->setText(QApplication::translate("Calculadora", "==", 0));
        negativo->setText(QApplication::translate("Calculadora", "-", 0));
        back->setText(QApplication::translate("Calculadora", "<----", 0));
        pushButton->setText(QApplication::translate("Calculadora", "Clear history", 0));
    } // retranslateUi

};

namespace Ui {
    class Calculadora: public Ui_Calculadora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULADORA_H
