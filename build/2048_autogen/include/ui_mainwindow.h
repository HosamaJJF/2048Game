/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *startg;
    QLabel *score;
    QLabel *g11;
    QLabel *g12;
    QLabel *g13;
    QLabel *g14;
    QLabel *g23;
    QLabel *g21;
    QLabel *g24;
    QLabel *g22;
    QLabel *g33;
    QLabel *g31;
    QLabel *g34;
    QLabel *g32;
    QLabel *g44;
    QLabel *g41;
    QLabel *g42;
    QLabel *g43;
    QLabel *description;
    QLabel *scorenum;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(424, 522);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        startg = new QPushButton(centralwidget);
        startg->setObjectName("startg");
        startg->setGeometry(QRect(20, 20, 111, 61));
        score = new QLabel(centralwidget);
        score->setObjectName("score");
        score->setGeometry(QRect(220, 20, 31, 61));
        score->setAutoFillBackground(false);
        score->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        g11 = new QLabel(centralwidget);
        g11->setObjectName("g11");
        g11->setGeometry(QRect(90, 120, 50, 50));
        g11->setAlignment(Qt::AlignCenter);
        g12 = new QLabel(centralwidget);
        g12->setObjectName("g12");
        g12->setGeometry(QRect(150, 120, 50, 50));
        g12->setAlignment(Qt::AlignCenter);
        g13 = new QLabel(centralwidget);
        g13->setObjectName("g13");
        g13->setGeometry(QRect(210, 120, 50, 50));
        g13->setAlignment(Qt::AlignCenter);
        g14 = new QLabel(centralwidget);
        g14->setObjectName("g14");
        g14->setGeometry(QRect(270, 120, 50, 50));
        g14->setAlignment(Qt::AlignCenter);
        g23 = new QLabel(centralwidget);
        g23->setObjectName("g23");
        g23->setGeometry(QRect(210, 180, 50, 50));
        g23->setAlignment(Qt::AlignCenter);
        g21 = new QLabel(centralwidget);
        g21->setObjectName("g21");
        g21->setGeometry(QRect(90, 180, 50, 50));
        g21->setAlignment(Qt::AlignCenter);
        g24 = new QLabel(centralwidget);
        g24->setObjectName("g24");
        g24->setGeometry(QRect(270, 180, 50, 50));
        g24->setAlignment(Qt::AlignCenter);
        g22 = new QLabel(centralwidget);
        g22->setObjectName("g22");
        g22->setGeometry(QRect(150, 180, 50, 50));
        g22->setAlignment(Qt::AlignCenter);
        g33 = new QLabel(centralwidget);
        g33->setObjectName("g33");
        g33->setGeometry(QRect(210, 240, 50, 50));
        g33->setAlignment(Qt::AlignCenter);
        g31 = new QLabel(centralwidget);
        g31->setObjectName("g31");
        g31->setGeometry(QRect(90, 240, 50, 50));
        g31->setAlignment(Qt::AlignCenter);
        g34 = new QLabel(centralwidget);
        g34->setObjectName("g34");
        g34->setGeometry(QRect(270, 240, 50, 50));
        g34->setAlignment(Qt::AlignCenter);
        g32 = new QLabel(centralwidget);
        g32->setObjectName("g32");
        g32->setGeometry(QRect(150, 240, 50, 50));
        g32->setAlignment(Qt::AlignCenter);
        g44 = new QLabel(centralwidget);
        g44->setObjectName("g44");
        g44->setGeometry(QRect(270, 300, 50, 50));
        g44->setAlignment(Qt::AlignCenter);
        g41 = new QLabel(centralwidget);
        g41->setObjectName("g41");
        g41->setGeometry(QRect(90, 300, 50, 50));
        g41->setAlignment(Qt::AlignCenter);
        g42 = new QLabel(centralwidget);
        g42->setObjectName("g42");
        g42->setGeometry(QRect(150, 300, 50, 50));
        g42->setAlignment(Qt::AlignCenter);
        g43 = new QLabel(centralwidget);
        g43->setObjectName("g43");
        g43->setGeometry(QRect(210, 300, 50, 50));
        g43->setAlignment(Qt::AlignCenter);
        description = new QLabel(centralwidget);
        description->setObjectName("description");
        description->setGeometry(QRect(40, 390, 341, 61));
        description->setAlignment(Qt::AlignCenter);
        scorenum = new QLabel(centralwidget);
        scorenum->setObjectName("scorenum");
        scorenum->setGeometry(QRect(255, 20, 131, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 424, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "2048 By\351\207\221\344\277\212\345\270\206\343\200\201\345\274\240\346\245\240\343\200\201\350\264\276\345\245\207\345\263\260\343\200\201\351\231\210\344\275\263\350\264\244", nullptr));
        startg->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213/\351\207\215\347\275\256", nullptr));
        score->setText(QCoreApplication::translate("MainWindow", "\345\210\206\346\225\260\357\274\232", nullptr));
        g11->setText(QString());
        g12->setText(QString());
        g13->setText(QString());
        g14->setText(QString());
        g23->setText(QString());
        g21->setText(QString());
        g24->setText(QString());
        g22->setText(QString());
        g33->setText(QString());
        g31->setText(QString());
        g34->setText(QString());
        g32->setText(QString());
        g44->setText(QString());
        g41->setText(QString());
        g42->setText(QString());
        g43->setText(QString());
        description->setText(QCoreApplication::translate("MainWindow", "\346\214\211W(\344\270\212)S(\344\270\213)A(\345\267\246)D(\345\217\263)\350\256\251\347\233\270\345\220\214\346\225\260\345\255\227\347\232\204\346\226\271\346\240\274\345\220\210\345\271\266\357\274\214\345\276\227\345\210\2602048\357\274\201", nullptr));
        scorenum->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
