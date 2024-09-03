/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clientscombox.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEditRev;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *labelProtocol;
    QComboBox *comboBoxProtocol;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelAddress;
    QComboBox *comboBoxAddress;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labelPort;
    QLineEdit *lineEditPort;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnListen;
    QPushButton *btnStopListen;
    QPushButton *btnClientSuspend;
    ClientsCombox *comboBoxClients;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEditSent;
    QPushButton *btnSent;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::NetworkWireless));
        Widget->setWindowIcon(icon);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 801, 601));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEditRev = new QTextEdit(layoutWidget);
        textEditRev->setObjectName("textEditRev");

        verticalLayout->addWidget(textEditRev);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelProtocol = new QLabel(layoutWidget);
        labelProtocol->setObjectName("labelProtocol");

        horizontalLayout->addWidget(labelProtocol);

        comboBoxProtocol = new QComboBox(layoutWidget);
        comboBoxProtocol->addItem(QString());
        comboBoxProtocol->addItem(QString());
        comboBoxProtocol->setObjectName("comboBoxProtocol");

        horizontalLayout->addWidget(comboBoxProtocol);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        labelAddress = new QLabel(layoutWidget);
        labelAddress->setObjectName("labelAddress");

        horizontalLayout->addWidget(labelAddress);

        comboBoxAddress = new QComboBox(layoutWidget);
        comboBoxAddress->setObjectName("comboBoxAddress");

        horizontalLayout->addWidget(comboBoxAddress);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        labelPort = new QLabel(layoutWidget);
        labelPort->setObjectName("labelPort");

        horizontalLayout->addWidget(labelPort);

        lineEditPort = new QLineEdit(layoutWidget);
        lineEditPort->setObjectName("lineEditPort");

        horizontalLayout->addWidget(lineEditPort);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnListen = new QPushButton(layoutWidget);
        btnListen->setObjectName("btnListen");

        horizontalLayout_2->addWidget(btnListen);

        btnStopListen = new QPushButton(layoutWidget);
        btnStopListen->setObjectName("btnStopListen");

        horizontalLayout_2->addWidget(btnStopListen);

        btnClientSuspend = new QPushButton(layoutWidget);
        btnClientSuspend->setObjectName("btnClientSuspend");

        horizontalLayout_2->addWidget(btnClientSuspend);


        verticalLayout->addLayout(horizontalLayout_2);

        comboBoxClients = new ClientsCombox(layoutWidget);
        comboBoxClients->setObjectName("comboBoxClients");

        verticalLayout->addWidget(comboBoxClients);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        textEditSent = new QTextEdit(layoutWidget);
        textEditSent->setObjectName("textEditSent");

        horizontalLayout_3->addWidget(textEditSent);

        btnSent = new QPushButton(layoutWidget);
        btnSent->setObjectName("btnSent");
        btnSent->setMinimumSize(QSize(0, 80));
        btnSent->setMaximumSize(QSize(16777214, 16777215));

        horizontalLayout_3->addWidget(btnSent);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 6);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(4, 4);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\206\205\347\275\221\351\200\232\350\256\257\345\267\245\345\205\267", nullptr));
        labelProtocol->setText(QCoreApplication::translate("Widget", "\351\200\232\344\277\241\345\215\217\350\256\256", nullptr));
        comboBoxProtocol->setItemText(0, QCoreApplication::translate("Widget", "TCP", nullptr));
        comboBoxProtocol->setItemText(1, QCoreApplication::translate("Widget", "UDP", nullptr));

        labelAddress->setText(QCoreApplication::translate("Widget", "IPV4\345\234\260\345\235\200", nullptr));
        labelPort->setText(QCoreApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267", nullptr));
        lineEditPort->setPlaceholderText(QCoreApplication::translate("Widget", "\345\273\272\350\256\2560~65535", nullptr));
        btnListen->setText(QCoreApplication::translate("Widget", "\347\233\221\345\220\254", nullptr));
        btnStopListen->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\347\233\221\345\220\254", nullptr));
        btnClientSuspend->setText(QCoreApplication::translate("Widget", "\346\226\255\345\274\200", nullptr));
        comboBoxClients->setPlaceholderText(QCoreApplication::translate("Widget", "\350\257\267\351\200\211\346\213\251\345\256\242\346\210\267\347\253\257\345\217\221\351\200\201", nullptr));
        btnSent->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
