#include <iostream>
#include <string>
#include <random>
#include <ctime>

#include "PriorityQueue.h"
#include "WorkerClasses.h"

int main() {
    PriorityQueue Q(70);  // Priority queue that will store 70 employees (7 roles * 10 objects each)
    int nextID = 1;       // Auto-incrementing employee ID generator

    // Pool of random names used for generating employees
    const std::string names[20] = {"Nika","Giorgi","Mariam","Ana","Luka","Saba","Nino","Dato","Salome","Irakli",
                                   "Tamar","Elene","Beka","Keti","Zurab","Khatia","Levan","Tinatin","Ilia","Giga" };

    // Random engine seeded for different results each run in [0;19] Range
    std::default_random_engine dre((unsigned)time(NULL));
    std::uniform_int_distribution<int> dis(0, 19);

    // Create and insert 10 CIO employees
    for (int i = 0; i < 10; ++i) {
        Q.insert(new CIO(names[dis(dre)], nextID++, 12 + 3 * i));
    }

    // Create and insert 10 Project Managers
    for (int i = 0; i < 10; ++i) {
        Q.insert(new ProjectManager(names[dis(dre)], nextID++, 12 + 2 * i));
    }

    // Create and insert 10 Backend Developers
    for (int i = 0; i < 10; ++i)
    {
        // Choose qualification level based on i
        QualificationLevel lvl;
        if (i % 3 == 0) lvl = QualificationLevel::Junior;
        else if (i % 3 == 1) lvl = QualificationLevel::Middle;
        else lvl = QualificationLevel::Senior;

        // Choose backend tech based on i 
        DevTech tech;
        if (i % 3 == 0) tech = DevTech::DotNet;
        else if (i % 3 == 1) tech = DevTech::Spring;
        else tech = DevTech::Django;

        Q.insert(new BackendDeveloper(names[dis(dre)], nextID++, 6 + 2 * i, lvl, tech));
    }

    // Create and insert 10 Frontend Developers
    for (int i = 0; i < 10; ++i)
    {
        QualificationLevel lvl;
        if (i % 3 == 0) lvl = QualificationLevel::Junior;
        else if (i % 3 == 1) lvl = QualificationLevel::Middle;
        else lvl = QualificationLevel::Senior;

        // Choose frontend tech
        DevTech tech;
        if (i % 3 == 0) tech = DevTech::Angular;
        else if (i % 3 == 1) tech = DevTech::React;
        else tech = DevTech::Vue;

        Q.insert(new FrontendDeveloper(names[dis(dre)], nextID++, 6 + 2 * i, lvl, tech));
    }

    // Create and insert 10 Database Engineers
    for (int i = 0; i < 10; ++i)
    {
        QualificationLevel lvl;
        if (i % 3 == 0) lvl = QualificationLevel::Junior;
        else if (i % 3 == 1) lvl = QualificationLevel::Middle;
        else lvl = QualificationLevel::Senior;

        Q.insert(new DataBaseEngineer(names[dis(dre)], nextID++, 6 + 4 * i, lvl));
    }

    // Create and insert 10 DevOps Engineers
    for (int i = 0; i < 10; ++i)
    {
        QualificationLevel lvl;
        if (i % 3 == 0) lvl = QualificationLevel::Junior;
        else if (i % 3 == 1) lvl = QualificationLevel::Middle;
        else lvl = QualificationLevel::Senior;

        Q.insert(new DevOpsEngineer(names[dis(dre)], nextID++, 6 + 4 * i, lvl));
    }

    // Create and insert 10 Testers
    for (int i = 0; i < 10; ++i)
    {
        QualificationLevel lvl;
        if (i % 3 == 0) lvl = QualificationLevel::Junior;
        else if (i % 3 == 1) lvl = QualificationLevel::Middle;
        else lvl = QualificationLevel::Senior;

        Q.insert(new Tester(names[dis(dre)], nextID++, 6 + 3 * i, lvl));
    }

    // Print queue size and the heap content in heap order
    std::cout << "\nTotal employees in priority queue: " << Q.getSize() << "\n\n";
    Q.print(std::cout);

    // Test peekMax()
    if (!Q.isEmpty()) {
        std::cout << "\n\nHighest paid employee (peekMax):\n";
        Q.peekMax()->print(std::cout);
    }

    // Test extractMax(): remove top 5 highest paid employees
    std::cout << "\n\nTop 5 employees by salary (extractMax):\n";
    for (int i = 0; i < 5 && !Q.isEmpty(); ++i) {
        Employee* E = Q.extractMax();
        std::cout << i + 1 << ") ";
        E->print(std::cout);
        std::cout << "\n";
        delete E; // prevent memory leak for removed employees
    }

    // Print queue again after removals
    std::cout << "\n\nQueue size after removing top 5: " << Q.getSize() << "\n\n";
    Q.print(std::cout);
    std::cout << "\n";

    // Test isFull()
    std::cout << "Is Queue Full? " << (Q.isFull() ? "YES" : "NO") << "\n";
}