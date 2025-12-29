#include <iostream>
#include "LStack.h"
using namespace std;

LStack::LStack() : myTop(0) {}

LStack::~LStack()
{
    node *temp = myTop;
    while (myTop)
    {
        temp = myTop->next;
        delete myTop;
        myTop = temp;
    }
}

LStack::LStack(LStack &RHS)
{
    if (!RHS.isEmpty())
    {
        myTop = new node(RHS.myTop->value);
        node *iterator = RHS.myTop;
        node *follower = myTop;
        while (iterator->next)
        {
            follower->next = new node(iterator->next->value);
            iterator = iterator->next;
            follower = follower->next;
        }
    }
    else
        myTop = 0;
}

bool LStack::isEmpty() { return myTop == 0; }

void LStack::push(int item)
{
    if (!isEmpty())
    {
        node *newNode = new node(item);
        newNode->next = myTop;
        myTop = newNode;
    }
    else
        myTop = new node(item);
}

void LStack::pop()
{
    if (!isEmpty())
    {
        node *temp = myTop;
        myTop = myTop->next;
        delete temp;
    }
    else
        cout << "Nothing to delete \n";
}

int LStack::top()
{
    if (!isEmpty())
        return myTop->value;
    else
        cout << "Stack is Empty \n";
    return -9999;
}