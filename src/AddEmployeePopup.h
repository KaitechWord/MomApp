#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>

class AddEmployeePopup : public QDialog
{
    AddEmployeePopup(QWidget *parent = nullptr);
private:
    QLineEdit m_nameInput;
    QLineEdit m_surnameInput;
    QComboBox m_facilitiesInput;
};