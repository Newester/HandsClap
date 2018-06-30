#include "MainWidget.h"

#include "QuotoView.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(400,400);

    QVBoxLayout* mLayout = new QVBoxLayout();
    this->setLayout(mLayout);

    QHBoxLayout* quotoRow = new QHBoxLayout();
    mLayout->addLayout(quotoRow);

    quotoRow->addStretch();

    QuotoView* quotoView = new QuotoView();
    quotoRow->addWidget(quotoView);



    QHBoxLayout* timerRow = new QHBoxLayout();
    mLayout->addLayout(timerRow);

    QHBoxLayout* titleRow = new QHBoxLayout();
    mLayout->addLayout(titleRow);

    titleRow->addStretch();

    QLabel* titleLabel = new QLabel("HandsClap");
    titleRow->addWidget(titleLabel);

    titleRow->addStretch();

    QVBoxLayout* tasksRows = new QVBoxLayout();
    mLayout->addLayout(tasksRows);


    TasksWidget* tasksWidget = new TasksWidget();
    tasksRows->addWidget(tasksWidget);

    QHBoxLayout* opsRow = new QHBoxLayout();
    mLayout->addLayout(opsRow);

    this->show();

}

MainWidget::~MainWidget()
{

}
