#pragma once

class BST
{
    class bstNode
    {
    public:
        bstNode *lchild;
        int value;
        bstNode *rchild;

        bstNode(int item) : lchild(0), value(item), rchild(0) {}
        bstNode() : lchild(0), rchild(0) {}
    };
    bstNode *root;
    void destroy(bstNode *);
    bstNode *copyNode(bstNode *);
    void helpDisplay(bstNode *);
    bstNode *findInsert(bstNode *, int);
    bstNode *helpDel(bstNode *, int);
    bstNode *findNode(bstNode *, int);
    bstNode *MirrorImage(bstNode *);
    int Size(bstNode *);
    int level(bstNode*, int);
    int height(bstNode*);
    int leafCount(bstNode*);
    bool isBST(bstNode*, int&);

public:
    BST();
    ~BST();
    BST(BST &);

    void insert(int);
    void erase(int);
    bool search(int);
    void display();
    void displayMirror();
    bool isEmpty();
    void countNode();
    void findLevelVal(int);
    void nonReLevelVal(int);
    void showHeight();
    void countLeaf();
    void checkBST();
};