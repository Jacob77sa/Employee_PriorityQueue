#include "Employee.h"

// Converts QualificationLevel enum to a human-readable string
std::string QualificationToString(QualificationLevel level)
{
    switch (level)
    {
    case QualificationLevel::Junior: return "Junior";
    case QualificationLevel::Middle: return "Middle";
    case QualificationLevel::Senior: return "Senior";
    }
    return ""; // Fallback (should never happen)
}
// Converts DevTech enum to a human-readable string
std::string DevTechToString(DevTech tech)
{
    switch (tech)
    {
    case DevTech::DotNet:  return ".Net";
    case DevTech::Spring:  return "Spring";
    case DevTech::Django:  return "Django";
    case DevTech::Angular: return "Angular";
    case DevTech::React:   return "React";
    case DevTech::Vue:     return "Vue";
    }
    return ""; // Fallback (should never happen)
}
// Base constructor initializes common employee fields
Employee::Employee(const std::string& n, int id, const std::string& cls, int tenure, double Base)
         : name(n), empID(id), empClass(cls), tenureMonths(tenure), BaseSalary(Base) {}
// Virtual destructor (needed for polymorphic deletion)
Employee::~Employee() {}
// Prints common employee information.
void Employee::print(std::ostream& os) const {
    os << "Name: " << name
        << " | ID: " << empID
        << " | Class: " << empClass
        << " | Tenure(months): " << tenureMonths
        << " | Base salary: " << BaseSalary
        << " | Total salary: " << calcSalary();
}
// overloaded << operator
std::ostream& operator<<(std::ostream& os, const Employee& E) {
    E.print(os);
    return os;
}