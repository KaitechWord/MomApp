#include "EmployeesTab.h"

EmployeesTab::EmployeesTab(QWidget *parent) : QWidget(parent), m_tabLayout(this), m_activeEmployee(nullptr)
{
    connect(&m_employeesBox, &QComboBox::activated, this, &EmployeesTab::setActiveEmployee);

    m_employeesBox.setPlaceholderText("Select employee...");

    m_employees = {{"Andrzej", "Didi", "CKD", {}, {}}, {"Bart", "Godles", "RETA", {}, {}}, {"Julas", "Kox", "WAM", {}, {}}};
    for (const auto &employee : m_employees)
    {
        m_employeesBox.addItem(employee.getFullName());
    }
    m_calendar.setDisabled(true);
    m_tabLayout.addWidget(&m_calendar);
    m_tabLayout.addLayout(&m_employeeLayout);
    m_employeeLayout.addLayout(&m_employeeDataLayout);
    m_employeeLayout.addLayout(&m_addEmployeeLayout);
    m_employeeDataLayout.addWidget(&m_employeesBox);
    m_employeeDataLayout.addWidget(&m_fullNameLabel);
    m_employeeDataLayout.addWidget(&m_facilityLabel);
    m_addEmployeeLayout.addWidget(&m_addEmployeeButton);
    m_addEmployeeButton.setText("Add new employee");
    m_employeesBox.model()->sort(0, Qt::AscendingOrder);
    std::ranges::sort(m_employees, [](const Employee &left, const Employee &right)
                      { return left.getFullName() < right.getFullName(); });
}

void EmployeesTab::setActiveEmployee(int index)
{
    m_activeEmployee = &m_employees.at(index);
    m_facilityLabel.setText(m_activeEmployee->facility);
    m_fullNameLabel.setText(m_activeEmployee->getFullName());
    m_calendar.setEnabled(true);
}