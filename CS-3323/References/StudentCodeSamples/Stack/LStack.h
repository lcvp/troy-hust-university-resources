#ifndef LSTACK_H
#define LSTACK_H

class LStack
{
    class node
    {
    public:
        int value;
        node *next;
        node() : next(0) {}
        node(int item) : value(item), next(0) {}
    };

    node *myTop;

public:
    LStack();
    ~LStack();
    LStack(LStack &);
    bool isEmpty();
    void push(int);
    void pop();
    int top();
};
#endif