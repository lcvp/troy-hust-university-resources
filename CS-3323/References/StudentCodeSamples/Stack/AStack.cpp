#include <iostream>
#include "AStack.h"
using namespace std;

AStack::AStack(int Cap) : CAPACITY(Cap), myTop(-1)
{
    A = new int[Cap];
}

AStack::~AStack()
{
    delete[] A;
}

AStack::AStack(AStack &S)
{
    A = new int[S.CAPACITY];
    CAPACITY = S.CAPACITY;
    myTop = -1;
    for (; ++myTop <= S.myTop;)
        A[myTop] = S.A[myTop];
    myTop--;
}

void AStack::push(int item)
{
    if (!isFull())
        A[++myTop] = item;
    else
        cout << "Stack is full\n";
}

void AStack::pop()
{
    if (!isEmpty())
        myTop--;
    else
        cout << "Stack is empty \n";
}

int AStack::top()
{
    if (!isEmpty())
        return A[myTop];
    else
    {
        cout << "Stack is empty \n";
        return -9999;
    }
}

bool AStack::isEmpty() { return myTop == -1; }
bool AStack::isFull() { return CAPACITY == (myTop + 1); }