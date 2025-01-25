#pragma once

#include "EmployeesTab.h"

#include <utility>

#include <QTabWidget>

class TabsWidget : public QTabWidget
{
    enum class Tabs
    {
        General,
        Employees,
        Facilities,
        Size
    };

    struct WidgetToName
    {
        QWidget *tab;
        QString name;
    };

public:
    TabsWidget(QWidget *parent = nullptr)
        : QTabWidget(parent)
    {
        m_tabs = {
            {Tabs::General, {new QWidget(this), "General"}}, {Tabs::Employees, {new EmployeesTab(this), "Employees"}}, {Tabs::Facilities, {new QWidget(this), "Facilities"}}};

        for (const auto &[_, widgetToName] : m_tabs)
        {
            addTab(widgetToName.tab, widgetToName.name);
        }
    };

private:
    std::map<Tabs, WidgetToName> m_tabs;
};