#pragma once

#include <chrono>

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QCalendarWidget>
#include <QPushButton>

// Move that to some facility class or tab
namespace Facility
{
    enum class Shift
    {
        No,
        Morning,
        Afternoon,
        Evening,
        Every
    };
}

struct ShiftDay
{
    std::chrono::year_month_day day;
    Facility::Shift shift;
};

struct Employee
{
    QString name;
    QString surname;
    QString facility;
    std::vector<ShiftDay> requestedShifts;
    std::vector<ShiftDay> shiftsOff;
    QString getFullName() const { return surname + " " + name; };
};

class EmployeesTab : public QWidget
{
    Q_OBJECT

public:
    EmployeesTab(QWidget *parent = nullptr);

private:
    QHBoxLayout m_tabLayout;
    QVBoxLayout m_employeeLayout;
    QVBoxLayout m_employeeDataLayout;
    QVBoxLayout m_addEmployeeLayout;
    QCalendarWidget m_calendar;
    QComboBox m_employeesBox;
    QLabel m_fullNameLabel;
    QLabel m_facilityLabel;
    QPushButton m_addEmployeeButton;
    Employee *m_activeEmployee;
    std::vector<Employee> m_employees;

private slots:
    void setActiveEmployee(int index);
};