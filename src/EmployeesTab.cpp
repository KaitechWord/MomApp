#include "EmployeesTab.h"

EmployeesTab::EmployeesTab(QWidget *parent) : QWidget(parent), m_tabLayout(this), m_addEmployeePopup(m_employees, this), m_activeEmployee(nullptr)
{
    connect(&m_employeesBox, &QComboBox::activated, this, &EmployeesTab::setActiveEmployee);
    connect(&m_addEmployeeButton, &QPushButton::clicked, this, &EmployeesTab::openPopup);
    connect(&m_addEmployeePopup, &QDialog::finished, this, &EmployeesTab::closePopup);

    m_employeesBox.setPlaceholderText("Select employee...");

    m_employees = {{"Andi", "Didi", "CKD", {}, {}}, {"Bart", "Godles", "RETA", {}, {}}, {"Julas", "Kox", "WAM", {}, {}}};
    for (const auto &employee : m_employees)
    {
        m_employeesBox.addItem(employee.getFullName());
    }
    // m_calendar.setDisabled(true);
    m_calendar.setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    m_calendar.setFirstDayOfWeek(Qt::DayOfWeek::Monday);
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
                      { return left.surname < right.surname; });
    m_addEmployeeLayout.addWidget(&m_addEmployeePopup);
}

void EmployeesTab::setActiveEmployee(int index)
{
    m_activeEmployee = &m_employees.at(index);
    m_facilityLabel.setText(m_activeEmployee->facility);
    m_fullNameLabel.setText(m_activeEmployee->getFullName());
    m_calendar.setEnabled(true);
}

void EmployeesTab::openPopup()
{
    this->parentWidget()->parentWidget()->setDisabled(true);
    m_addEmployeePopup.open();
}

void EmployeesTab::closePopup()
{
    this->parentWidget()->parentWidget()->setDisabled(false);
}