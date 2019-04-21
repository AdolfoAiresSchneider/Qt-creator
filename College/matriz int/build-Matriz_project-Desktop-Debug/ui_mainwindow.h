/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QPushButton *criarA_botton;
    QPushButton *criarB_botton;
    QComboBox *comboBox_OpoesMatrizes;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableWidget_MatA;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget_MatB;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QPushButton *subtracao;
    QComboBox *multiplicacao;
    QComboBox *transopsta;
    QComboBox *potencia;
    QPushButton *soma;
    QComboBox *Escalar;
    QToolBox *toolBoxResults;
    QWidget *page_6;
    QFormLayout *formLayout_2;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *TSR;
    QLabel *TIR;
    QLabel *PR;
    QLabel *IDR;
    QLabel *OTR;
    QLabel *SIR;
    QTableWidget *tableView_Result;
    QWidget *page_5;
    QVBoxLayout *verticalLayout;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *TSA;
    QLabel *TIA;
    QLabel *PA;
    QLabel *IDA;
    QLabel *OTA;
    QLabel *SIA;
    QWidget *page_9;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_4;
    QFormLayout *formLayout;
    QLabel *TSB;
    QLabel *TIB;
    QLabel *PB;
    QLabel *IDB;
    QLabel *OTB;
    QLabel *SIB;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(550, 680);
        MainWindow->setMinimumSize(QSize(550, 680));
        MainWindow->setMaximumSize(QSize(550, 680));
        MainWindow->setWindowOpacity(1);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        criarA_botton = new QPushButton(frame_2);
        criarA_botton->setObjectName(QStringLiteral("criarA_botton"));

        gridLayout->addWidget(criarA_botton, 0, 0, 1, 1);

        criarB_botton = new QPushButton(frame_2);
        criarB_botton->setObjectName(QStringLiteral("criarB_botton"));

        gridLayout->addWidget(criarB_botton, 0, 1, 1, 1);

        comboBox_OpoesMatrizes = new QComboBox(frame_2);
        comboBox_OpoesMatrizes->setObjectName(QStringLiteral("comboBox_OpoesMatrizes"));
        comboBox_OpoesMatrizes->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(comboBox_OpoesMatrizes, 0, 2, 1, 1);


        verticalLayout_5->addWidget(frame_2);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tableWidget_MatA = new QTableWidget(tab);
        if (tableWidget_MatA->columnCount() < 1)
            tableWidget_MatA->setColumnCount(1);
        if (tableWidget_MatA->rowCount() < 1)
            tableWidget_MatA->setRowCount(1);
        tableWidget_MatA->setObjectName(QStringLiteral("tableWidget_MatA"));
        tableWidget_MatA->setEnabled(true);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 255, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(127, 255, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(63, 255, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(0, 127, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(0, 170, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        tableWidget_MatA->setPalette(palette);
        tableWidget_MatA->setFocusPolicy(Qt::ClickFocus);
        tableWidget_MatA->setContextMenuPolicy(Qt::PreventContextMenu);
        tableWidget_MatA->setLayoutDirection(Qt::LeftToRight);
        tableWidget_MatA->setAutoFillBackground(true);
        tableWidget_MatA->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly|Qt::ImhHiddenText|Qt::ImhPreferNumbers);
        tableWidget_MatA->setFrameShape(QFrame::Panel);
        tableWidget_MatA->setFrameShadow(QFrame::Sunken);
        tableWidget_MatA->setAutoScrollMargin(0);
        tableWidget_MatA->setTabKeyNavigation(true);
        tableWidget_MatA->setProperty("showDropIndicator", QVariant(true));
        tableWidget_MatA->setDragDropMode(QAbstractItemView::InternalMove);
        tableWidget_MatA->setDefaultDropAction(Qt::ActionMask);
        tableWidget_MatA->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget_MatA->setTextElideMode(Qt::ElideMiddle);
        tableWidget_MatA->setShowGrid(true);
        tableWidget_MatA->setGridStyle(Qt::SolidLine);
        tableWidget_MatA->setWordWrap(false);
        tableWidget_MatA->setCornerButtonEnabled(false);
        tableWidget_MatA->setRowCount(1);
        tableWidget_MatA->setColumnCount(1);
        tableWidget_MatA->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_MatA->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_MatA->horizontalHeader()->setStretchLastSection(true);
        tableWidget_MatA->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget_MatA->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget_MatA->verticalHeader()->setStretchLastSection(true);

        verticalLayout_4->addWidget(tableWidget_MatA);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableWidget_MatB = new QTableWidget(tab_2);
        if (tableWidget_MatB->columnCount() < 1)
            tableWidget_MatB->setColumnCount(1);
        if (tableWidget_MatB->rowCount() < 1)
            tableWidget_MatB->setRowCount(1);
        tableWidget_MatB->setObjectName(QStringLiteral("tableWidget_MatB"));
        tableWidget_MatB->setEnabled(true);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush8(QColor(255, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush8);
        QBrush brush9(QColor(255, 127, 127, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush9);
        QBrush brush10(QColor(255, 63, 63, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        QBrush brush11(QColor(127, 0, 0, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush11);
        QBrush brush12(QColor(170, 0, 0, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        tableWidget_MatB->setPalette(palette1);
        tableWidget_MatB->setAutoFillBackground(true);
        tableWidget_MatB->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly|Qt::ImhPreferNumbers);
        tableWidget_MatB->setTabKeyNavigation(false);
        tableWidget_MatB->setProperty("showDropIndicator", QVariant(false));
        tableWidget_MatB->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget_MatB->setTextElideMode(Qt::ElideNone);
        tableWidget_MatB->setShowGrid(true);
        tableWidget_MatB->setGridStyle(Qt::SolidLine);
        tableWidget_MatB->setWordWrap(false);
        tableWidget_MatB->setCornerButtonEnabled(false);
        tableWidget_MatB->setRowCount(1);
        tableWidget_MatB->setColumnCount(1);
        tableWidget_MatB->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_MatB->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_MatB->horizontalHeader()->setStretchLastSection(true);
        tableWidget_MatB->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget_MatB->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget_MatB->verticalHeader()->setStretchLastSection(true);

        horizontalLayout_2->addWidget(tableWidget_MatB);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_5->addWidget(tabWidget);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        subtracao = new QPushButton(frame);
        subtracao->setObjectName(QStringLiteral("subtracao"));

        gridLayout_2->addWidget(subtracao, 0, 4, 1, 1);

        multiplicacao = new QComboBox(frame);
        multiplicacao->setObjectName(QStringLiteral("multiplicacao"));
        multiplicacao->setEnabled(true);

        gridLayout_2->addWidget(multiplicacao, 0, 1, 1, 1);

        transopsta = new QComboBox(frame);
        transopsta->setObjectName(QStringLiteral("transopsta"));

        gridLayout_2->addWidget(transopsta, 1, 1, 1, 1);

        potencia = new QComboBox(frame);
        potencia->setObjectName(QStringLiteral("potencia"));

        gridLayout_2->addWidget(potencia, 1, 4, 1, 1);

        soma = new QPushButton(frame);
        soma->setObjectName(QStringLiteral("soma"));

        gridLayout_2->addWidget(soma, 0, 3, 1, 1);

        Escalar = new QComboBox(frame);
        Escalar->setObjectName(QStringLiteral("Escalar"));

        gridLayout_2->addWidget(Escalar, 1, 3, 1, 1);


        verticalLayout_5->addWidget(frame);

        toolBoxResults = new QToolBox(centralWidget);
        toolBoxResults->setObjectName(QStringLiteral("toolBoxResults"));
        toolBoxResults->setFrameShape(QFrame::NoFrame);
        toolBoxResults->setFrameShadow(QFrame::Plain);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        page_6->setGeometry(QRect(0, 0, 532, 213));
        formLayout_2 = new QFormLayout(page_6);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        frame_6 = new QFrame(page_6);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_6);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        frame_5 = new QFrame(frame_6);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_5);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        TSR = new QLabel(frame_5);
        TSR->setObjectName(QStringLiteral("TSR"));
        TSR->setEnabled(false);

        verticalLayout_3->addWidget(TSR);

        TIR = new QLabel(frame_5);
        TIR->setObjectName(QStringLiteral("TIR"));
        TIR->setEnabled(false);

        verticalLayout_3->addWidget(TIR);

        PR = new QLabel(frame_5);
        PR->setObjectName(QStringLiteral("PR"));
        PR->setEnabled(false);

        verticalLayout_3->addWidget(PR);

        IDR = new QLabel(frame_5);
        IDR->setObjectName(QStringLiteral("IDR"));
        IDR->setEnabled(false);

        verticalLayout_3->addWidget(IDR);

        OTR = new QLabel(frame_5);
        OTR->setObjectName(QStringLiteral("OTR"));
        OTR->setEnabled(false);

        verticalLayout_3->addWidget(OTR);

        SIR = new QLabel(frame_5);
        SIR->setObjectName(QStringLiteral("SIR"));
        SIR->setEnabled(false);

        verticalLayout_3->addWidget(SIR);


        horizontalLayout_4->addWidget(frame_5);

        tableView_Result = new QTableWidget(frame_6);
        if (tableView_Result->columnCount() < 1)
            tableView_Result->setColumnCount(1);
        if (tableView_Result->rowCount() < 1)
            tableView_Result->setRowCount(1);
        tableView_Result->setObjectName(QStringLiteral("tableView_Result"));
        tableView_Result->setEnabled(true);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush13(QColor(85, 0, 255, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush13);
        QBrush brush14(QColor(170, 127, 255, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush14);
        QBrush brush15(QColor(127, 63, 255, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        QBrush brush16(QColor(42, 0, 127, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush16);
        QBrush brush17(QColor(56, 0, 170, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush13);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush13);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        tableView_Result->setPalette(palette2);
        tableView_Result->setLayoutDirection(Qt::LeftToRight);
        tableView_Result->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView_Result->setRowCount(1);
        tableView_Result->setColumnCount(1);
        tableView_Result->horizontalHeader()->setVisible(true);
        tableView_Result->horizontalHeader()->setCascadingSectionResizes(false);
        tableView_Result->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableView_Result->horizontalHeader()->setStretchLastSection(true);
        tableView_Result->verticalHeader()->setCascadingSectionResizes(true);
        tableView_Result->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableView_Result->verticalHeader()->setStretchLastSection(true);

        horizontalLayout_4->addWidget(tableView_Result);


        formLayout_2->setWidget(0, QFormLayout::FieldRole, frame_6);

        toolBoxResults->addItem(page_6, QString::fromUtf8("Resultado da opera\303\247\303\243o"));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        page_5->setGeometry(QRect(0, 0, 532, 176));
        verticalLayout = new QVBoxLayout(page_5);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_3 = new QFrame(page_5);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        TSA = new QLabel(frame_3);
        TSA->setObjectName(QStringLiteral("TSA"));
        TSA->setEnabled(false);

        verticalLayout_2->addWidget(TSA);

        TIA = new QLabel(frame_3);
        TIA->setObjectName(QStringLiteral("TIA"));
        TIA->setEnabled(false);

        verticalLayout_2->addWidget(TIA);

        PA = new QLabel(frame_3);
        PA->setObjectName(QStringLiteral("PA"));
        PA->setEnabled(false);

        verticalLayout_2->addWidget(PA);

        IDA = new QLabel(frame_3);
        IDA->setObjectName(QStringLiteral("IDA"));
        IDA->setEnabled(false);

        verticalLayout_2->addWidget(IDA);

        OTA = new QLabel(frame_3);
        OTA->setObjectName(QStringLiteral("OTA"));
        OTA->setEnabled(false);

        verticalLayout_2->addWidget(OTA);

        SIA = new QLabel(frame_3);
        SIA->setObjectName(QStringLiteral("SIA"));
        SIA->setEnabled(false);

        verticalLayout_2->addWidget(SIA);


        verticalLayout->addWidget(frame_3);

        toolBoxResults->addItem(page_5, QString::fromUtf8("Informa\303\247\303\265es Matriz A"));
        page_9 = new QWidget();
        page_9->setObjectName(QStringLiteral("page_9"));
        page_9->setGeometry(QRect(0, 0, 532, 176));
        horizontalLayout_5 = new QHBoxLayout(page_9);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        frame_4 = new QFrame(page_9);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame_4);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        TSB = new QLabel(frame_4);
        TSB->setObjectName(QStringLiteral("TSB"));
        TSB->setEnabled(false);

        formLayout->setWidget(0, QFormLayout::LabelRole, TSB);

        TIB = new QLabel(frame_4);
        TIB->setObjectName(QStringLiteral("TIB"));
        TIB->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::LabelRole, TIB);

        PB = new QLabel(frame_4);
        PB->setObjectName(QStringLiteral("PB"));
        PB->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::LabelRole, PB);

        IDB = new QLabel(frame_4);
        IDB->setObjectName(QStringLiteral("IDB"));
        IDB->setEnabled(false);

        formLayout->setWidget(3, QFormLayout::LabelRole, IDB);

        OTB = new QLabel(frame_4);
        OTB->setObjectName(QStringLiteral("OTB"));
        OTB->setEnabled(false);

        formLayout->setWidget(4, QFormLayout::LabelRole, OTB);

        SIB = new QLabel(frame_4);
        SIB->setObjectName(QStringLiteral("SIB"));
        SIB->setEnabled(false);

        formLayout->setWidget(5, QFormLayout::LabelRole, SIB);

        TIB->raise();
        OTB->raise();
        SIB->raise();
        PB->raise();
        IDB->raise();
        TSB->raise();

        horizontalLayout_5->addWidget(frame_4);

        toolBoxResults->addItem(page_9, QString::fromUtf8("Informa\303\247\303\265es Matriz B"));

        verticalLayout_5->addWidget(toolBoxResults);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        toolBoxResults->setCurrentIndex(0);
        toolBoxResults->layout()->setSpacing(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Matrizes", 0));
        criarA_botton->setText(QApplication::translate("MainWindow", "Criar Matriz A", 0));
        criarB_botton->setText(QApplication::translate("MainWindow", "Criar Matriz B", 0));
        comboBox_OpoesMatrizes->clear();
        comboBox_OpoesMatrizes->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "            Op\303\247\303\265es", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "MatrizA", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "MatrizB", 0));
        subtracao->setText(QApplication::translate("MainWindow", "A-B", 0));
        multiplicacao->clear();
        multiplicacao->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "                  *", 0)
         << QApplication::translate("MainWindow", "- A*B", 0)
         << QApplication::translate("MainWindow", "- B*A", 0)
        );
        transopsta->clear();
        transopsta->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "          Transposta", 0)
         << QApplication::translate("MainWindow", "--> A Transposta", 0)
         << QApplication::translate("MainWindow", "--> B Transposta", 0)
        );
        potencia->clear();
        potencia->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "           Pot\303\252ncia", 0)
         << QApplication::translate("MainWindow", "--> A^K", 0)
         << QApplication::translate("MainWindow", "--> B^K", 0)
        );
        soma->setText(QApplication::translate("MainWindow", "A+B", 0));
        Escalar->clear();
        Escalar->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "             Escalar", 0)
         << QApplication::translate("MainWindow", "--> A*K", 0)
         << QApplication::translate("MainWindow", "--> B*K", 0)
        );
        TSR->setText(QApplication::translate("MainWindow", "--> Triangular superior", 0));
        TIR->setText(QApplication::translate("MainWindow", "--> Triangular inferior", 0));
        PR->setText(QApplication::translate("MainWindow", "--> Permuta\303\247\303\243o", 0));
        IDR->setText(QApplication::translate("MainWindow", "--> Identidade", 0));
        OTR->setText(QApplication::translate("MainWindow", "--> Ortogonal", 0));
        SIR->setText(QApplication::translate("MainWindow", "--> Simetrica", 0));
        toolBoxResults->setItemText(toolBoxResults->indexOf(page_6), QApplication::translate("MainWindow", "Resultado da opera\303\247\303\243o", 0));
        TSA->setText(QApplication::translate("MainWindow", "--> Triangular superior", 0));
        TIA->setText(QApplication::translate("MainWindow", "--> Triangular inferior", 0));
        PA->setText(QApplication::translate("MainWindow", "--> Permuta\303\247\303\243o", 0));
        IDA->setText(QApplication::translate("MainWindow", "--> Identidade", 0));
        OTA->setText(QApplication::translate("MainWindow", "--> Ortogonal", 0));
        SIA->setText(QApplication::translate("MainWindow", "--> Simetrica", 0));
        toolBoxResults->setItemText(toolBoxResults->indexOf(page_5), QApplication::translate("MainWindow", "Informa\303\247\303\265es Matriz A", 0));
        TSB->setText(QApplication::translate("MainWindow", "--> Triangular superior", 0));
        TIB->setText(QApplication::translate("MainWindow", "--> Triangular inferior", 0));
        PB->setText(QApplication::translate("MainWindow", "--> Permuta\303\247\303\243o", 0));
        IDB->setText(QApplication::translate("MainWindow", "--> Identidade", 0));
        OTB->setText(QApplication::translate("MainWindow", "--> Ortogonal", 0));
        SIB->setText(QApplication::translate("MainWindow", "--> Simetrica", 0));
        toolBoxResults->setItemText(toolBoxResults->indexOf(page_9), QApplication::translate("MainWindow", "Informa\303\247\303\265es Matriz B", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
