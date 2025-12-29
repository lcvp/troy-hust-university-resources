#include <iostream>
#include "LList.h"
using namespace std;

LList::node *LList::index2ptr(int pos)
{
    node *temp = first;
    while (--pos)
        temp = temp->next;
    return temp;
}

LList::LList() : first(0), size(0) {}

LList::~LList()
{
    node *temp = first;
    while (first)
    {
        temp = first->next;
        delete first;
        first = temp;
    }
}

LList::LList(LList &RHS)
{
    if (!RHS.isEmpty())
    {
        first = new node(RHS.first->value);
        node *iterator = RHS.first;
        node *follower = first;
        while (iterator->next)
        {
            follower->next = new node(iterator->next->value);
            iterator = iterator->next;
            follower = follower->next;
        }
        size = RHS.size;
    }
    else
    {
        first = 0;
        size = 0;
    }
}

bool LList::isEmpty() { return first == 0; }

void LList::insertItem(int item, int pos)
{
    if (pos >= 0 && pos <= size)
    {
        node *newnode = new node(item);
        if (pos == 0)
        {
            newnode->next = first;
            first = newnode;
        }
        else
        {
            node *insertPos = index2ptr(pos);
            newnode->next = insertPos->next;
            insertPos->next = newnode;
        }
        size++;
    }
    else
        cout << "Invalid position \n";
}

void LList::deleteByIndex(int pos)
{
    if (pos >= 0 && pos < size)
    {
        node *nodeToBeDeleted;
        if (pos == 0)
        {
            nodeToBeDeleted = first;
            first = first->next;
        }
        else
        {
            node *deletePos = index2ptr(pos);
            nodeToBeDeleted = deletePos->next;
            deletePos->next = nodeToBeDeleted->next;
        }
        delete nodeToBeDeleted;
        size--;
    }
    else
        cout << "Invalid position \n";
}

void LList::insertItemAtEnd(int item)
{
    if (isEmpty())
        first = new node(item);
    else
    {
        node *temp = first;
        while (temp->next != 0)
            temp = temp->next;
        temp->next = new node(item);
    }
    size++;
}

void LList::deleteItem(int item)
{
    if (isEmpty())
    {
        cout << "Item not found \n";
        return;
    }

    if (first->value == item)
    {
        node *todelete = first;
        first = first->next;
        delete todelete;
        size--;
        return;
    }

    node *cur = first;

    while (cur->next != 0 && cur->next->value != item)
        cur = cur->next;

    if (cur->next != 0)
    {
        node *temp = cur->next;
        cur->next = temp->next;
        delete temp;
        size--;
    }
    else
        cout << "Item not found \n";
}

void LList::displayList()
{
    cout << "Size: " << size << endl;
    cout << "Items in the list \n";
    node *temp = first;
    while (temp)
    {
        cout << temp->value << ", ";
        temp = temp->next;
    }
}

bool LList::searchItem(int item)
{
    node *temp = first;
    if (isEmpty())
    {
        return 0;
    }
    while (temp->value != item)
    {
        temp = temp->next;
        if (temp == 0)
        {
            break;
        }
    }
    return (temp != 0);
}