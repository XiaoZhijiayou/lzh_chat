#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include "global.h"
#include "statewidget.h"
#include "userdata.h"
#include <QListWidgetItem>

namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override ;
    void handleGlobalMousePress(QMouseEvent *event) ;

private:
    void addChatUserList();
    void ClearLabelState(StateWidget* lb);
    void ShowSearch(bool bsearch = false);
    void AddLBGroup(StateWidget *lb);
    void loadMoreConUser();
    void loadMoreChatUser();
    void SetSelectChatItem(int uid = 0);
    void SetSelectChatPage(int uid = 0);
    Ui::ChatDialog *ui;
    QList<StateWidget*> _lb_list;
    ChatUIMode _mode;
    ChatUIMode _state;
    QWidget* _last_widget;
    bool _b_loading;
    QMap<int, QListWidgetItem*> _chat_items_added;
    int _cur_chat_uid;

public slots:
    void slot_loading_chat_user();
    void slot_side_chat();
    void slot_side_contact();
    void slot_text_changed(const QString & str);
    void slot_apply_friend(std::shared_ptr<AddFriendApply> apply);
    void slot_add_auth_friend(std::shared_ptr<AuthInfo> auth_info);
    void slot_auth_rsp(std::shared_ptr<AuthRsp> auth_rsp);
    void slot_jump_chat_item(std::shared_ptr<SearchInfo> si);
    void slot_loading_contact_user();
private slots:
};

#endif // CHATDIALOG_H
