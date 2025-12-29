#ifndef ASTACK_H
#define ASTACK_H
class AStack
{
    int *A;
    int CAPACITY;
    int myTop;

public:
    AStack(int);
    ~AStack();
    AStack(AStack &);
    void push(int);
    void pop();
    int top();
    bool isEmpty();
    bool isFull();
};
#endif