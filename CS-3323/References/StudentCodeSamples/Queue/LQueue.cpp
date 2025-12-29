#include <iostream>
#include "LQueue.h"
using namespace std;

LQueue::LQueue() : front(0), back(0) {}

LQueue::~LQueue()
{
    node *temp = front;
    while (front)
    {
        temp = front->next;
        delete front;
        front = temp;
    }
}

LQueue::LQueue(LQueue &RHS)
{
    cout << "copy constructor is called\n";
    if (!RHS.isEmpty())
    {
        front = new node(RHS.front->item);
        node *iterator = RHS.front;
        back = front;
        while (iterator->next)
        {
            back->next = new node(iterator->next->item);
            iterator = iterator->next;
            back = back->next;
        }
    }
    else
    {
        front = back = 0;
    }
}

void LQueue::enqueue(int item)
{
    node *newnode = new node(item);
    if (front == 0)
    {
        front = newnode;
        back = front;
    }
    else
    {
        back->next = newnode;
        back = newnode;
    }
}

void LQueue::dequeue()
{
    if (front == back)
    {
        if (front == 0)
            cout << " queue is empty\n";
        else
        {
            delete front;
            front = 0;
            back = 0;
        }
    }
    else
    {
        node *temp = front;
        front = front->next;
        delete temp;
    }
}

int LQueue::getFront()
{
    if (front != 0)
        return front->item;
    else
    {
        cout << "Queue is empty\n";
        return -9999;
    }
}

bool LQueue::isEmpty() { return front == 0; }