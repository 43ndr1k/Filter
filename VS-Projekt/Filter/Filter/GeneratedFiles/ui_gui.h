/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QAction *actionPicLoad;
    QAction *actionPicSave;
    QAction *actionClose;
    QAction *actionBack;
    QAction *actionInvertieren;
    QAction *actionGrauwerte;
    QAction *actionBunt;
    QAction *actionG_e;
    QAction *actionAbweichung;
    QAction *actionSchwarz_Wei;
    QAction *actionRot_Gr_n_Blau;
    QAction *actionBlackWhite;
    QAction *actionThreshold;
    QAction *actionMeanValue;
    QAction *actionGauss;
    QAction *actionHSobel;
    QAction *actionVSobel;
    QAction *actionQSobel;
    QAction *actionthresholdSobel;
    QAction *actionKSobel;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *picture;
    QMenuBar *menuBar;
    QMenu *menuDatei;
    QMenu *menuBearbeiten;
    QMenu *menuFilter;
    QMenu *menuSobel;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QStringLiteral("GUIClass"));
        GUIClass->resize(640, 400);
        actionPicLoad = new QAction(GUIClass);
        actionPicLoad->setObjectName(QStringLiteral("actionPicLoad"));
        actionPicSave = new QAction(GUIClass);
        actionPicSave->setObjectName(QStringLiteral("actionPicSave"));
        actionClose = new QAction(GUIClass);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionBack = new QAction(GUIClass);
        actionBack->setObjectName(QStringLiteral("actionBack"));
        actionBack->setText(QString::fromUtf8("R\303\274ckg\303\244ngig"));
        actionBack->setIconText(QString::fromUtf8("R\303\274ckg\303\244ngig"));
        actionInvertieren = new QAction(GUIClass);
        actionInvertieren->setObjectName(QStringLiteral("actionInvertieren"));
        actionGrauwerte = new QAction(GUIClass);
        actionGrauwerte->setObjectName(QStringLiteral("actionGrauwerte"));
        actionBunt = new QAction(GUIClass);
        actionBunt->setObjectName(QStringLiteral("actionBunt"));
        actionG_e = new QAction(GUIClass);
        actionG_e->setObjectName(QStringLiteral("actionG_e"));
        actionAbweichung = new QAction(GUIClass);
        actionAbweichung->setObjectName(QStringLiteral("actionAbweichung"));
        actionSchwarz_Wei = new QAction(GUIClass);
        actionSchwarz_Wei->setObjectName(QStringLiteral("actionSchwarz_Wei"));
        actionRot_Gr_n_Blau = new QAction(GUIClass);
        actionRot_Gr_n_Blau->setObjectName(QStringLiteral("actionRot_Gr_n_Blau"));
        actionBlackWhite = new QAction(GUIClass);
        actionBlackWhite->setObjectName(QStringLiteral("actionBlackWhite"));
        actionThreshold = new QAction(GUIClass);
        actionThreshold->setObjectName(QStringLiteral("actionThreshold"));
        actionMeanValue = new QAction(GUIClass);
        actionMeanValue->setObjectName(QStringLiteral("actionMeanValue"));
        actionGauss = new QAction(GUIClass);
        actionGauss->setObjectName(QStringLiteral("actionGauss"));
        actionHSobel = new QAction(GUIClass);
        actionHSobel->setObjectName(QStringLiteral("actionHSobel"));
        actionVSobel = new QAction(GUIClass);
        actionVSobel->setObjectName(QStringLiteral("actionVSobel"));
        actionQSobel = new QAction(GUIClass);
        actionQSobel->setObjectName(QStringLiteral("actionQSobel"));
        actionthresholdSobel = new QAction(GUIClass);
        actionthresholdSobel->setObjectName(QStringLiteral("actionthresholdSobel"));
        actionKSobel = new QAction(GUIClass);
        actionKSobel->setObjectName(QStringLiteral("actionKSobel"));
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        picture = new QLabel(centralWidget);
        picture->setObjectName(QStringLiteral("picture"));
        picture->setScaledContents(true);

        gridLayout->addWidget(picture, 0, 0, 1, 1);

        GUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 21));
        menuDatei = new QMenu(menuBar);
        menuDatei->setObjectName(QStringLiteral("menuDatei"));
        menuBearbeiten = new QMenu(menuBar);
        menuBearbeiten->setObjectName(QStringLiteral("menuBearbeiten"));
        menuFilter = new QMenu(menuBar);
        menuFilter->setObjectName(QStringLiteral("menuFilter"));
        menuSobel = new QMenu(menuFilter);
        menuSobel->setObjectName(QStringLiteral("menuSobel"));
        GUIClass->setMenuBar(menuBar);

        menuBar->addAction(menuDatei->menuAction());
        menuBar->addAction(menuBearbeiten->menuAction());
        menuBar->addAction(menuFilter->menuAction());
        menuDatei->addAction(actionPicLoad);
        menuDatei->addAction(actionPicSave);
        menuDatei->addSeparator();
        menuDatei->addAction(actionClose);
        menuBearbeiten->addAction(actionBack);
        menuFilter->addAction(actionBlackWhite);
        menuFilter->addAction(actionInvertieren);
        menuFilter->addSeparator();
        menuFilter->addAction(actionThreshold);
        menuFilter->addAction(actionMeanValue);
        menuFilter->addAction(actionGauss);
        menuFilter->addSeparator();
        menuFilter->addAction(menuSobel->menuAction());
        menuSobel->addAction(actionKSobel);
        menuSobel->addSeparator();
        menuSobel->addAction(actionHSobel);
        menuSobel->addAction(actionVSobel);
        menuSobel->addAction(actionQSobel);
        menuSobel->addSeparator();
        menuSobel->addAction(actionthresholdSobel);

        retranslateUi(GUIClass);
        QObject::connect(actionClose, SIGNAL(triggered()), GUIClass, SLOT(close()));
        QObject::connect(actionPicLoad, SIGNAL(triggered()), GUIClass, SLOT(loadPic()));
        QObject::connect(actionPicSave, SIGNAL(triggered()), GUIClass, SLOT(savePic()));
        QObject::connect(actionBack, SIGNAL(triggered()), GUIClass, SLOT(back()));
        QObject::connect(actionBlackWhite, SIGNAL(triggered()), GUIClass, SLOT(makeGray()));
        QObject::connect(actionThreshold, SIGNAL(triggered()), GUIClass, SLOT(threshold()));
        QObject::connect(actionMeanValue, SIGNAL(triggered()), GUIClass, SLOT(meanValue()));
        QObject::connect(actionGauss, SIGNAL(triggered()), GUIClass, SLOT(gauss()));
        QObject::connect(actionHSobel, SIGNAL(triggered()), GUIClass, SLOT(hSobel()));
        QObject::connect(actionVSobel, SIGNAL(triggered()), GUIClass, SLOT(vSobel()));
        QObject::connect(actionQSobel, SIGNAL(triggered()), GUIClass, SLOT(qSobel()));
        QObject::connect(actionKSobel, SIGNAL(triggered()), GUIClass, SLOT(kSobel()));
        QObject::connect(actionthresholdSobel, SIGNAL(triggered()), GUIClass, SLOT(thresholdSobel()));

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "GUI", 0));
        actionPicLoad->setText(QApplication::translate("GUIClass", "Bild laden", 0));
        actionPicSave->setText(QApplication::translate("GUIClass", "Bild speichern", 0));
        actionClose->setText(QApplication::translate("GUIClass", "Beenden", 0));
        actionInvertieren->setText(QApplication::translate("GUIClass", "Invertieren", 0));
        actionGrauwerte->setText(QApplication::translate("GUIClass", "Grauwerte", 0));
        actionBunt->setText(QApplication::translate("GUIClass", "Bunt", 0));
        actionG_e->setText(QApplication::translate("GUIClass", "G\303\203\302\266\303\203\305\270e", 0));
        actionAbweichung->setText(QApplication::translate("GUIClass", "Abweichung", 0));
        actionSchwarz_Wei->setText(QApplication::translate("GUIClass", "Schwarz/Wei\303\203\305\270", 0));
        actionRot_Gr_n_Blau->setText(QApplication::translate("GUIClass", "Rot/Gr\303\203\302\274n/Blau", 0));
        actionBlackWhite->setText(QApplication::translate("GUIClass", "Schwarz/Wei\303\237", 0));
        actionThreshold->setText(QApplication::translate("GUIClass", "Schwellenwertfilter", 0));
        actionMeanValue->setText(QApplication::translate("GUIClass", "Mittelwertfilter", 0));
        actionGauss->setText(QApplication::translate("GUIClass", "Gaussfilter", 0));
        actionHSobel->setText(QApplication::translate("GUIClass", "Horizontal", 0));
        actionVSobel->setText(QApplication::translate("GUIClass", "Vertikal", 0));
        actionQSobel->setText(QApplication::translate("GUIClass", "Quer", 0));
        actionthresholdSobel->setText(QApplication::translate("GUIClass", "Angepasster Schwellenwert", 0));
        actionKSobel->setText(QApplication::translate("GUIClass", "Komplett", 0));
        picture->setText(QString());
        menuDatei->setTitle(QApplication::translate("GUIClass", "Datei", 0));
        menuBearbeiten->setTitle(QApplication::translate("GUIClass", "Bearbeiten", 0));
        menuFilter->setTitle(QApplication::translate("GUIClass", "Filter", 0));
        menuSobel->setTitle(QApplication::translate("GUIClass", "Sobel", 0));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
