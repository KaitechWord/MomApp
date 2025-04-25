#include "EmployeesTab.h"

EmployeesTab::EmployeesTab(QWidget *parent) : QWidget(parent), m_tabLayout(this), m_addEmployeePopup(m_employees, m_employeesBox, this)
{
    connect(&m_employeesBox, &QComboBox::activated, this, &EmployeesTab::setActiveEmployee);
    connect(&m_addEmployeeButton, &QPushButton::clicked, this, &EmployeesTab::openPopup);
    connect(&m_deleteEmployeeButton, &QPushButton::clicked, this, &EmployeesTab::deleteEmployee);
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
    m_employeeDataLayout.addWidget(&m_deleteEmployeeButton);
    m_addEmployeeLayout.addWidget(&m_addEmployeeButton);
    m_addEmployeeButton.setText("Add new employee");
    m_deleteEmployeeButton.setText("Delete this employee");
    m_deleteEmployeeButton.setDisabled(true);
    sortEmployees();
    m_addEmployeeLayout.addWidget(&m_addEmployeePopup);
}

void EmployeesTab::sortEmployees()
{
    m_employeesBox.model()->sort(0, Qt::AscendingOrder);
    std::ranges::sort(m_employees, [](const Employee &left, const Employee &right)
                      { return left.getFullName() < right.getFullName(); });
}

void EmployeesTab::setActiveEmployee(int index)
{
    m_activeEmployeeId = index;
    const auto &activeEmployee = m_employees.at(m_activeEmployeeId);
    m_facilityLabel.setText(activeEmployee.facility);
    m_fullNameLabel.setText(activeEmployee.getFullName());
    m_deleteEmployeeButton.setDisabled(false);
}

void EmployeesTab::openPopup()
{
    parentWidget()->parentWidget()->setDisabled(true);
    m_addEmployeePopup.open();
}

void EmployeesTab::closePopup()
{
    parentWidget()->parentWidget()->setDisabled(false);
    sortEmployees();
}

void EmployeesTab::deleteEmployee()
{
    m_employees.erase(m_employees.begin() + m_activeEmployeeId);
    m_employeesBox.removeItem(m_activeEmployeeId);
    sortEmployees();
    m_employeesBox.setCurrentIndex(-1);
    m_facilityLabel.setText("");
    m_fullNameLabel.setText("");
    m_deleteEmployeeButton.setDisabled(true);
}