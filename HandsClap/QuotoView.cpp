#include "QuotoView.h"

QuotoView::QuotoView()
{
    m_timeout = 1000*10;
    m_timer = new QTimer();
    m_timer->start(m_timeout);

    m_curQuotoIndex = 0;
    for( int i = 0; i < QUOTO_NUM; i++ ) {
        m_quotos.push_back(quotos[i]);
    }
    this->setText(m_quotos[m_curQuotoIndex]);
    connect(m_timer,&QTimer::timeout,this,&QuotoView::OnTimeOut);
}

void QuotoView::OnTimeOut()
{
    if( QUOTO_NUM - 1 > m_curQuotoIndex )
        m_curQuotoIndex++;
    else
        m_curQuotoIndex = 0;
    this->setText(m_quotos[m_curQuotoIndex]);
    m_timer->start(m_timeout);
}
