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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEditRev;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditAddress;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QPushButton *btnConnect;
    QPushButton *btnStop;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEditSend;
    QPushButton *btnSend;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::AddressBookNew));
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

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditAddress = new QLineEdit(groupBox);
        lineEditAddress->setObjectName("lineEditAddress");

        gridLayout->addWidget(lineEditAddress, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        lineEditPort = new QLineEdit(groupBox);
        lineEditPort->setObjectName("lineEditPort");

        gridLayout->addWidget(lineEditPort, 0, 3, 1, 1);

        btnConnect = new QPushButton(groupBox);
        btnConnect->setObjectName("btnConnect");

        gridLayout->addWidget(btnConnect, 0, 4, 1, 1);

        btnStop = new QPushButton(groupBox);
        btnStop->setObjectName("btnStop");

        gridLayout->addWidget(btnStop, 1, 4, 1, 1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        textEditSend = new QTextEdit(layoutWidget);
        textEditSend->setObjectName("textEditSend");

        horizontalLayout->addWidget(textEditSend);

        btnSend = new QPushButton(layoutWidget);
        btnSend->setObjectName("btnSend");
        btnSend->setMinimumSize(QSize(0, 60));

        horizontalLayout->addWidget(btnSend);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 6);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 3);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\206\205\347\275\221\351\200\232\350\256\257\345\256\242\346\210\267\347\253\257", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200:", nullptr));
        lineEditAddress->setText(QCoreApplication::translate("Widget", "192.168.234.1", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\347\253\257\345\217\243:", nullptr));
        lineEditPort->setText(QCoreApplication::translate("Widget", "8889", nullptr));
        btnConnect->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
        btnStop->setText(QCoreApplication::translate("Widget", "\346\226\255\345\274\200", nullptr));
        btnSend->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
