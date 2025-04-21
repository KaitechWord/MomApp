#pragma once

#include "Employee.h"

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QHBoxLayout>

class AddEmployeePopup : public QDialog
{
public:
    AddEmployeePopup(std::vector<Employee> &employees, QWidget *parent = nullptr);

private:
    QLineEdit m_nameInput;
    QLineEdit m_surnameInput;
    QComboBox m_facilitiesInput;
    std::vector<Employee> &m_employees;
    QHBoxLayout m_layout;

public slots:
    void open();
};