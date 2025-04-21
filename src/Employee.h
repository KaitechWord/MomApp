#pragma once

#include <vector>
#include <chrono>

#include <QString>

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
    QString getFullName() const { return name + " " + surname; };
};