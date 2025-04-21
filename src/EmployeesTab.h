#pragma once

#include "AddEmployeePopup.h"
#include "Employee.h"

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QCalendarWidget>
#include <QPushButton>

class EmployeesTab : public QWidget
{
    Q_OBJECT

public:
    EmployeesTab(QWidget *parent = nullptr);

private:
    std::vector<Employee> m_employees;
    QHBoxLayout m_tabLayout;
    QVBoxLayout m_employeeLayout;
    QVBoxLayout m_employeeDataLayout;
    QVBoxLayout m_addEmployeeLayout;
    QCalendarWidget m_calendar;
    QComboBox m_employeesBox;
    QLabel m_fullNameLabel;
    QLabel m_facilityLabel;
    QPushButton m_addEmployeeButton;
    AddEmployeePopup m_addEmployeePopup;
    Employee *m_activeEmployee;

private slots:
    void setActiveEmployee(int index);
    void openPopup();
    void closePopup();
};