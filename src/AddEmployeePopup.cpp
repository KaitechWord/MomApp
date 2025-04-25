#include "AddEmployeePopup.h"

AddEmployeePopup::AddEmployeePopup(std::vector<Employee> &employees, QComboBox &employeesBox, QWidget *parent)
    : QDialog(parent), m_employees(employees), m_employeesBox(employeesBox)
{
    connect(&m_createEmployeeButton, &QPushButton::released, this, &AddEmployeePopup::addEmployee);
    m_createEmployeeButton.setText("Create");
    m_layout.addWidget(&m_nameInput);
    m_layout.addWidget(&m_surnameInput);
    m_layout.addWidget(&m_facilitiesInput);
    m_layout.addWidget(&m_createEmployeeButton);
    setLayout(&m_layout);
};

void AddEmployeePopup::open()
{
    show();
    setEnabled(true);
}

void AddEmployeePopup::addEmployee()
{
    if (!m_nameInput.isModified())
    {
        return;
    }
    if (!m_surnameInput.isModified())
    {
        return;
    }
    m_employees.emplace_back(m_nameInput.text(), m_surnameInput.text(), m_facilitiesInput.currentText());
    m_employeesBox.addItem(m_employees.back().getFullName());
    // TODO: add checking for facility
}
