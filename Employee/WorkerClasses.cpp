#include <stdexcept>
#include "WorkerClasses.h"

// -------------------- CIO --------------------

CIO::CIO(const std::string& n, int id, int tenure)
    : Employee(n, id, "CIO", tenure, 10000.0) {
}
// CIO salary: base + prorated yearly bonus (depends on tenure)
double CIO::calcSalary() const {
    double YearlyBonus = 1200.0 * (tenureMonths / 12.0);
    return BaseSalary + YearlyBonus;
}
void CIO::print(std::ostream& os) const {
    os << "[CIO]\n";
    Employee::print(os);
}

// -------------------- Project Manager --------------------

ProjectManager::ProjectManager(const std::string& n, int id, int tenure)
    : Employee(n, id, "PM", tenure, 7000.0) {
}
// PM salary: base + prorated yearly bonus
double ProjectManager::calcSalary() const {
    double YearlyBonus = 1080.0 * (tenureMonths / 12.0);
    return BaseSalary + YearlyBonus;
}
void ProjectManager::print(std::ostream& os) const {
    os << "[Project Manager]\n";
    Employee::print(os);
}

// -------------------- Developer base class --------------------

Developer::Developer(const std::string& n, int id, const std::string& cls, int tenure, QualificationLevel lvl, DevTech tech, double Base)
          : Employee(n, id, cls, tenure, Base), Level(lvl), Technology(tech) {}

// -------------------- Backend Developer --------------------

BackendDeveloper::BackendDeveloper(const std::string& n, int id, int tenure, QualificationLevel lvl, DevTech tech)
                 : Developer(n, id, "BD", tenure, lvl, tech, 0.0)
{
    // Validate: backend developer is allowed only these technologies
    if (!(tech == DevTech::DotNet || tech == DevTech::Spring || tech == DevTech::Django)) {
        throw std::invalid_argument(
            "ERROR: BackendDeveloper can use only (.Net, Spring, Django). Given: " + DevTechToString(tech));
    }
    // Base salary depends on qualification level
    double Base = (lvl == QualificationLevel::Junior) ? 4000.0 :
                  (lvl == QualificationLevel::Middle) ? 5500.0 : 7000.0;
    // Extra salary depends on specific backend technology
    if (tech == DevTech::DotNet) Base += 150.0;
    else if (tech == DevTech::Spring) Base += 300.0;
    else if (tech == DevTech::Django) Base += 200.0;
    // Store computed base salary into Employee field
    BaseSalary = Base;
}
// Backend developer salary: base + prorated yearly bonus
double BackendDeveloper::calcSalary() const {
    double YearlyBonus = 840.0 * (tenureMonths / 12.0);
    return BaseSalary + YearlyBonus;
}
void BackendDeveloper::print(std::ostream& os) const {
    os << "[Backend Dev]\n";
    Employee::print(os);
    os << " | Level: " << QualificationToString(Level)
       << " | Tech: " << DevTechToString(Technology);
}

// -------------------- Frontend Developer --------------------

FrontendDeveloper::FrontendDeveloper(const std::string& n, int id, int tenure, QualificationLevel lvl, DevTech tech)
                  : Developer(n, id, "FD", tenure, lvl, tech, 0.0)
{
    // Validate: frontend developer is allowed only these technologies
    if (!(tech == DevTech::Angular || tech == DevTech::React || tech == DevTech::Vue)) {
        throw std::invalid_argument(
            "ERROR: FrontendDeveloper can use only (Angular, React, Vue). Given: " + DevTechToString(tech));
    }
    // Base salary depends on qualification level
    double Base = (lvl == QualificationLevel::Junior) ? 3800.0 :
                  (lvl == QualificationLevel::Middle) ? 5200.0 : 6600.0;
    // Extra salary depends on specific frontend technology
    if (tech == DevTech::Angular) Base += 150.0;
    else if (tech == DevTech::React) Base += 250.0;
    else if (tech == DevTech::Vue) Base += 180.0;

    BaseSalary = Base;
}
double FrontendDeveloper::calcSalary() const {
    double YearlyBonus = 780.0 * (tenureMonths / 12.0);
    return BaseSalary + YearlyBonus;
}
void FrontendDeveloper::print(std::ostream& os) const {
    os << "[Frontend Dev]\n";
    Employee::print(os);
    os << " | Level: " << QualificationToString(Level)
       << " | Tech: " << DevTechToString(Technology);
}

// -------------------- Engineer base class --------------------

Engineer::Engineer(const std::string& n, int id, const std::string& cls, int tenure, QualificationLevel lvl, double Base)
         : Employee(n, id, cls, tenure, Base), Level(lvl) {}

// -------------------- Database Engineer --------------------

DataBaseEngineer::DataBaseEngineer(const std::string& n, int id, int tenure, QualificationLevel lvl)
                 : Engineer(n, id, "DB", tenure, lvl, 0.0)
{
    // Base salary depends on qualification level
    double Base = (lvl == QualificationLevel::Junior) ? 4500.0 :
                  (lvl == QualificationLevel::Middle) ? 6000.0 : 7500.0;

    BaseSalary = Base;
}
double DataBaseEngineer::calcSalary() const {
    double YearlyBonus = 960.0 * (tenureMonths / 12.0);
    return BaseSalary + YearlyBonus;
}
void DataBaseEngineer::print(std::ostream& os) const {
    os << "[DB Engineer]\n";
    Employee::print(os);
    os << " | Level: " << QualificationToString(Level);
}

// -------------------- DevOps Engineer --------------------

DevOpsEngineer::DevOpsEngineer(const std::string& n, int id, int tenure, QualificationLevel lvl)
               : Engineer(n, id, "DE", tenure, lvl, 0.0)
{
    // Base salary depends on qualification level
    double Base = (lvl == QualificationLevel::Junior) ? 4600.0 :
        (lvl == QualificationLevel::Middle) ? 6200.0 : 7800.0;

    BaseSalary = Base;
}
double DevOpsEngineer::calcSalary() const {
    double YearlyBonus = 1020.0 * (tenureMonths / 12.0);
    return BaseSalary + YearlyBonus;
}
void DevOpsEngineer::print(std::ostream& os) const {
    os << "[DevOps Engineer]\n";
    Employee::print(os);
    os << " | Level: " << QualificationToString(Level);
}

// -------------------- Tester --------------------

Tester::Tester(const std::string& n, int id, int tenure, QualificationLevel lvl)
       : Employee(n, id, "TST", tenure, 0.0), Level(lvl)
{
    // Base salary depends on qualification level
    double Base = (lvl == QualificationLevel::Junior) ? 3000.0 :
        (lvl == QualificationLevel::Middle) ? 4000.0 : 5000.0;

    BaseSalary = Base;
}
double Tester::calcSalary() const {
    double YearlyBonus = tenureMonths * 40.0; 
    return BaseSalary + YearlyBonus;
}
void Tester::print(std::ostream& os) const {
    os << "[Tester]\n";
    Employee::print(os);
    os << " | Level: " << QualificationToString(Level);
}