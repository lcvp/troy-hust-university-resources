#ifndef LLIST_H
#define LLIST_H

class LList
{
    class node
    {
    public:
        int value;
        node *next;
        node() : next(0) {}
        node(int item) : value(item), next(0) {}
    };
    node *first;
    int size;
    node *index2ptr(int);

public:
    LList();
    LList(LList &);
    ~LList();

    bool isEmpty();
    void insertItem(int, int);
    void deleteByIndex(int);
    void insertItemAtEnd(int);
    void deleteItem(int);
    void displayList();
    bool searchItem(int);
};

#endif