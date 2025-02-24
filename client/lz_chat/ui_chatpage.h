/********************************************************************************
** Form generated from reading UI file 'chatpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATPAGE_H
#define UI_CHATPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickedbtn.h>
#include <clickedlabel.h>
#include <messagetextedit.h>
#include "chatview.h"

QT_BEGIN_NAMESPACE

class Ui_ChatPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *chat_data_wid;
    QVBoxLayout *verticalLayout_4;
    QWidget *title_wid;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *titile_lb;
    ChatView *chat_data_list;
    QWidget *tool_wid;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    ClickedLabel *emo_lb;
    QSpacerItem *horizontalSpacer_4;
    ClickedLabel *file_lb;
    QSpacerItem *horizontalSpacer_3;
    MessageTextEdit *chatEdit;
    QWidget *send_wid;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    ClickedBtn *receive_btn;
    QSpacerItem *horizontalSpacer_6;
    ClickedBtn *send_btn;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QWidget *ChatPage)
    {
        if (ChatPage->objectName().isEmpty())
            ChatPage->setObjectName("ChatPage");
        ChatPage->resize(721, 948);
        verticalLayout = new QVBoxLayout(ChatPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        chat_data_wid = new QWidget(ChatPage);
        chat_data_wid->setObjectName("chat_data_wid");
        verticalLayout_4 = new QVBoxLayout(chat_data_wid);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        title_wid = new QWidget(chat_data_wid);
        title_wid->setObjectName("title_wid");
        title_wid->setMinimumSize(QSize(0, 60));
        title_wid->setMaximumSize(QSize(16777215, 60));
        verticalLayout_5 = new QVBoxLayout(title_wid);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(-1, 2, 2, 2);
        widget_2 = new QWidget(title_wid);
        widget_2->setObjectName("widget_2");
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(2, 2, 2, 2);
        titile_lb = new QLabel(widget_2);
        titile_lb->setObjectName("titile_lb");

        horizontalLayout_3->addWidget(titile_lb);


        verticalLayout_5->addWidget(widget_2);


        verticalLayout_4->addWidget(title_wid);

        chat_data_list = new ChatView(chat_data_wid);
        chat_data_list->setObjectName("chat_data_list");

        verticalLayout_4->addWidget(chat_data_list);

        tool_wid = new QWidget(chat_data_wid);
        tool_wid->setObjectName("tool_wid");
        tool_wid->setMinimumSize(QSize(0, 40));
        tool_wid->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_4 = new QHBoxLayout(tool_wid);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(2, 2, 2, 2);
        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        emo_lb = new ClickedLabel(tool_wid);
        emo_lb->setObjectName("emo_lb");
        emo_lb->setMinimumSize(QSize(25, 25));
        emo_lb->setMaximumSize(QSize(25, 25));

        horizontalLayout_4->addWidget(emo_lb);

        horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        file_lb = new ClickedLabel(tool_wid);
        file_lb->setObjectName("file_lb");
        file_lb->setMinimumSize(QSize(25, 25));
        file_lb->setMaximumSize(QSize(25, 25));

        horizontalLayout_4->addWidget(file_lb);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_4->addWidget(tool_wid);

        chatEdit = new MessageTextEdit(chat_data_wid);
        chatEdit->setObjectName("chatEdit");
        chatEdit->setMinimumSize(QSize(0, 150));
        chatEdit->setMaximumSize(QSize(16777215, 150));

        verticalLayout_4->addWidget(chatEdit);

        send_wid = new QWidget(chat_data_wid);
        send_wid->setObjectName("send_wid");
        send_wid->setMinimumSize(QSize(0, 40));
        send_wid->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_5 = new QHBoxLayout(send_wid);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(-1, 2, -1, 2);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        receive_btn = new ClickedBtn(send_wid);
        receive_btn->setObjectName("receive_btn");
        receive_btn->setMinimumSize(QSize(100, 30));
        receive_btn->setMaximumSize(QSize(100, 30));

        horizontalLayout_5->addWidget(receive_btn);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        send_btn = new ClickedBtn(send_wid);
        send_btn->setObjectName("send_btn");
        send_btn->setMinimumSize(QSize(100, 30));
        send_btn->setMaximumSize(QSize(100, 30));

        horizontalLayout_5->addWidget(send_btn);

        horizontalSpacer_7 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);


        verticalLayout_4->addWidget(send_wid);


        verticalLayout->addWidget(chat_data_wid);


        retranslateUi(ChatPage);

        QMetaObject::connectSlotsByName(ChatPage);
    } // setupUi

    void retranslateUi(QWidget *ChatPage)
    {
        ChatPage->setWindowTitle(QCoreApplication::translate("ChatPage", "Form", nullptr));
        titile_lb->setText(QCoreApplication::translate("ChatPage", "\346\235\216\346\231\272\346\265\251", nullptr));
        emo_lb->setText(QString());
        file_lb->setText(QString());
        receive_btn->setText(QCoreApplication::translate("ChatPage", "\346\216\245\346\224\266", nullptr));
        send_btn->setText(QCoreApplication::translate("ChatPage", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatPage: public Ui_ChatPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATPAGE_H
