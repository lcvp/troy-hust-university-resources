#ifndef ALIST_H
#define ALIST_H

class Alist
{
private:
    int *A;
    int capacity;
    int size;

public:
    Alist();
    Alist(int);
    Alist(Alist &);
    ~Alist();
    void insertItem(int, int);
    void delteItem(int);
    void displayList();
    int searchItem(int);
};

#endif