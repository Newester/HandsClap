#include "TaskItemWidget.h"
#include <QPalette>


TaskItemWidget::TaskItemWidget(QString taskName, unsigned int taskTime, unsigned int index)
{

    m_taskName = taskName;

    m_taskTime = taskTime;

    m_taskRunable = false;

    m_index = (int)index;

    m_taskFinished = false;


    QHBoxLayout* mainLayout = new QHBoxLayout();
    this->setLayout(mainLayout);

    mainLayout->addStretch();

    m_taskNameLineEdit = new QLineEdit();
    m_taskNameLineEdit->setText(m_taskName);
    mainLayout->addWidget(m_taskNameLineEdit);

    m_taskTimeLineEdit = new QLineEdit();
    m_taskTimeLineEdit->setText(QString::number(m_taskTime) + " min");
    mainLayout->addWidget(m_taskTimeLineEdit);

    m_opsWidget = new QWidget();
    mainLayout->addWidget(m_opsWidget);

    mainLayout->addStretch();

    QHBoxLayout* subLayout = new QHBoxLayout();
    m_opsWidget->setLayout(subLayout);

    m_upButton = new QPushButton();
    subLayout->addWidget(m_upButton);

    m_topButton = new QPushButton();
    subLayout->addWidget(m_topButton);

    m_delButton = new QPushButton();
    subLayout->addWidget(m_delButton);


    connect(m_timer,&QTimer::timeout,this,&TaskItemWidget::OnTaskTimeOut);

    connect(m_upButton,&QPushButton::clicked,this,&TaskItemWidget::OnUpButtonClicked);
    connect(m_topButton,&QPushButton::clicked,this,&TaskItemWidget::OnTopButtonClicked);
    connect(m_delButton,&QPushButton::clicked,this,&TaskItemWidget::OnDelButtonClicked);

    this->show();
}

void TaskItemWidget::OnTaskFinished()
{
    m_timer->stop();
    SetTaskRunable(false);
    emit TaskFinishedNotice(m_taskName);
}

void TaskItemWidget::OnTaskUnfinished()
{
    m_timer->stop();
    SetTaskBreakDown();
    emit TaskUnfinishedNotice(m_taskName);
}

void TaskItemWidget::OnTaskTimeOut()
{
    if( true == m_taskFinished)
    {
        OnTaskUnfinished();
    }
    else
    {
        OnTaskUnfinished();
    }
}

void TaskItemWidget::SetTaskRunable(bool runable)
{
    m_taskRunable = runable;
    if( true == runable )
    {
        m_timer->start();
        emit TaskStartedNotice(m_taskTime);
    }
    if( true == runable )
    {
        m_taskRunable = false;
    }
}

void TaskItemWidget::SetTaskBreakDown()
{
    SetTaskRunable(false);
    m_index = -1;
    this->setBackgroundRole(QPalette::Dark);
}

void TaskItemWidget::OnUpButtonClicked()
{
    emit UpRequest(this);
}

void TaskItemWidget::OnTopButtonClicked()
{
    emit TopRequest(this);
}

void TaskItemWidget::OnDelButtonClicked()
{
    emit DelRequest(this);
}
