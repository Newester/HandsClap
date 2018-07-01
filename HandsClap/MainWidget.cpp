#include "MainWidget.h"

#include <QDialog>
#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include<QScrollArea>

#include <QVector>

#include "TasksWidget.h"
#include "TimeView.h"
#include "QuotoView.h"
#include "TaskAddDialog.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(400,400);
/***************************************/
    QVBoxLayout* mLayout = new QVBoxLayout();
    this->setLayout(mLayout);

/**************************************/
    QHBoxLayout* quotoRow = new QHBoxLayout();
    mLayout->addLayout(quotoRow);

    quotoRow->addStretch();

    QuotoView* quotoView = new QuotoView();
    quotoRow->addWidget(quotoView);

/**************************************/
    QHBoxLayout* timeRow = new QHBoxLayout();
    mLayout->addLayout(timeRow);

    timeRow->addStretch();

    TimeView* timeView = new TimeView();
    timeRow->addWidget(timeView);


/**************************************/
    QHBoxLayout* titleRow = new QHBoxLayout();
    mLayout->addLayout(titleRow);

    titleRow->addStretch();

    QLabel* titleLabel = new QLabel("HandsClap");
    titleRow->addWidget(titleLabel);

    titleRow->addStretch();

/**************************************/
    QHBoxLayout* tasksRows = new QHBoxLayout();
    mLayout->addLayout(tasksRows);

    tasksRows->addStretch();

    QScrollArea* tasksArea = new QScrollArea();
    tasksRows->addWidget(tasksArea);

    TasksWidget* tasksWidget = new TasksWidget();
    tasksArea->setWidget(tasksWidget);
    tasksArea->setWidgetResizable(true);

    tasksRows->addStretch();

/**************************************/
    QHBoxLayout* opsRow = new QHBoxLayout();
    mLayout->addLayout(opsRow);

    opsRow->addStretch();

    QPushButton* addTaskButton = new QPushButton();
    opsRow->addWidget(addTaskButton);

    QPushButton* unfinishedButton = new QPushButton();
    opsRow->addWidget(unfinishedButton);

    QPushButton* finishedButton = new QPushButton();
    opsRow->addWidget(finishedButton);

/**************************************/
    TaskAddDialog* taskAddDialog = new TaskAddDialog(this);
/**************************************/
    connect(addTaskButton, &QPushButton::clicked,taskAddDialog,&TaskAddDialog::OnTaskAddRequest);
    connect(finishedButton, &QPushButton::clicked,tasksWidget,&TasksWidget::OnTaskFinished);
    connect(unfinishedButton, &QPushButton::clicked,tasksWidget,&TasksWidget::OnTaskUnfinished);
    connect(taskAddDialog,SIGNAL(AddTask(QString,unsigned int)),tasksWidget,SLOT(OnTaskAdd(QString,unsigned int)));


    this->show();

}

MainWidget::~MainWidget()
{

}
