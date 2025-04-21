#include "AddEmployeePopup.h"

AddEmployeePopup::AddEmployeePopup(std::vector<Employee> &employees, QWidget *parent)
    : QDialog(parent), m_employees(employees)
{

    m_layout.addWidget(&m_nameInput);
    m_layout.addWidget(&m_surnameInput);
    m_layout.addWidget(&m_facilitiesInput);
    setLayout(&m_layout);
};

void AddEmployeePopup::open()
{
    show();
}
