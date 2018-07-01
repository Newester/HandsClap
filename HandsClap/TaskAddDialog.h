#ifndef TASKADDDIALOG_H
#define TASKADDDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QString>
#include <QLineEdit>

class TaskAddDialog : public QDialog
{

public:
    explicit TaskAddDialog(QWidget* parent = nullptr);
    QString m_addTaskName;
    int m_addTaskTime;

    QLineEdit* m_taskNameEdit;
    QLineEdit* m_taskTimeEdit;

public slots:
    OnTaskAddRequest();
    OnEditClear();
    OnEditEnsure();
private:

signals:
    void AddTask(QString,unsigned int);

};

#endif // TASKADDDIALOG_H
