/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QToolButton *btnAdd;
    QTableView *playlist;
    QHBoxLayout *horizontalLayout;
    QProgressBar *slider_0;
    QProgressBar *slider_1;
    QProgressBar *slider_2;
    QProgressBar *slider_3;
    QProgressBar *slider_4;
    QProgressBar *slider_5;
    QProgressBar *slider_6;
    QProgressBar *slider_7;
    QProgressBar *slider_8;
    QProgressBar *slider_9;
    QProgressBar *slider_10;
    QProgressBar *slider_11;
    QProgressBar *slider_12;
    QProgressBar *slider_13;
    QProgressBar *slider_14;
    QProgressBar *slider_15;
    QProgressBar *slider_16;
    QProgressBar *slider_17;
    QProgressBar *slider_18;
    QProgressBar *slider_19;
    QProgressBar *slider_20;
    QProgressBar *slider_21;
    QProgressBar *slider_22;
    QProgressBar *slider_23;
    QProgressBar *slider_24;
    QProgressBar *slider_25;
    QProgressBar *slider_26;
    QProgressBar *slider_27;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Audio;
    QSlider *timeController;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer;
    QToolButton *btnPrevious;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *btnStop;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *btnPlay;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *btnPause;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *btnNext;
    QSpacerItem *horizontalSpacer_2;
    QSlider *volController;
    QLabel *label_Vol;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1211, 698);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnAdd = new QToolButton(centralWidget);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(40);
        sizePolicy.setHeightForWidth(btnAdd->sizePolicy().hasHeightForWidth());
        btnAdd->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        btnAdd->setFont(font);

        verticalLayout->addWidget(btnAdd);

        playlist = new QTableView(centralWidget);
        playlist->setObjectName(QStringLiteral("playlist"));
        playlist->setMinimumSize(QSize(200, 0));
        playlist->setMaximumSize(QSize(10000, 16777215));

        verticalLayout->addWidget(playlist);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        slider_0 = new QProgressBar(centralWidget);
        slider_0->setObjectName(QStringLiteral("slider_0"));
        slider_0->setMaximum(1000);
        slider_0->setValue(0);
        slider_0->setTextVisible(false);
        slider_0->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_0);

        slider_1 = new QProgressBar(centralWidget);
        slider_1->setObjectName(QStringLiteral("slider_1"));
        slider_1->setMaximum(1000);
        slider_1->setValue(0);
        slider_1->setTextVisible(false);
        slider_1->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_1);

        slider_2 = new QProgressBar(centralWidget);
        slider_2->setObjectName(QStringLiteral("slider_2"));
        slider_2->setMaximum(1000);
        slider_2->setValue(0);
        slider_2->setTextVisible(false);
        slider_2->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_2);

        slider_3 = new QProgressBar(centralWidget);
        slider_3->setObjectName(QStringLiteral("slider_3"));
        slider_3->setMaximum(1000);
        slider_3->setValue(0);
        slider_3->setTextVisible(false);
        slider_3->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_3);

        slider_4 = new QProgressBar(centralWidget);
        slider_4->setObjectName(QStringLiteral("slider_4"));
        slider_4->setMaximum(1000);
        slider_4->setValue(0);
        slider_4->setTextVisible(false);
        slider_4->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_4);

        slider_5 = new QProgressBar(centralWidget);
        slider_5->setObjectName(QStringLiteral("slider_5"));
        slider_5->setMaximum(1000);
        slider_5->setValue(0);
        slider_5->setTextVisible(false);
        slider_5->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_5);

        slider_6 = new QProgressBar(centralWidget);
        slider_6->setObjectName(QStringLiteral("slider_6"));
        slider_6->setMaximum(1000);
        slider_6->setValue(0);
        slider_6->setTextVisible(false);
        slider_6->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_6);

        slider_7 = new QProgressBar(centralWidget);
        slider_7->setObjectName(QStringLiteral("slider_7"));
        slider_7->setMaximum(1000);
        slider_7->setValue(0);
        slider_7->setTextVisible(false);
        slider_7->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_7);

        slider_8 = new QProgressBar(centralWidget);
        slider_8->setObjectName(QStringLiteral("slider_8"));
        slider_8->setMaximum(1000);
        slider_8->setValue(0);
        slider_8->setTextVisible(false);
        slider_8->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_8);

        slider_9 = new QProgressBar(centralWidget);
        slider_9->setObjectName(QStringLiteral("slider_9"));
        slider_9->setMaximum(1000);
        slider_9->setValue(0);
        slider_9->setTextVisible(false);
        slider_9->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_9);

        slider_10 = new QProgressBar(centralWidget);
        slider_10->setObjectName(QStringLiteral("slider_10"));
        slider_10->setMaximum(1000);
        slider_10->setValue(0);
        slider_10->setTextVisible(false);
        slider_10->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_10);

        slider_11 = new QProgressBar(centralWidget);
        slider_11->setObjectName(QStringLiteral("slider_11"));
        slider_11->setMaximum(1000);
        slider_11->setValue(0);
        slider_11->setTextVisible(false);
        slider_11->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_11);

        slider_12 = new QProgressBar(centralWidget);
        slider_12->setObjectName(QStringLiteral("slider_12"));
        slider_12->setMaximum(1000);
        slider_12->setValue(0);
        slider_12->setTextVisible(false);
        slider_12->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_12);

        slider_13 = new QProgressBar(centralWidget);
        slider_13->setObjectName(QStringLiteral("slider_13"));
        slider_13->setMaximum(1000);
        slider_13->setValue(0);
        slider_13->setTextVisible(false);
        slider_13->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_13);

        slider_14 = new QProgressBar(centralWidget);
        slider_14->setObjectName(QStringLiteral("slider_14"));
        slider_14->setMaximum(1000);
        slider_14->setValue(0);
        slider_14->setTextVisible(false);
        slider_14->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_14);

        slider_15 = new QProgressBar(centralWidget);
        slider_15->setObjectName(QStringLiteral("slider_15"));
        slider_15->setMaximum(1000);
        slider_15->setValue(0);
        slider_15->setTextVisible(false);
        slider_15->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_15);

        slider_16 = new QProgressBar(centralWidget);
        slider_16->setObjectName(QStringLiteral("slider_16"));
        slider_16->setMaximum(1000);
        slider_16->setValue(0);
        slider_16->setTextVisible(false);
        slider_16->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_16);

        slider_17 = new QProgressBar(centralWidget);
        slider_17->setObjectName(QStringLiteral("slider_17"));
        slider_17->setMaximum(1000);
        slider_17->setValue(0);
        slider_17->setTextVisible(false);
        slider_17->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_17);

        slider_18 = new QProgressBar(centralWidget);
        slider_18->setObjectName(QStringLiteral("slider_18"));
        slider_18->setMaximum(1000);
        slider_18->setValue(0);
        slider_18->setTextVisible(false);
        slider_18->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_18);

        slider_19 = new QProgressBar(centralWidget);
        slider_19->setObjectName(QStringLiteral("slider_19"));
        slider_19->setMaximum(1000);
        slider_19->setValue(0);
        slider_19->setTextVisible(false);
        slider_19->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_19);

        slider_20 = new QProgressBar(centralWidget);
        slider_20->setObjectName(QStringLiteral("slider_20"));
        slider_20->setMaximum(1000);
        slider_20->setValue(0);
        slider_20->setTextVisible(false);
        slider_20->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_20);

        slider_21 = new QProgressBar(centralWidget);
        slider_21->setObjectName(QStringLiteral("slider_21"));
        slider_21->setMaximum(1000);
        slider_21->setValue(0);
        slider_21->setTextVisible(false);
        slider_21->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_21);

        slider_22 = new QProgressBar(centralWidget);
        slider_22->setObjectName(QStringLiteral("slider_22"));
        slider_22->setMaximum(1000);
        slider_22->setValue(0);
        slider_22->setTextVisible(false);
        slider_22->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_22);

        slider_23 = new QProgressBar(centralWidget);
        slider_23->setObjectName(QStringLiteral("slider_23"));
        slider_23->setMaximum(1000);
        slider_23->setValue(0);
        slider_23->setTextVisible(false);
        slider_23->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_23);

        slider_24 = new QProgressBar(centralWidget);
        slider_24->setObjectName(QStringLiteral("slider_24"));
        slider_24->setMaximum(1000);
        slider_24->setValue(0);
        slider_24->setTextVisible(false);
        slider_24->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_24);

        slider_25 = new QProgressBar(centralWidget);
        slider_25->setObjectName(QStringLiteral("slider_25"));
        slider_25->setMaximum(1000);
        slider_25->setValue(0);
        slider_25->setTextVisible(false);
        slider_25->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_25);

        slider_26 = new QProgressBar(centralWidget);
        slider_26->setObjectName(QStringLiteral("slider_26"));
        slider_26->setMaximum(1000);
        slider_26->setValue(0);
        slider_26->setTextVisible(false);
        slider_26->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_26);

        slider_27 = new QProgressBar(centralWidget);
        slider_27->setObjectName(QStringLiteral("slider_27"));
        slider_27->setMaximum(1000);
        slider_27->setValue(0);
        slider_27->setTextVisible(false);
        slider_27->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_27);


        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_Audio = new QLabel(centralWidget);
        label_Audio->setObjectName(QStringLiteral("label_Audio"));
        label_Audio->setFont(font);

        verticalLayout_2->addWidget(label_Audio);

        timeController = new QSlider(centralWidget);
        timeController->setObjectName(QStringLiteral("timeController"));
        timeController->setMaximum(1000);
        timeController->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(timeController);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_7 = new QSpacerItem(120, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnPrevious = new QToolButton(centralWidget);
        btnPrevious->setObjectName(QStringLiteral("btnPrevious"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnPrevious->sizePolicy().hasHeightForWidth());
        btnPrevious->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(btnPrevious);

        horizontalSpacer_3 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btnStop = new QToolButton(centralWidget);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        sizePolicy1.setHeightForWidth(btnStop->sizePolicy().hasHeightForWidth());
        btnStop->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(btnStop);

        horizontalSpacer_4 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        btnPlay = new QToolButton(centralWidget);
        btnPlay->setObjectName(QStringLiteral("btnPlay"));
        sizePolicy1.setHeightForWidth(btnPlay->sizePolicy().hasHeightForWidth());
        btnPlay->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(btnPlay);

        horizontalSpacer_5 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        btnPause = new QToolButton(centralWidget);
        btnPause->setObjectName(QStringLiteral("btnPause"));
        sizePolicy1.setHeightForWidth(btnPause->sizePolicy().hasHeightForWidth());
        btnPause->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(btnPause);

        horizontalSpacer_6 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        btnNext = new QToolButton(centralWidget);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        sizePolicy1.setHeightForWidth(btnNext->sizePolicy().hasHeightForWidth());
        btnNext->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(btnNext);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        volController = new QSlider(centralWidget);
        volController->setObjectName(QStringLiteral("volController"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(80);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(volController->sizePolicy().hasHeightForWidth());
        volController->setSizePolicy(sizePolicy2);
        volController->setMinimumSize(QSize(100, 0));
        volController->setMaximum(100);
        volController->setValue(50);
        volController->setSliderPosition(50);
        volController->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(volController);

        label_Vol = new QLabel(centralWidget);
        label_Vol->setObjectName(QStringLiteral("label_Vol"));
        label_Vol->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(50);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_Vol->sizePolicy().hasHeightForWidth());
        label_Vol->setSizePolicy(sizePolicy3);
        label_Vol->setMinimumSize(QSize(40, 20));

        horizontalLayout_2->addWidget(label_Vol);


        verticalLayout_3->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1211, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        btnAdd->setText(QApplication::translate("MainWindow", "+", nullptr));
        label_Audio->setText(QString());
        btnPrevious->setText(QString());
        btnStop->setText(QString());
        btnPlay->setText(QString());
        btnPause->setText(QString());
        btnNext->setText(QString());
        label_Vol->setText(QApplication::translate("MainWindow", "50", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
