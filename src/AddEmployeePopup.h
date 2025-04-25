#pragma once

#include "Employee.h"

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QHBoxLayout>
#include <QPushButton>

class AddEmployeePopup : public QDialog
{
public:
    AddEmployeePopup(std::vector<Employee> &employees, QComboBox &employeesBox, QWidget *parent = nullptr);

private:
    QLineEdit m_nameInput;
    QLineEdit m_surnameInput;
    QComboBox m_facilitiesInput;
    QPushButton m_createEmployeeButton;
    std::vector<Employee> &m_employees;
    QComboBox &m_employeesBox;
    QHBoxLayout m_layout;

public slots:
    void open();
private slots:
    void addEmployee();
};