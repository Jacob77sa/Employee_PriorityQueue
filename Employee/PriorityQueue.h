#pragma once
#include <iostream>
#include "Employee.h"

// Max-heap Priority Queue where priority is Employee salary.
class PriorityQueue
{
private:
    Employee** Data;   // Dynamic array of pointers to Employee objects (heap storage)
    int Capacity;      // Maximum number of employees the queue can store
    int size;          // Current number of employees in the heap

    // Restores heap property after insertion
    void siftUp(int index);
    // Restores heap property after deletion
    void siftDown(int index);
    // Index helpers for binary heap
    int Parent(int index) const;
    int LeftChild(int index) const;
    int RightChild(int index) const;

public:
    
    PriorityQueue(int cap = 100);// Creates a priority queue with given capacity (default 100)
    ~PriorityQueue();            // Deletes remaining employees still stored in the queue and frees array memory
    bool isEmpty() const;        // Returns true if there are no employees in the queue
    bool isFull() const;         // Returns true if the queue has reached its capacity
    int getSize() const;         // Returns current number of employees
    void insert(Employee* E);    // Inserts an employee pointer into the heap
    Employee* peekMax() const;   // Returns the highest paid employee
    Employee* extractMax();      // Removes and returns the highest paid employee
    void print(std::ostream& os) const;   // Prints all employees currently stored in heap order
};