#pragma once

#include "AddEmployeePopup.h"
#include "Employee.h"

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QCalendarWidget>
#include <QPushButton>

// TODO: there is some trouble with deleting employees and ids, maybe change the AddEmployeePopup, so it doesnt take
// the references, but instead it returns the employee to be added, guess it would be better and more encapuslation friendly
// approach

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
    QPushButton m_deleteEmployeeButton;
    AddEmployeePopup m_addEmployeePopup;
    int m_activeEmployeeId{-1};

    void sortEmployees();

private slots:
    void setActiveEmployee(int index);
    void openPopup();
    void closePopup();
    void deleteEmployee();
};