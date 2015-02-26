/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labelSettings;
    QFrame *lineh1;
    QGridLayout *gridLayout;
    QLabel *labelVoltageUp;
    QDoubleSpinBox *doubleSpinBoxVoltageUp;
    QLabel *labelLoad;
    QToolButton *toolButtonLoad;
    QDoubleSpinBox *doubleSpinBoxTolerance;
    QDoubleSpinBox *doubleSpinBoxVoltageLow;
    QLabel *labelAccuracy;
    QLabel *labelVoltageLow;
    QLabel *labelVoltageGround;
    QDoubleSpinBox *doubleSpinBoxVoltageGround;
    QLabel *labelScale;
    QSpinBox *spinBoxScale;
    QFrame *lineh2;
    QPushButton *pushButtonRun;
    QFrame *lineh3;
    QLabel *labelIteration;
    QLabel *labelTime;
    QSpacerItem *verticalSpacer;
    QFrame *linev1;
    QTabWidget *tabWidget;
    QWidget *tabPotential;
    QGridLayout *gridLayout_2;
    QLabel *plotV;
    QWidget *tabEField;
    QGridLayout *gridLayout_3;
    QLabel *plotE;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(666, 451);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        labelSettings = new QLabel(centralWidget);
        labelSettings->setObjectName(QStringLiteral("labelSettings"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelSettings->sizePolicy().hasHeightForWidth());
        labelSettings->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelSettings->setFont(font);

        verticalLayout->addWidget(labelSettings);

        lineh1 = new QFrame(centralWidget);
        lineh1->setObjectName(QStringLiteral("lineh1"));
        lineh1->setFrameShape(QFrame::HLine);
        lineh1->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(lineh1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        labelVoltageUp = new QLabel(centralWidget);
        labelVoltageUp->setObjectName(QStringLiteral("labelVoltageUp"));

        gridLayout->addWidget(labelVoltageUp, 0, 0, 1, 1);

        doubleSpinBoxVoltageUp = new QDoubleSpinBox(centralWidget);
        doubleSpinBoxVoltageUp->setObjectName(QStringLiteral("doubleSpinBoxVoltageUp"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doubleSpinBoxVoltageUp->sizePolicy().hasHeightForWidth());
        doubleSpinBoxVoltageUp->setSizePolicy(sizePolicy1);
        doubleSpinBoxVoltageUp->setDecimals(2);
        doubleSpinBoxVoltageUp->setMinimum(-500);
        doubleSpinBoxVoltageUp->setMaximum(500);
        doubleSpinBoxVoltageUp->setSingleStep(10);
        doubleSpinBoxVoltageUp->setValue(10);

        gridLayout->addWidget(doubleSpinBoxVoltageUp, 0, 1, 1, 1);

        labelLoad = new QLabel(centralWidget);
        labelLoad->setObjectName(QStringLiteral("labelLoad"));

        gridLayout->addWidget(labelLoad, 3, 0, 1, 1);

        toolButtonLoad = new QToolButton(centralWidget);
        toolButtonLoad->setObjectName(QStringLiteral("toolButtonLoad"));
        toolButtonLoad->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolButtonLoad->sizePolicy().hasHeightForWidth());
        toolButtonLoad->setSizePolicy(sizePolicy2);
        toolButtonLoad->setMinimumSize(QSize(120, 0));
        toolButtonLoad->setContextMenuPolicy(Qt::NoContextMenu);

        gridLayout->addWidget(toolButtonLoad, 3, 1, 1, 1);

        doubleSpinBoxTolerance = new QDoubleSpinBox(centralWidget);
        doubleSpinBoxTolerance->setObjectName(QStringLiteral("doubleSpinBoxTolerance"));
        sizePolicy1.setHeightForWidth(doubleSpinBoxTolerance->sizePolicy().hasHeightForWidth());
        doubleSpinBoxTolerance->setSizePolicy(sizePolicy1);
        doubleSpinBoxTolerance->setToolTipDuration(-1);
        doubleSpinBoxTolerance->setDecimals(5);
        doubleSpinBoxTolerance->setMinimum(1e-05);
        doubleSpinBoxTolerance->setMaximum(1);
        doubleSpinBoxTolerance->setSingleStep(0.0001);
        doubleSpinBoxTolerance->setValue(0.0001);

        gridLayout->addWidget(doubleSpinBoxTolerance, 5, 1, 1, 1);

        doubleSpinBoxVoltageLow = new QDoubleSpinBox(centralWidget);
        doubleSpinBoxVoltageLow->setObjectName(QStringLiteral("doubleSpinBoxVoltageLow"));
        doubleSpinBoxVoltageLow->setMinimum(-500);
        doubleSpinBoxVoltageLow->setMaximum(500);
        doubleSpinBoxVoltageLow->setSingleStep(10);
        doubleSpinBoxVoltageLow->setValue(-10);

        gridLayout->addWidget(doubleSpinBoxVoltageLow, 1, 1, 1, 1);

        labelAccuracy = new QLabel(centralWidget);
        labelAccuracy->setObjectName(QStringLiteral("labelAccuracy"));

        gridLayout->addWidget(labelAccuracy, 5, 0, 1, 1);

        labelVoltageLow = new QLabel(centralWidget);
        labelVoltageLow->setObjectName(QStringLiteral("labelVoltageLow"));

        gridLayout->addWidget(labelVoltageLow, 1, 0, 1, 1);

        labelVoltageGround = new QLabel(centralWidget);
        labelVoltageGround->setObjectName(QStringLiteral("labelVoltageGround"));

        gridLayout->addWidget(labelVoltageGround, 2, 0, 1, 1);

        doubleSpinBoxVoltageGround = new QDoubleSpinBox(centralWidget);
        doubleSpinBoxVoltageGround->setObjectName(QStringLiteral("doubleSpinBoxVoltageGround"));
        doubleSpinBoxVoltageGround->setMinimum(-500);
        doubleSpinBoxVoltageGround->setMaximum(500);

        gridLayout->addWidget(doubleSpinBoxVoltageGround, 2, 1, 1, 1);

        labelScale = new QLabel(centralWidget);
        labelScale->setObjectName(QStringLiteral("labelScale"));

        gridLayout->addWidget(labelScale, 4, 0, 1, 1);

        spinBoxScale = new QSpinBox(centralWidget);
        spinBoxScale->setObjectName(QStringLiteral("spinBoxScale"));
        spinBoxScale->setMinimum(1);
        spinBoxScale->setMaximum(1000);
        spinBoxScale->setValue(1);

        gridLayout->addWidget(spinBoxScale, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        lineh2 = new QFrame(centralWidget);
        lineh2->setObjectName(QStringLiteral("lineh2"));
        lineh2->setFrameShape(QFrame::HLine);
        lineh2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(lineh2);

        pushButtonRun = new QPushButton(centralWidget);
        pushButtonRun->setObjectName(QStringLiteral("pushButtonRun"));

        verticalLayout->addWidget(pushButtonRun);

        lineh3 = new QFrame(centralWidget);
        lineh3->setObjectName(QStringLiteral("lineh3"));
        lineh3->setFrameShape(QFrame::HLine);
        lineh3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(lineh3);

        labelIteration = new QLabel(centralWidget);
        labelIteration->setObjectName(QStringLiteral("labelIteration"));

        verticalLayout->addWidget(labelIteration);

        labelTime = new QLabel(centralWidget);
        labelTime->setObjectName(QStringLiteral("labelTime"));

        verticalLayout->addWidget(labelTime);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        linev1 = new QFrame(centralWidget);
        linev1->setObjectName(QStringLiteral("linev1"));
        linev1->setFrameShape(QFrame::VLine);
        linev1->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(linev1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabPotential = new QWidget();
        tabPotential->setObjectName(QStringLiteral("tabPotential"));
        gridLayout_2 = new QGridLayout(tabPotential);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        plotV = new QLabel(tabPotential);
        plotV->setObjectName(QStringLiteral("plotV"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(plotV->sizePolicy().hasHeightForWidth());
        plotV->setSizePolicy(sizePolicy3);
        plotV->setMinimumSize(QSize(1, 1));

        gridLayout_2->addWidget(plotV, 0, 0, 1, 1);

        tabWidget->addTab(tabPotential, QString());
        tabEField = new QWidget();
        tabEField->setObjectName(QStringLiteral("tabEField"));
        gridLayout_3 = new QGridLayout(tabEField);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        plotE = new QLabel(tabEField);
        plotE->setObjectName(QStringLiteral("plotE"));
        sizePolicy3.setHeightForWidth(plotE->sizePolicy().hasHeightForWidth());
        plotE->setSizePolicy(sizePolicy3);
        plotE->setMinimumSize(QSize(1, 1));

        gridLayout_3->addWidget(plotE, 0, 0, 1, 1);

        tabWidget->addTab(tabEField, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        labelSettings->setText(QApplication::translate("MainWindow", "SETTINGS:", 0));
#ifndef QT_NO_TOOLTIP
        labelVoltageUp->setToolTip(QApplication::translate("MainWindow", "Voltage of the top plate [RED]", 0));
#endif // QT_NO_TOOLTIP
        labelVoltageUp->setText(QApplication::translate("MainWindow", "Upper Voltage", 0));
#ifndef QT_NO_TOOLTIP
        labelLoad->setToolTip(QApplication::translate("MainWindow", "Load an image from a file (R= +V, B= -V, G= ground)", 0));
#endif // QT_NO_TOOLTIP
        labelLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        toolButtonLoad->setText(QApplication::translate("MainWindow", "...", 0));
#ifndef QT_NO_TOOLTIP
        labelAccuracy->setToolTip(QApplication::translate("MainWindow", "Error tolerance", 0));
#endif // QT_NO_TOOLTIP
        labelAccuracy->setText(QApplication::translate("MainWindow", "Tolerance", 0));
#ifndef QT_NO_TOOLTIP
        labelVoltageLow->setToolTip(QApplication::translate("MainWindow", "Voltage of the lower plate [BLUE]", 0));
#endif // QT_NO_TOOLTIP
        labelVoltageLow->setText(QApplication::translate("MainWindow", "Lower Voltage", 0));
#ifndef QT_NO_TOOLTIP
        labelVoltageGround->setToolTip(QApplication::translate("MainWindow", "Voltage of the ground [GREEN}", 0));
#endif // QT_NO_TOOLTIP
        labelVoltageGround->setText(QApplication::translate("MainWindow", "Ground Voltage", 0));
#ifndef QT_NO_TOOLTIP
        labelScale->setToolTip(QApplication::translate("MainWindow", "Scale the image up", 0));
#endif // QT_NO_TOOLTIP
        labelScale->setText(QApplication::translate("MainWindow", "Scale", 0));
        pushButtonRun->setText(QApplication::translate("MainWindow", "RUN", 0));
        labelIteration->setText(QString());
        labelTime->setText(QString());
        plotV->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabPotential), QApplication::translate("MainWindow", "Potential", 0));
        plotE->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabEField), QApplication::translate("MainWindow", "Electric Field", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
