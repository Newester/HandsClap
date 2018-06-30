#ifndef QUOTOVIEW_H
#define QUOTOVIEW_H
#include <QLabel>
#include <QString>
#include <QVector>
#include <QTimer>

#define QUOTO_NUM 10


using namespace std;

const QString quotos[QUOTO_NUM] = {
    "转机即危机。",
    "相信值得信任的人，成为可信赖的人。",
    "有时会迷茫，有时会膨胀；静下心来，认真去做计划好的事情就好。",
    "每做一件事情都有成本，在做之前确保已经赚到成本或者当前有足够的余额。",
    "",
    "",
    "",
    "",
    "",
    ""
};

class QuotoView : public QLabel
{
public:
    QuotoView();

public slots:
    void OnTimeOut(void);
private:
    QTimer* m_timer;
    int m_timeout;
    QVector<QString> m_quotos;
    int m_curQuotoIndex;

};

#endif // QUOTOVIEW_H
