/********************************************************************************
** Form generated from reading UI file 'filter.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTER_H
#define UI_FILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterClass
{
public:
    QAction *actionPicOpen;
    QAction *actionPicSave;
    QAction *actionClose;
    QAction *actionBack;
    QAction *actionInvert;
    QAction *actionGrey;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuDatei;
    QMenu *menuBearbeiten;
    QMenu *menuFilter;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FilterClass)
    {
        if (FilterClass->objectName().isEmpty())
            FilterClass->setObjectName(QStringLiteral("FilterClass"));
        FilterClass->resize(583, 451);
        actionPicOpen = new QAction(FilterClass);
        actionPicOpen->setObjectName(QStringLiteral("actionPicOpen"));
        actionPicSave = new QAction(FilterClass);
        actionPicSave->setObjectName(QStringLiteral("actionPicSave"));
        actionClose = new QAction(FilterClass);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionBack = new QAction(FilterClass);
        actionBack->setObjectName(QStringLiteral("actionBack"));
        actionInvert = new QAction(FilterClass);
        actionInvert->setObjectName(QStringLiteral("actionInvert"));
        actionGrey = new QAction(FilterClass);
        actionGrey->setObjectName(QStringLiteral("actionGrey"));
        centralWidget = new QWidget(FilterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../bilder/cool.png")));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        FilterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FilterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 583, 21));
        menuDatei = new QMenu(menuBar);
        menuDatei->setObjectName(QStringLiteral("menuDatei"));
        menuBearbeiten = new QMenu(menuBar);
        menuBearbeiten->setObjectName(QStringLiteral("menuBearbeiten"));
        menuFilter = new QMenu(menuBar);
        menuFilter->setObjectName(QStringLiteral("menuFilter"));
        FilterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FilterClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FilterClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FilterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FilterClass->setStatusBar(statusBar);

        menuBar->addAction(menuDatei->menuAction());
        menuBar->addAction(menuBearbeiten->menuAction());
        menuBar->addAction(menuFilter->menuAction());
        menuDatei->addAction(actionPicOpen);
        menuDatei->addAction(actionPicSave);
        menuDatei->addSeparator();
        menuDatei->addAction(actionClose);
        menuBearbeiten->addAction(actionBack);
        menuFilter->addAction(actionInvert);
        menuFilter->addAction(actionGrey);

        retranslateUi(FilterClass);
        QObject::connect(actionClose, SIGNAL(triggered()), FilterClass, SLOT(close()));

        QMetaObject::connectSlotsByName(FilterClass);
    } // setupUi

    void retranslateUi(QMainWindow *FilterClass)
    {
        FilterClass->setWindowTitle(QApplication::translate("FilterClass", "Filter", 0));
        actionPicOpen->setText(QApplication::translate("FilterClass", "Bild \303\266ffnen", 0));
        actionPicSave->setText(QApplication::translate("FilterClass", "Bild speichern", 0));
        actionClose->setText(QApplication::translate("FilterClass", "Beenden", 0));
        actionBack->setText(QApplication::translate("FilterClass", "R\303\274ckg\303\244ngig", 0));
        actionInvert->setText(QApplication::translate("FilterClass", "Invertieren", 0));
        actionGrey->setText(QApplication::translate("FilterClass", "Grauwertfilter", 0));
        label->setText(QString());
        menuDatei->setTitle(QApplication::translate("FilterClass", "Datei", 0));
        menuBearbeiten->setTitle(QApplication::translate("FilterClass", "Bearbeiten", 0));
        menuFilter->setTitle(QApplication::translate("FilterClass", "Filter", 0));
    } // retranslateUi

};

namespace Ui {
    class FilterClass: public Ui_FilterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTER_H
