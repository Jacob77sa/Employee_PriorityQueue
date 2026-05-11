#pragma once
#include <iostream>
#include <string>

// Qualification level used by Developer / Engineer / Tester roles
enum class QualificationLevel { Junior, Middle, Senior };
// Technologies used only by Developers (Backend/Frontend)
enum class DevTech { DotNet, Spring, Django, Angular, React, Vue };

// Converts enum values to readable strings for printing
std::string QualificationToString(QualificationLevel level);
std::string DevTechToString(DevTech tech);

// Abstract base class that represents any employee in the company.
class Employee
{
protected:
    std::string name;      // Employee full name
    int empID;             // Unique employee identifier
    std::string empClass;  // Class code (CIO, PM, BD, FD, DB, DE, TST)
    int tenureMonths;      // Tenure in the company (in months)
    double BaseSalary;     // Base salary before bonuses (varies by role/level/tech)

public:
    // Constructs an employee with all common fields.
    Employee(const std::string& n, int id, const std::string& cls, int tenure, double Base);
    // Virtual destructor is required because we delete through Employee* pointers.
    virtual ~Employee();
    // Calculates total salary for the employee (base + bonuses).
    virtual double calcSalary() const = 0;  // Pure virtual => Employee is abstract; each derived role must implement it.
    // Prints common employee info (derived classes can extend it).
    virtual void print(std::ostream& os) const;
};
// overaloaded << operator
std::ostream& operator<<(std::ostream& os, const Employee& E);