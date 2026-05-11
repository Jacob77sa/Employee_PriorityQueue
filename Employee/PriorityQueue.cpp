#include <utility>
#include <stdexcept>
#include "PriorityQueue.h"

// Allocates dynamic array for heap storage
PriorityQueue::PriorityQueue(int cap) : Data(nullptr), Capacity(cap), size(0)
{
    Data = new Employee * [Capacity];
}
// Destructor: deletes all Employee objects still inside the queue, then deletes the array itself
PriorityQueue::~PriorityQueue() {
    for (int i = 0; i < size; i++) {
        delete Data[i];
    }
    delete[] Data;
}

bool PriorityQueue::isEmpty() const { return size == 0; }
bool PriorityQueue::isFull() const { return size == Capacity; }
int  PriorityQueue::getSize() const { return size; }

// Heap index calculations
int PriorityQueue::Parent(int index) const { return (index - 1) / 2; }
int PriorityQueue::LeftChild(int index) const { return 2 * index + 1; }
int PriorityQueue::RightChild(int index) const { return 2 * index + 2; }

// Moves element at 'index' upward until heap property is restored
void PriorityQueue::siftUp(int index)
{
    while (index > 0) {
        int p = Parent(index);
        // Compare by total salary (priority)
        if (Data[p]->calcSalary() < Data[index]->calcSalary()) {
            std::swap(Data[p], Data[index]);
            index = p;
        }
        else break;
    }
}
// Moves element at 'index' downward until heap property is restored
void PriorityQueue::siftDown(int index)
{
    while (true) {
        int Left = LeftChild(index);
        int Right = RightChild(index);
        int Largest = index;

        // Find the child with larger salary priority
        if (Left < size && Data[Left]->calcSalary() > Data[Largest]->calcSalary())
            Largest = Left;
        if (Right < size && Data[Right]->calcSalary() > Data[Largest]->calcSalary())
            Largest = Right;
        // If a child is larger, swap and continue
        if (Largest != index) {
            std::swap(Data[index], Data[Largest]);
            index = Largest;
        }
        else break;
    }
}
// Inserts new element and restores heap property
void PriorityQueue::insert(Employee* E)
{
    if (isFull())
        throw std::runtime_error("PriorityQueue is full - cannot insert new employee");

    Data[size] = E; // Place at the end
    siftUp(size);   // Restore heap property
    size++;         // Increase size
}
// Returns max element 
Employee* PriorityQueue::peekMax() const
{
    if (isEmpty()) return nullptr;
    return Data[0];
}
// Removes max element, restores heap, returns removed pointer.
Employee* PriorityQueue::extractMax()
{
    if (isEmpty()) return nullptr;

    Employee* maxEmp = Data[0];   // Store max element
    Data[0] = Data[size - 1];     // Move last to root
    size--;                       // Shrink heap
    if (!isEmpty()) siftDown(0);  // Restore heap property
    return maxEmp;                // Return removed element (not deleted here!)
}

// Prints elements in heap array order
// Each employee prints their own role + fields polymorphically
void PriorityQueue::print(std::ostream& os) const
{
    for (int i = 0; i < size; ++i) {
        os << "\n[" << (i + 1) << "] ";
        Data[i]->print(os);
        os << '\n';
    }
}