#include "TaskAddDialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

TaskAddDialog::TaskAddDialog(QWidget* parent) : QDialog(parent)
{
    m_addTaskName = "";
    m_addTaskTime = -1;

    QHBoxLayout* mlayout = new QHBoxLayout();
    this->setLayout(mlayout);

    mlayout->addStretch();

    QVBoxLayout* slayout = new QVBoxLayout();
    mlayout->addLayout(slayout);

    slayout->addStretch();

    QHBoxLayout* taskName = new QHBoxLayout();
    slayout->addLayout(taskName);

    QLabel* taskNameView = new QLabel("Task Name :");
    taskName->addWidget(taskNameView);

    m_taskNameEdit = new QLineEdit("");
    taskName->addWidget(m_taskNameEdit);

    QHBoxLayout* taskTime = new QHBoxLayout();
    slayout->addLayout(taskTime);

    QLabel* taskTimeView = new QLabel("Task Time :");
    taskTime->addWidget(taskTimeView);

    m_taskTimeEdit = new QLineEdit("");
    taskTime->addWidget(m_taskTimeEdit);

    QHBoxLayout* ops = new QHBoxLayout();
    slayout->addLayout(ops);

    QPushButton* clearButton = new QPushButton("清除");
    ops->addWidget(clearButton);

    ops->addStretch();

    QPushButton* ensureButton = new QPushButton("确认");
    ops->addWidget(ensureButton);

    slayout->addStretch();

    mlayout->addStretch();

    connect(clearButton,&QPushButton::clicked,this,&TaskAddDialog::OnEditClear);
    connect(ensureButton,&QPushButton::clicked,this,&TaskAddDialog::OnEditEnsure);

    this->show();
}

TaskAddDialog::OnTaskAddRequest()
{
    this->show();
}

TaskAddDialog::OnEditClear()
{
    m_taskNameEdit->clear();
    m_taskTimeEdit->clear();
}

TaskAddDialog::OnEditEnsure()
{
    if( m_taskNameEdit->text().isEmpty() && m_taskTimeEdit->text().isEmpty() )
    {
        m_addTaskName = m_taskNameEdit->text();
        m_addTaskTime = (unsigned int)m_taskTimeEdit->text().toInt();
        m_addTaskName = "";
        m_addTaskTime = -1;
        this->hide();
    }
    else
    {
        //TODO
    }
}
