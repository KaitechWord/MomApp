#pragma once
#include <QTabWidget>
#include <utility>

class TabsWidget : public QTabWidget {
    enum class TABS{
        MAIN,
        EMPLOYEES,
        FACILITIES,
        SIZE
    };

    public:
        TabsWidget(QWidget *parent = nullptr)
            : QTabWidget(parent)
        {
            m_tabs.at(std::to_underlying(TABS::MAIN)) = new QWidget(this);
            return;
        };
    private:
        std::array<QWidget*, std::to_underlying(TABS::SIZE)> m_tabs;
};