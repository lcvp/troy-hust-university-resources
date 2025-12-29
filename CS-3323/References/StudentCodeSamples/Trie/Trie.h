#pragma once
#include <string>
using namespace std;

const int NUM_ALPHA = 26;
class Trie
{
    class tnode
    {
    public:
        tnode *child[NUM_ALPHA];
        int prefix;
        bool isword;
        tnode() : prefix(0), isword(false)
        {
            for (int i = 0; i < NUM_ALPHA; i++)
            {
                child[i] = 0;
            }
        }
    };
    tnode *root;
    void helpDes(tnode *);
    void helpDisplay(int, tnode *, int);

public:
    Trie();
    ~Trie();

    bool search(string);
    void insert(string);
    void display();
};