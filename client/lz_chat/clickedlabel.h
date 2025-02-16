#ifndef CLICKEDLABEL_H
#define CLICKEDLABEL_H

#include "global.h"
#include <QLabel>

class ClickedLabel : public QLabel
{
    Q_OBJECT
public:
    ClickedLabel(QWidget *parent = nullptr);
    virtual void enterEvent(QEnterEvent *event) override;
    virtual void leaveEvent(QEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    void SetState(QString normal="", QString hover="", QString press="",
                  QString select="", QString select_hover="", QString select_press="");
    ClickLbState GetCurState();
    bool SetCurState(ClickLbState state);
    void ResetNormalState();

private:
    QString _normal;
    QString _normal_hover;
    QString _normal_press;

    QString _selected;
    QString _selected_hover;
    QString _selected_press;

    ClickLbState _curstate;

signals:
    void clicked(QString, ClickLbState);
};

#endif // CLICKEDLABEL_H
