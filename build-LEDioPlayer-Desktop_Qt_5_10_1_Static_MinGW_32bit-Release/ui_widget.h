/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_8;
    QSlider *v1r;
    QSlider *v1g;
    QSlider *v1b;
    QSpacerItem *horizontalSpacer_10;
    QSlider *v2r;
    QSlider *v2g;
    QSlider *v2b;
    QSpacerItem *horizontalSpacer_11;
    QSlider *v3r;
    QSlider *v3g;
    QSlider *v3b;
    QSpacerItem *horizontalSpacer_9;
    QToolButton *btn_minimize;
    QToolButton *btn_maximize;
    QToolButton *btn_close;
    QHBoxLayout *horizontalLayout_4;
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
    QProgressBar *slider_28;
    QProgressBar *slider_29;
    QProgressBar *slider_30;
    QProgressBar *slider_31;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Audio;
    QSlider *timeController;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QSlider *level;
    QSpacerItem *horizontalSpacer_12;
    QToolButton *btnReconnect;
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

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(821, 495);
        Widget->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(10, 10, 10, 10);
        centralWidget = new QWidget(Widget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, 0, -1, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(8, 0, 8, 8);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        v1r = new QSlider(centralWidget);
        v1r->setObjectName(QStringLiteral("v1r"));
        v1r->setMaximum(255);
        v1r->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(v1r);

        v1g = new QSlider(centralWidget);
        v1g->setObjectName(QStringLiteral("v1g"));
        v1g->setMaximum(255);
        v1g->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(v1g);

        v1b = new QSlider(centralWidget);
        v1b->setObjectName(QStringLiteral("v1b"));
        v1b->setMaximum(255);
        v1b->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(v1b);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        v2r = new QSlider(centralWidget);
        v2r->setObjectName(QStringLiteral("v2r"));
        v2r->setMaximum(255);
        v2r->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(v2r);

        v2g = new QSlider(centralWidget);
        v2g->setObjectName(QStringLiteral("v2g"));
        v2g->setMaximum(255);
        v2g->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(v2g);

        v2b = new QSlider(centralWidget);
        v2b->setObjectName(QStringLiteral("v2b"));
        v2b->setMaximum(255);
        v2b->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(v2b);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        v3r = new QSlider(centralWidget);
        v3r->setObjectName(QStringLiteral("v3r"));
        v3r->setMaximum(255);
        v3r->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(v3r);

        v3g = new QSlider(centralWidget);
        v3g->setObjectName(QStringLiteral("v3g"));
        v3g->setMaximum(255);
        v3g->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(v3g);

        v3b = new QSlider(centralWidget);
        v3b->setObjectName(QStringLiteral("v3b"));
        v3b->setMaximum(255);
        v3b->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(v3b);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        btn_minimize = new QToolButton(centralWidget);
        btn_minimize->setObjectName(QStringLiteral("btn_minimize"));
        btn_minimize->setAcceptDrops(false);

        horizontalLayout_3->addWidget(btn_minimize);

        btn_maximize = new QToolButton(centralWidget);
        btn_maximize->setObjectName(QStringLiteral("btn_maximize"));

        horizontalLayout_3->addWidget(btn_maximize);

        btn_close = new QToolButton(centralWidget);
        btn_close->setObjectName(QStringLiteral("btn_close"));

        horizontalLayout_3->addWidget(btn_close);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
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


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 10, -1);
        slider_0 = new QProgressBar(centralWidget);
        slider_0->setObjectName(QStringLiteral("slider_0"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(slider_0->sizePolicy().hasHeightForWidth());
        slider_0->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(6);
        slider_0->setFont(font1);
        slider_0->setMaximum(1000);
        slider_0->setValue(0);
        slider_0->setTextVisible(false);
        slider_0->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_0);

        slider_1 = new QProgressBar(centralWidget);
        slider_1->setObjectName(QStringLiteral("slider_1"));
        sizePolicy1.setHeightForWidth(slider_1->sizePolicy().hasHeightForWidth());
        slider_1->setSizePolicy(sizePolicy1);
        slider_1->setFont(font1);
        slider_1->setMaximum(1000);
        slider_1->setValue(0);
        slider_1->setTextVisible(false);
        slider_1->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_1);

        slider_2 = new QProgressBar(centralWidget);
        slider_2->setObjectName(QStringLiteral("slider_2"));
        sizePolicy1.setHeightForWidth(slider_2->sizePolicy().hasHeightForWidth());
        slider_2->setSizePolicy(sizePolicy1);
        slider_2->setFont(font1);
        slider_2->setMaximum(1000);
        slider_2->setValue(0);
        slider_2->setTextVisible(false);
        slider_2->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_2);

        slider_3 = new QProgressBar(centralWidget);
        slider_3->setObjectName(QStringLiteral("slider_3"));
        sizePolicy1.setHeightForWidth(slider_3->sizePolicy().hasHeightForWidth());
        slider_3->setSizePolicy(sizePolicy1);
        slider_3->setFont(font1);
        slider_3->setMaximum(1000);
        slider_3->setValue(0);
        slider_3->setTextVisible(false);
        slider_3->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_3);

        slider_4 = new QProgressBar(centralWidget);
        slider_4->setObjectName(QStringLiteral("slider_4"));
        sizePolicy1.setHeightForWidth(slider_4->sizePolicy().hasHeightForWidth());
        slider_4->setSizePolicy(sizePolicy1);
        slider_4->setFont(font1);
        slider_4->setMaximum(1000);
        slider_4->setValue(0);
        slider_4->setTextVisible(false);
        slider_4->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_4);

        slider_5 = new QProgressBar(centralWidget);
        slider_5->setObjectName(QStringLiteral("slider_5"));
        sizePolicy1.setHeightForWidth(slider_5->sizePolicy().hasHeightForWidth());
        slider_5->setSizePolicy(sizePolicy1);
        slider_5->setFont(font1);
        slider_5->setMaximum(1000);
        slider_5->setValue(0);
        slider_5->setTextVisible(false);
        slider_5->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_5);

        slider_6 = new QProgressBar(centralWidget);
        slider_6->setObjectName(QStringLiteral("slider_6"));
        sizePolicy1.setHeightForWidth(slider_6->sizePolicy().hasHeightForWidth());
        slider_6->setSizePolicy(sizePolicy1);
        slider_6->setFont(font1);
        slider_6->setMaximum(1000);
        slider_6->setValue(0);
        slider_6->setTextVisible(false);
        slider_6->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_6);

        slider_7 = new QProgressBar(centralWidget);
        slider_7->setObjectName(QStringLiteral("slider_7"));
        sizePolicy1.setHeightForWidth(slider_7->sizePolicy().hasHeightForWidth());
        slider_7->setSizePolicy(sizePolicy1);
        slider_7->setFont(font1);
        slider_7->setMaximum(1000);
        slider_7->setValue(0);
        slider_7->setTextVisible(false);
        slider_7->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_7);

        slider_8 = new QProgressBar(centralWidget);
        slider_8->setObjectName(QStringLiteral("slider_8"));
        sizePolicy1.setHeightForWidth(slider_8->sizePolicy().hasHeightForWidth());
        slider_8->setSizePolicy(sizePolicy1);
        slider_8->setFont(font1);
        slider_8->setMaximum(1000);
        slider_8->setValue(0);
        slider_8->setTextVisible(false);
        slider_8->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_8);

        slider_9 = new QProgressBar(centralWidget);
        slider_9->setObjectName(QStringLiteral("slider_9"));
        sizePolicy1.setHeightForWidth(slider_9->sizePolicy().hasHeightForWidth());
        slider_9->setSizePolicy(sizePolicy1);
        slider_9->setFont(font1);
        slider_9->setMaximum(1000);
        slider_9->setValue(0);
        slider_9->setTextVisible(false);
        slider_9->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_9);

        slider_10 = new QProgressBar(centralWidget);
        slider_10->setObjectName(QStringLiteral("slider_10"));
        sizePolicy1.setHeightForWidth(slider_10->sizePolicy().hasHeightForWidth());
        slider_10->setSizePolicy(sizePolicy1);
        slider_10->setFont(font1);
        slider_10->setMaximum(1000);
        slider_10->setValue(0);
        slider_10->setTextVisible(false);
        slider_10->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_10);

        slider_11 = new QProgressBar(centralWidget);
        slider_11->setObjectName(QStringLiteral("slider_11"));
        sizePolicy1.setHeightForWidth(slider_11->sizePolicy().hasHeightForWidth());
        slider_11->setSizePolicy(sizePolicy1);
        slider_11->setFont(font1);
        slider_11->setMaximum(1000);
        slider_11->setValue(0);
        slider_11->setTextVisible(false);
        slider_11->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_11);

        slider_12 = new QProgressBar(centralWidget);
        slider_12->setObjectName(QStringLiteral("slider_12"));
        sizePolicy1.setHeightForWidth(slider_12->sizePolicy().hasHeightForWidth());
        slider_12->setSizePolicy(sizePolicy1);
        slider_12->setFont(font1);
        slider_12->setMaximum(1000);
        slider_12->setValue(0);
        slider_12->setTextVisible(false);
        slider_12->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_12);

        slider_13 = new QProgressBar(centralWidget);
        slider_13->setObjectName(QStringLiteral("slider_13"));
        sizePolicy1.setHeightForWidth(slider_13->sizePolicy().hasHeightForWidth());
        slider_13->setSizePolicy(sizePolicy1);
        slider_13->setFont(font1);
        slider_13->setMaximum(1000);
        slider_13->setValue(0);
        slider_13->setTextVisible(false);
        slider_13->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_13);

        slider_14 = new QProgressBar(centralWidget);
        slider_14->setObjectName(QStringLiteral("slider_14"));
        sizePolicy1.setHeightForWidth(slider_14->sizePolicy().hasHeightForWidth());
        slider_14->setSizePolicy(sizePolicy1);
        slider_14->setFont(font1);
        slider_14->setMaximum(1000);
        slider_14->setValue(0);
        slider_14->setTextVisible(false);
        slider_14->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_14);

        slider_15 = new QProgressBar(centralWidget);
        slider_15->setObjectName(QStringLiteral("slider_15"));
        sizePolicy1.setHeightForWidth(slider_15->sizePolicy().hasHeightForWidth());
        slider_15->setSizePolicy(sizePolicy1);
        slider_15->setFont(font1);
        slider_15->setMaximum(1000);
        slider_15->setValue(0);
        slider_15->setTextVisible(false);
        slider_15->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_15);

        slider_16 = new QProgressBar(centralWidget);
        slider_16->setObjectName(QStringLiteral("slider_16"));
        sizePolicy1.setHeightForWidth(slider_16->sizePolicy().hasHeightForWidth());
        slider_16->setSizePolicy(sizePolicy1);
        slider_16->setFont(font1);
        slider_16->setMaximum(1000);
        slider_16->setValue(0);
        slider_16->setTextVisible(false);
        slider_16->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_16);

        slider_17 = new QProgressBar(centralWidget);
        slider_17->setObjectName(QStringLiteral("slider_17"));
        sizePolicy1.setHeightForWidth(slider_17->sizePolicy().hasHeightForWidth());
        slider_17->setSizePolicy(sizePolicy1);
        slider_17->setFont(font1);
        slider_17->setMaximum(1000);
        slider_17->setValue(0);
        slider_17->setTextVisible(false);
        slider_17->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_17);

        slider_18 = new QProgressBar(centralWidget);
        slider_18->setObjectName(QStringLiteral("slider_18"));
        sizePolicy1.setHeightForWidth(slider_18->sizePolicy().hasHeightForWidth());
        slider_18->setSizePolicy(sizePolicy1);
        slider_18->setFont(font1);
        slider_18->setMaximum(1000);
        slider_18->setValue(0);
        slider_18->setTextVisible(false);
        slider_18->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_18);

        slider_19 = new QProgressBar(centralWidget);
        slider_19->setObjectName(QStringLiteral("slider_19"));
        sizePolicy1.setHeightForWidth(slider_19->sizePolicy().hasHeightForWidth());
        slider_19->setSizePolicy(sizePolicy1);
        slider_19->setFont(font1);
        slider_19->setMaximum(1000);
        slider_19->setValue(0);
        slider_19->setTextVisible(false);
        slider_19->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_19);

        slider_20 = new QProgressBar(centralWidget);
        slider_20->setObjectName(QStringLiteral("slider_20"));
        sizePolicy1.setHeightForWidth(slider_20->sizePolicy().hasHeightForWidth());
        slider_20->setSizePolicy(sizePolicy1);
        slider_20->setFont(font1);
        slider_20->setMaximum(1000);
        slider_20->setValue(0);
        slider_20->setTextVisible(false);
        slider_20->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_20);

        slider_21 = new QProgressBar(centralWidget);
        slider_21->setObjectName(QStringLiteral("slider_21"));
        sizePolicy1.setHeightForWidth(slider_21->sizePolicy().hasHeightForWidth());
        slider_21->setSizePolicy(sizePolicy1);
        slider_21->setFont(font1);
        slider_21->setMaximum(1000);
        slider_21->setValue(0);
        slider_21->setTextVisible(false);
        slider_21->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_21);

        slider_22 = new QProgressBar(centralWidget);
        slider_22->setObjectName(QStringLiteral("slider_22"));
        sizePolicy1.setHeightForWidth(slider_22->sizePolicy().hasHeightForWidth());
        slider_22->setSizePolicy(sizePolicy1);
        slider_22->setFont(font1);
        slider_22->setMaximum(1000);
        slider_22->setValue(0);
        slider_22->setTextVisible(false);
        slider_22->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_22);

        slider_23 = new QProgressBar(centralWidget);
        slider_23->setObjectName(QStringLiteral("slider_23"));
        sizePolicy1.setHeightForWidth(slider_23->sizePolicy().hasHeightForWidth());
        slider_23->setSizePolicy(sizePolicy1);
        slider_23->setFont(font1);
        slider_23->setMaximum(1000);
        slider_23->setValue(0);
        slider_23->setTextVisible(false);
        slider_23->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_23);

        slider_24 = new QProgressBar(centralWidget);
        slider_24->setObjectName(QStringLiteral("slider_24"));
        sizePolicy1.setHeightForWidth(slider_24->sizePolicy().hasHeightForWidth());
        slider_24->setSizePolicy(sizePolicy1);
        slider_24->setFont(font1);
        slider_24->setMaximum(1000);
        slider_24->setValue(0);
        slider_24->setTextVisible(false);
        slider_24->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_24);

        slider_25 = new QProgressBar(centralWidget);
        slider_25->setObjectName(QStringLiteral("slider_25"));
        sizePolicy1.setHeightForWidth(slider_25->sizePolicy().hasHeightForWidth());
        slider_25->setSizePolicy(sizePolicy1);
        slider_25->setFont(font1);
        slider_25->setMaximum(1000);
        slider_25->setValue(0);
        slider_25->setTextVisible(false);
        slider_25->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_25);

        slider_26 = new QProgressBar(centralWidget);
        slider_26->setObjectName(QStringLiteral("slider_26"));
        sizePolicy1.setHeightForWidth(slider_26->sizePolicy().hasHeightForWidth());
        slider_26->setSizePolicy(sizePolicy1);
        slider_26->setFont(font1);
        slider_26->setMaximum(1000);
        slider_26->setValue(0);
        slider_26->setTextVisible(false);
        slider_26->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_26);

        slider_27 = new QProgressBar(centralWidget);
        slider_27->setObjectName(QStringLiteral("slider_27"));
        sizePolicy1.setHeightForWidth(slider_27->sizePolicy().hasHeightForWidth());
        slider_27->setSizePolicy(sizePolicy1);
        slider_27->setFont(font1);
        slider_27->setMaximum(1000);
        slider_27->setValue(0);
        slider_27->setTextVisible(false);
        slider_27->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_27);

        slider_28 = new QProgressBar(centralWidget);
        slider_28->setObjectName(QStringLiteral("slider_28"));
        sizePolicy1.setHeightForWidth(slider_28->sizePolicy().hasHeightForWidth());
        slider_28->setSizePolicy(sizePolicy1);
        slider_28->setFont(font1);
        slider_28->setMaximum(1000);
        slider_28->setValue(0);
        slider_28->setTextVisible(false);
        slider_28->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_28);

        slider_29 = new QProgressBar(centralWidget);
        slider_29->setObjectName(QStringLiteral("slider_29"));
        sizePolicy1.setHeightForWidth(slider_29->sizePolicy().hasHeightForWidth());
        slider_29->setSizePolicy(sizePolicy1);
        slider_29->setFont(font1);
        slider_29->setMaximum(1000);
        slider_29->setValue(0);
        slider_29->setTextVisible(false);
        slider_29->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_29);

        slider_30 = new QProgressBar(centralWidget);
        slider_30->setObjectName(QStringLiteral("slider_30"));
        sizePolicy1.setHeightForWidth(slider_30->sizePolicy().hasHeightForWidth());
        slider_30->setSizePolicy(sizePolicy1);
        slider_30->setFont(font1);
        slider_30->setMaximum(1000);
        slider_30->setValue(0);
        slider_30->setTextVisible(false);
        slider_30->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_30);

        slider_31 = new QProgressBar(centralWidget);
        slider_31->setObjectName(QStringLiteral("slider_31"));
        sizePolicy1.setHeightForWidth(slider_31->sizePolicy().hasHeightForWidth());
        slider_31->setSizePolicy(sizePolicy1);
        slider_31->setFont(font1);
        slider_31->setMaximum(1000);
        slider_31->setValue(0);
        slider_31->setTextVisible(false);
        slider_31->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider_31);


        horizontalLayout_4->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 10, -1);
        label_Audio = new QLabel(centralWidget);
        label_Audio->setObjectName(QStringLiteral("label_Audio"));
        label_Audio->setFont(font);

        verticalLayout_2->addWidget(label_Audio);

        timeController = new QSlider(centralWidget);
        timeController->setObjectName(QStringLiteral("timeController"));
        timeController->setMaximum(1000);
        timeController->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(timeController);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_7 = new QSpacerItem(120, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        level = new QSlider(centralWidget);
        level->setObjectName(QStringLiteral("level"));
        level->setMaximum(100);
        level->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(level);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_12);

        btnReconnect = new QToolButton(centralWidget);
        btnReconnect->setObjectName(QStringLiteral("btnReconnect"));

        horizontalLayout_2->addWidget(btnReconnect);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnPrevious = new QToolButton(centralWidget);
        btnPrevious->setObjectName(QStringLiteral("btnPrevious"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnPrevious->sizePolicy().hasHeightForWidth());
        btnPrevious->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(btnPrevious);

        horizontalSpacer_3 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btnStop = new QToolButton(centralWidget);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        sizePolicy2.setHeightForWidth(btnStop->sizePolicy().hasHeightForWidth());
        btnStop->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(btnStop);

        horizontalSpacer_4 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        btnPlay = new QToolButton(centralWidget);
        btnPlay->setObjectName(QStringLiteral("btnPlay"));
        sizePolicy2.setHeightForWidth(btnPlay->sizePolicy().hasHeightForWidth());
        btnPlay->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(btnPlay);

        horizontalSpacer_5 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        btnPause = new QToolButton(centralWidget);
        btnPause->setObjectName(QStringLiteral("btnPause"));
        sizePolicy2.setHeightForWidth(btnPause->sizePolicy().hasHeightForWidth());
        btnPause->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(btnPause);

        horizontalSpacer_6 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        btnNext = new QToolButton(centralWidget);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        sizePolicy2.setHeightForWidth(btnNext->sizePolicy().hasHeightForWidth());
        btnNext->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(btnNext);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        volController = new QSlider(centralWidget);
        volController->setObjectName(QStringLiteral("volController"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(80);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(volController->sizePolicy().hasHeightForWidth());
        volController->setSizePolicy(sizePolicy3);
        volController->setMinimumSize(QSize(100, 0));
        volController->setMaximum(100);
        volController->setValue(50);
        volController->setSliderPosition(50);
        volController->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(volController);

        label_Vol = new QLabel(centralWidget);
        label_Vol->setObjectName(QStringLiteral("label_Vol"));
        label_Vol->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(50);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_Vol->sizePolicy().hasHeightForWidth());
        label_Vol->setSizePolicy(sizePolicy4);
        label_Vol->setMinimumSize(QSize(40, 20));

        horizontalLayout_2->addWidget(label_Vol);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        gridLayout_2->addWidget(centralWidget, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        btn_minimize->setText(QString());
        btn_maximize->setText(QString());
        btn_close->setText(QString());
        btnAdd->setText(QApplication::translate("Widget", "+", nullptr));
        label_Audio->setText(QString());
        btnReconnect->setText(QApplication::translate("Widget", "R", nullptr));
        btnPrevious->setText(QString());
        btnStop->setText(QString());
        btnPlay->setText(QString());
        btnPause->setText(QString());
        btnNext->setText(QString());
        label_Vol->setText(QApplication::translate("Widget", "50", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
