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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QPushButton *amenos;
    QPushButton *adiv;
    QPushButton *avezes;
    QLineEdit *N1R;
    QLineEdit *N2R;
    QLineEdit *N1I;
    QLineEdit *N2I;
    QLineEdit *Resposta;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Calculadora)
    {
        if (Calculadora->objectName().isEmpty())
            Calculadora->setObjectName(QStringLiteral("Calculadora"));
        Calculadora->resize(320, 357);
        Calculadora->setMinimumSize(QSize(200, 300));
        Calculadora->setMaximumSize(QSize(320, 400));
        centralWidget = new QWidget(Calculadora);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        a1 = new QPushButton(centralWidget);
        a1->setObjectName(QStringLiteral("a1"));
        a1->setGeometry(QRect(10, 150, 51, 51));
        a2 = new QPushButton(centralWidget);
        a2->setObjectName(QStringLiteral("a2"));
        a2->setGeometry(QRect(70, 150, 51, 51));
        a3 = new QPushButton(centralWidget);
        a3->setObjectName(QStringLiteral("a3"));
        a3->setGeometry(QRect(130, 150, 51, 51));
        a4 = new QPushButton(centralWidget);
        a4->setObjectName(QStringLiteral("a4"));
        a4->setGeometry(QRect(10, 210, 51, 51));
        a5 = new QPushButton(centralWidget);
        a5->setObjectName(QStringLiteral("a5"));
        a5->setGeometry(QRect(70, 210, 51, 51));
        a6 = new QPushButton(centralWidget);
        a6->setObjectName(QStringLiteral("a6"));
        a6->setGeometry(QRect(130, 210, 51, 51));
        a7 = new QPushButton(centralWidget);
        a7->setObjectName(QStringLiteral("a7"));
        a7->setGeometry(QRect(10, 270, 51, 51));
        a9 = new QPushButton(centralWidget);
        a9->setObjectName(QStringLiteral("a9"));
        a9->setGeometry(QRect(130, 270, 51, 51));
        a8 = new QPushButton(centralWidget);
        a8->setObjectName(QStringLiteral("a8"));
        a8->setGeometry(QRect(70, 270, 51, 51));
        a0 = new QPushButton(centralWidget);
        a0->setObjectName(QStringLiteral("a0"));
        a0->setGeometry(QRect(190, 210, 51, 111));
        amais = new QPushButton(centralWidget);
        amais->setObjectName(QStringLiteral("amais"));
        amais->setGeometry(QRect(190, 150, 51, 51));
        amenos = new QPushButton(centralWidget);
        amenos->setObjectName(QStringLiteral("amenos"));
        amenos->setGeometry(QRect(250, 150, 51, 51));
        adiv = new QPushButton(centralWidget);
        adiv->setObjectName(QStringLiteral("adiv"));
        adiv->setGeometry(QRect(250, 210, 51, 51));
        avezes = new QPushButton(centralWidget);
        avezes->setObjectName(QStringLiteral("avezes"));
        avezes->setGeometry(QRect(250, 270, 51, 51));
        N1R = new QLineEdit(centralWidget);
        N1R->setObjectName(QStringLiteral("N1R"));
        N1R->setGeometry(QRect(30, 20, 111, 25));
        N2R = new QLineEdit(centralWidget);
        N2R->setObjectName(QStringLiteral("N2R"));
        N2R->setGeometry(QRect(30, 50, 111, 31));
        N1I = new QLineEdit(centralWidget);
        N1I->setObjectName(QStringLiteral("N1I"));
        N1I->setGeometry(QRect(160, 20, 131, 25));
        N2I = new QLineEdit(centralWidget);
        N2I->setObjectName(QStringLiteral("N2I"));
        N2I->setGeometry(QRect(160, 50, 131, 25));
        Resposta = new QLineEdit(centralWidget);
        Resposta->setObjectName(QStringLiteral("Resposta"));
        Resposta->setGeometry(QRect(0, 90, 311, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 24, 20, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 54, 20, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 20, 21, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(140, 50, 21, 31));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(300, 20, 31, 31));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(300, 50, 31, 31));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(160, 50, 131, 31));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
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
        amenos->setText(QApplication::translate("Calculadora", "-", 0));
        adiv->setText(QApplication::translate("Calculadora", "/", 0));
        avezes->setText(QApplication::translate("Calculadora", "*", 0));
        label->setText(QApplication::translate("Calculadora", "N1", 0));
        label_2->setText(QApplication::translate("Calculadora", "N2", 0));
        label_3->setText(QApplication::translate("Calculadora", " R", 0));
        label_4->setText(QApplication::translate("Calculadora", " R", 0));
        label_5->setText(QApplication::translate("Calculadora", " i", 0));
        label_6->setText(QApplication::translate("Calculadora", " i", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Calculadora: public Ui_Calculadora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULADORA_H
