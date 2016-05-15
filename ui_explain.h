/********************************************************************************
** Form generated from reading UI file 'explain.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPLAIN_H
#define UI_EXPLAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Explain
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *Explain)
    {
        if (Explain->objectName().isEmpty())
            Explain->setObjectName(QStringLiteral("Explain"));
        Explain->resize(480, 320);
        Explain->setStyleSheet(QStringLiteral("border-image: url(:/img/images/scorebg.jpg);"));
        label = new QLabel(Explain);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 210, 50, 50));
        label->setStyleSheet(QStringLiteral("border-image: url(:/img/images/bluepoint.png);"));
        label_2 = new QLabel(Explain);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 120, 50, 50));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/img/images/redpoint.png);"));
        label_3 = new QLabel(Explain);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 20, 161, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\350\217\257\345\272\267\347\247\200\351\242\250\351\253\224W3"));
        font.setPointSize(28);
        font.setBold(false);
        font.setItalic(true);
        font.setUnderline(true);
        font.setWeight(9);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/);\n"
"text-decoration: underline;\n"
"font: 75 italic 28pt \"\350\217\257\345\272\267\347\247\200\351\242\250\351\253\224W3\";\n"
"background-color: rgb(255, 255, 127);"));
        label_4 = new QLabel(Explain);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 120, 231, 51));
        label_4->setStyleSheet(QString::fromUtf8("border-image: url(:/);\n"
"font: 75 italic 26pt \"\350\217\257\345\272\267\347\247\200\351\242\250\351\253\224W3\";\n"
"background-color: rgb(255, 255, 127);"));
        label_5 = new QLabel(Explain);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 210, 231, 51));
        label_5->setStyleSheet(QString::fromUtf8("border-image: url(:/);\n"
"font: 75 italic 26pt \"\350\217\257\345\272\267\347\247\200\351\242\250\351\253\224W3\";\n"
"background-color: rgb(255, 255, 127);"));
        label_6 = new QLabel(Explain);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(270, 80, 211, 231));
        label_6->setStyleSheet(QStringLiteral("border-image: url(:/img/images/gin.png);"));
        label_5->raise();
        label_4->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_6->raise();

        retranslateUi(Explain);

        QMetaObject::connectSlotsByName(Explain);
    } // setupUi

    void retranslateUi(QDialog *Explain)
    {
        Explain->setWindowTitle(QApplication::translate("Explain", "Dialog", 0));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QApplication::translate("Explain", "\351\201\212\346\210\262\350\252\252\346\230\216", 0));
        label_4->setText(QApplication::translate("Explain", "\351\201\207\345\210\260   \346\214\211Z\351\215\265", 0));
        label_5->setText(QApplication::translate("Explain", "\351\201\207\345\210\260   \346\214\211M\351\215\265", 0));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Explain: public Ui_Explain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPLAIN_H
