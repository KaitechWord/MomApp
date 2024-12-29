#pragma once

#include "TabsWidget.h"

#include <QMainWindow>

class MainWindow : public QMainWindow{
    public:
        MainWindow(QWidget *parent = nullptr)
            : QMainWindow(parent)
        {
            this->setCentralWidget(&m_tabsWidget);
            return;
        }
    private:
        TabsWidget m_tabsWidget;
};