#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QDialog>
#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

#include <QVector>

#include "TasksWidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();


};

#endif // MAINWIDGET_H
