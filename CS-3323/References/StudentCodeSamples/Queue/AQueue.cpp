#include <iostream>
#include "AQueue.h"
using namespace std;

AQueue::AQueue() : CAPACITY(10), front(0), back(0)
{
    A = new int[CAPACITY];
}

AQueue::AQueue(int cap) : front(0), back(0), CAPACITY(cap)
{
    A = new int[CAPACITY];
}

AQueue::~AQueue()
{
    delete[] A;
}

AQueue::AQueue(AQueue &RHS)
{
    CAPACITY = RHS.CAPACITY;
    A = new int[CAPACITY];
    front = RHS.front;
    back = RHS.back;

    int n = RHS.size();
    for (int k = 0; k < n; k++)
    {
        int i = (front + k) % CAPACITY;
        A[i] = RHS.A[i];
    }
}

bool AQueue::isEmpty() { return front == back; }
bool AQueue::isFull() { return ((back + 1) % CAPACITY == front); }

void AQueue::enqueue(int item)
{
    if (!isFull())
    {
        A[back] = item;
        back = (back + 1) % CAPACITY;
    }
    else
        cout << "Queue is Full \n";
}

void AQueue::dequeue()
{
    if (!isEmpty())
        front = (front + 1) % CAPACITY;
    else
        cout << "Queue is Empty \n";
}

int AQueue::qFront()
{
    if (!isEmpty())
        return A[front];
    else
    {
        cout << "Queue is empty";
        return -9999;
    }
}

int AQueue::size()
{
    return (front <= back ? (back - front) : (CAPACITY - front + back));
}