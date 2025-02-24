#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include "global.h"
#include "statewidget.h"
#include "userdata.h"

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
    Ui::ChatDialog *ui;
    QList<StateWidget*> _lb_list;
    ChatUIMode _mode;
    ChatUIMode _state;
    bool _b_loading;
public slots:
    void slot_loading_chat_user();
    void slot_side_chat();
    void slot_side_contact();
    void slot_text_changed(const QString & str);
    void slot_apply_friend(std::shared_ptr<AddFriendApply> apply);

private slots:
};

#endif // CHATDIALOG_H
