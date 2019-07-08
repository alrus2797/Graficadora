/********************************************************************************
** Form generated from reading UI file 'graficadora.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAFICADORA_H
#define UI_GRAFICADORA_H

#include <QVTKWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Graficadora
{
public:
    QWidget *centralWidget;
    QVTKWidget *qvtkWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *Input;
    QPushButton *Boton;
    QLabel *label_2;
    QLabel *Output;
    QMenuBar *menuBar;
    QMenu *menuGraficadora;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Graficadora)
    {
        if (Graficadora->objectName().isEmpty())
            Graficadora->setObjectName(QStringLiteral("Graficadora"));
        Graficadora->resize(925, 600);
        centralWidget = new QWidget(Graficadora);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        qvtkWidget = new QVTKWidget(centralWidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(10, 10, 661, 451));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 470, 661, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("NanumGothic"));
        font.setPointSize(14);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        Input = new QLineEdit(horizontalLayoutWidget);
        Input->setObjectName(QStringLiteral("Input"));

        horizontalLayout->addWidget(Input);

        Boton = new QPushButton(horizontalLayoutWidget);
        Boton->setObjectName(QStringLiteral("Boton"));

        horizontalLayout->addWidget(Boton);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 500, 81, 29));
        QFont font1;
        font1.setFamily(QStringLiteral("NanumGothic"));
        font1.setPointSize(12);
        label_2->setFont(font1);
        Output = new QLabel(centralWidget);
        Output->setObjectName(QStringLiteral("Output"));
        Output->setGeometry(QRect(100, 500, 411, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("NanumGothic"));
        font2.setPointSize(11);
        Output->setFont(font2);
        Graficadora->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Graficadora);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 925, 20));
        menuGraficadora = new QMenu(menuBar);
        menuGraficadora->setObjectName(QStringLiteral("menuGraficadora"));
        Graficadora->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Graficadora);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Graficadora->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Graficadora);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Graficadora->setStatusBar(statusBar);

        menuBar->addAction(menuGraficadora->menuAction());

        retranslateUi(Graficadora);

        QMetaObject::connectSlotsByName(Graficadora);
    } // setupUi

    void retranslateUi(QMainWindow *Graficadora)
    {
        Graficadora->setWindowTitle(QApplication::translate("Graficadora", "Graficadora", nullptr));
        label->setText(QApplication::translate("Graficadora", "Funci\303\263n:", nullptr));
        Boton->setText(QApplication::translate("Graficadora", "Graficar", nullptr));
        label_2->setText(QApplication::translate("Graficadora", "Ingresaste:", nullptr));
        Output->setText(QString());
        menuGraficadora->setTitle(QApplication::translate("Graficadora", "Graficadora", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graficadora: public Ui_Graficadora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAFICADORA_H
