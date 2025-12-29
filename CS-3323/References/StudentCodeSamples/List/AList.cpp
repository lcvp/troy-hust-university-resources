#include "AList.h"
#include <iostream>
using namespace std;

Alist::Alist() : capacity(10), size(0)
{
    A = new int[capacity];
}

Alist::Alist(int CAPACITY) : capacity(CAPACITY), size(0)
{
    if (capacity <= 0) capacity = 10;
    A = new int[capacity];
}

Alist::Alist(Alist &RHS) : capacity(RHS.capacity), size(RHS.size)
{
    A = new int[capacity];
    for (int i = 0; i < size; i++)
        A[i] = RHS.A[i];
}

Alist::~Alist()
{
    delete[] A;
    A = nullptr;
}

void Alist::insertItem(int pos, int item)
{
    if (pos < 0 || pos > size)
    {
        cout << "[insertItem] Not valid\n";
        return;
    }

    if (size == capacity)
    {
        int newCap = capacity * 2;
        int *newA = new int[newCap];
        for (int i = 0; i < size; i++) newA[i] = A[i];
        delete[] A;
        A = newA;
        capacity = newCap;
    }

    for (int i = size; i > pos; i--)
        A[i] = A[i - 1];

    A[pos] = item;
    size++;
}

void Alist::delteItem(int pos)
{
    if (size == 0)
    {
        cout << "[delteItem] List is empty\n";
        return;
    }
    if (pos < 0 || pos >= size)
    {
        cout << "[delteItem] Not valid\n";
        return;
    }

    for (int i = pos; i < size - 1; i++)
        A[i] = A[i + 1];

    size--;
}

int Alist::searchItem(int item)
{
    for (int i = 0; i < size; i++)
        if (A[i] == item) return i;
    return -1;
}

void Alist::displayList()
{
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        cout << A[i];
        if (i != size - 1) cout << ", ";
    }
    cout << " }";
}