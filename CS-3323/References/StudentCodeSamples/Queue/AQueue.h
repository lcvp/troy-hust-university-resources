#ifndef AQUEUE_H
#define AQUEUE_H

class AQueue
{
private:
    int CAPACITY;
    int *A;
    int front, back;

public:
    AQueue();
    AQueue(int);
    ~AQueue();
    AQueue(AQueue &);

    bool isEmpty();
    bool isFull();
    void enqueue(int);
    void dequeue();
    int qFront();
    int size();
};

#endif