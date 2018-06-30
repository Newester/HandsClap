#ifndef TASKITEMWIDGET_H
#define TASKITEMWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

#include <QTimer>

class TaskItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TaskItemWidget(QString taskName, unsigned int taskTime, unsigned int index);
    void SetTaskRunable(bool runable);
    void SetTaskBreakDown(void);
signals:
    void UpRequest(TaskItemWidget* taskItemWidget);
    void TopRequest(TaskItemWidget* taskItemWidget);
    void DelRequest(TaskItemWidget* taskItemWidget);

    void TaskStartedNotice(unsigned int taskTime);
    void TaskFinishedNotice(QString taskName);
    void TaskUnfinishedNotice(QString taskName);

public slots:
    void OnUpButtonClicked(void);
    void OnTopButtonClicked(void);
    void OnDelButtonClicked(void);

    void OnTaskFinished(void);
    void OnTaskUnfinished(void);
    void OnTaskTimeOut(void);


private:
    QString m_taskName;
    unsigned int m_taskTime;
    bool m_taskRunable;
    bool m_taskFinished;

    int m_index;

    QTimer* m_timer;

    QLineEdit* m_taskNameLineEdit;
    QLineEdit* m_taskTimeLineEdit;
    QWidget* m_opsWidget;
    QPushButton* m_upButton;
    QPushButton* m_topButton;
    QPushButton* m_delButton;
};

#endif // TASKITEMWIDGET_H
