#pragma once
#include "Employee.h"

// CIO role
class CIO : public Employee
{
public:
    CIO(const std::string& n, int id, int tenure);
    double calcSalary() const override;  // Salary calculation for CIO 
    void print(std::ostream& os) const override; // Prints role name + base fields
};

// Project Manager role
class ProjectManager : public Employee
{
public:
    ProjectManager(const std::string& n, int id, int tenure);
    double calcSalary() const override;
    void print(std::ostream& os) const override;
};

// Abstract idea of "Developer" in hierarchy.
class Developer : public Employee
{
protected:
    QualificationLevel Level;  // Junior / Middle / Senior
    DevTech Technology;        // Allowed tech depends on Backend / Frontend

public:
    // Base developer constructor used by BackendDeveloper and FrontendDeveloper.
    Developer(const std::string& n, int id, const std::string& cls, int tenure, QualificationLevel lvl, DevTech tech, double base);
};

// Backend Developer: uses only (.Net, Spring, Django)
class BackendDeveloper : public Developer
{
public:
    BackendDeveloper(const std::string& n, int id, int tenure, QualificationLevel lvl, DevTech tech);
    double calcSalary() const override;
    void print(std::ostream& os) const override;
};

// Frontend Developer: uses only (Angular, React, Vue)
class FrontendDeveloper : public Developer
{
public:
    FrontendDeveloper(const std::string& n, int id, int tenure, QualificationLevel lvl, DevTech tech);
    double calcSalary() const override;
    void print(std::ostream& os) const override;
};

// Abstract idea of "Engineer" in hierarchy
class Engineer : public Employee
{
protected:
    QualificationLevel Level;  // Junior / Middle / Senior

public:
    // Base engineer constructor used by DataBaseEngineer and DevOpsEngineer.
    Engineer(const std::string& n, int id, const std::string& cls, int tenure, QualificationLevel lvl, double base);
};

// Database Engineer
class DataBaseEngineer : public Engineer
{
public:
    DataBaseEngineer(const std::string& n, int id, int tenure, QualificationLevel lvl);
    double calcSalary() const override;
    void print(std::ostream& os) const override;
};

// DevOps Engineer
class DevOpsEngineer : public Engineer
{
public:
    DevOpsEngineer(const std::string& n, int id, int tenure, QualificationLevel lvl);
    double calcSalary() const override;
    void print(std::ostream& os) const override;
};

// Tester role
class Tester : public Employee
{
    QualificationLevel Level;  // Junior / Middle / Senior

public:
    Tester(const std::string& n, int id, int tenure, QualificationLevel lvl);
    double calcSalary() const override;
    void print(std::ostream& os) const override;
};