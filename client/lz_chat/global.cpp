#include "global.h"

/*用于刷新界面**/
std::function<void(QWidget*)> repolish = [](QWidget* w){
    w->style()->unpolish(w);
    w->style()->polish(w);
};

//简单的加密算法
std::function<QString(QString)> xorString = [](QString input) {
    QString result = input;
    int length = input.length();
    length = length % 255;
    for(int i = 0; i < length; ++i) {
        // 对每个字符进行异或操作
        // 注意：这里假设字符都是ASCII，因此直接转换为Qchar
        result[i] = QChar(static_cast<ushort>(input[i].unicode() ^ static_cast<ushort>(length)));
    }
    return result;
};

QString gate_url_prefix = "";

