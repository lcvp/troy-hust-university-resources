#ifndef LQUEUE_H
#define LQUEUE_H

class LQueue
{
    class node
    {
    public:
        int item;
        node *next;
        node() : next(0) {}
        node(int value) : item(value), next(0) {}
    };

    node *front;
    node *back;

public:
    LQueue();
    ~LQueue();
    LQueue(LQueue &);

    // Queue functions
    void enqueue(int);
    void dequeue();
    int getFront();
    bool isEmpty();
};
#endif