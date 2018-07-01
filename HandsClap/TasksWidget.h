#ifndef TASKSWIDGET_H
#define TASKSWIDGET_H

#include <QWidget>
#include<QPushButton>
#include<QString>

#include "TaskItemWidget.h"

class TasksWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TasksWidget(QWidget *parent = nullptr);

signals:

public slots:
    void OnTaskFinished(void);
    void OnTaskUnfinished(void);
    void OnTaskAdd(QString taskName,unsigned int taskTime);
};

#endif // TASKSWIDGET_H
