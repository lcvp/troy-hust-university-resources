#include "BST.h"
#include <iostream>
using namespace std;

BST::BST() : root(0) {}

void BST::destroy(bstNode *node)
{
    if (node != 0)
    {
        destroy(node->lchild);
        destroy(node->rchild);
        delete node;
    }
}

BST::bstNode *BST::copyNode(bstNode *node)
{
    if (node != 0)
    {
        bstNode *newNode = new bstNode(node->value);
        newNode->lchild = copyNode(node->lchild);
        newNode->rchild = copyNode(node->rchild);
        return newNode;
    }
    else
    {
        return 0;
    }
}

void BST::helpDisplay(bstNode *node)
{
    if (node != 0)
    {
        helpDisplay(node->lchild);
        cout << " " << node->value << " ";
        helpDisplay(node->rchild);
    }
}

BST::bstNode *BST::helpDel(bstNode *node, int value)
{
    if (node == 0)
    {
        return 0;
    }
    if (value < node->value)
    {
        node->lchild = helpDel(node->lchild, value);
    }
    else if (value > node->value)
    {
        node->rchild = helpDel(node->rchild, value);
    }
    else
    {
        bstNode *temp = node->lchild ? node->lchild : node->rchild;
        if (node->lchild == 0 || node->rchild == 0)
        {
            delete node;
            return temp;
        }
        temp = node->rchild;
        while (temp->lchild != 0)
        {
            temp = temp->lchild;
        }
        node->value = temp->value;
        node->rchild = helpDel(node->rchild, temp->value);
    }
    return node;
}

int BST::level(bstNode *node, int value)
{
    if (node == 0)
    {
        return -9999;
    }
    if (value < node->value)
    {
        return 1 + level(node->lchild, value);
    }
    else if (value > node->value)
    {
        return 1 + level(node->rchild, value);
    }
    else
    {
        return 0;
    }
}

int BST::height(bstNode *node)
{
    if (node == 0)
    {
        return -1;
    }
    int lheight = 1 + height(node->lchild);
    int rheight = 1 + height(node->rchild);
    return max(lheight, rheight);
}

BST::bstNode *BST::findInsert(bstNode *node, int value)
{
    if (node->value == value)
    {
        return 0;
    }
    if (node->lchild != 0 || node->rchild != 0)
    {
        if (node->lchild != 0 && value < node->value)
        {
            return findInsert(node->lchild, value);
        }
        else if (node->rchild != 0 && value > node->value)
        {
            return findInsert(node->rchild, value);
        }
    }
    return node;
}

BST::bstNode *BST::MirrorImage(bstNode *node)
{
    if (node == 0)
        return 0;
    bstNode *temp = node->rchild;
    node->rchild = node->lchild;
    node->lchild = temp;

    MirrorImage(node->lchild);
    MirrorImage(node->rchild);
    return node;
}

int BST::Size(bstNode *node)
{
    if (node != 0)
    {
        return 1 + Size(node->lchild) + Size(node->rchild);
    }
    else
        return 0;
}

BST::bstNode *BST::findNode(bstNode *node, int value)
{
    if (node != 0)
    {
        if (node->value == value)
        {
            return node;
        }
        else
        {
            if (value < node->value)
                return findNode(node->lchild, value);
            else if (value > node->value)
                return findNode(node->rchild, value);
        }
    }
    return 0;
}

BST::~BST()
{
    destroy(root);
    root = 0;
}

BST::BST(BST &RHS)
{
    cout << "Copy constructor called";
    root = copyNode(RHS.root);
}

void BST::insert(int value)
{
    if (isEmpty())
    {
        root = new bstNode(value);
        return;
    }
    bstNode *target = findInsert(root, value);
    if (target == 0)
    {
        cout << "Duplicate value" << endl;
    }
    else
    {
        if (value < target->value)
        {
            target->lchild = new bstNode(value);
        }
        else
        {
            target->rchild = new bstNode(value);
        }
    }
}

void BST::erase(int value)
{
    root = helpDel(root, value);
}

bool BST::search(int value)
{
    return findNode(root, value) != 0;
}

void BST::display()
{
    helpDisplay(root);
}

void BST::displayMirror()
{
    root = MirrorImage(root);
    display();
    root = MirrorImage(root);
}

bool BST::isEmpty()
{
    return root == 0;
}

void BST::countNode()
{
    cout << "Number nodes: " << Size(root) << endl;
}

void BST::findLevelVal(int value)
{
    if (level(root, value) >= 0)
    {
        cout << "This val is in level: " << level(root, value) << endl;
    }
    else
    {
        cout << "This val is not exist in tree" << endl;
    }
}

void BST::nonReLevelVal(int value)
{
    if (isEmpty())
    {
        cout << "This val is not exist in tree" << endl;
        return;
    }
    int level = 0;
    bstNode *temp = root;
    while (temp != 0)
    {
        if (value < temp->value)
        {
            temp = temp->lchild;
            level++;
        }
        else if (value > temp->value)
        {
            temp = temp->rchild;
            level++;
        }
        else
        {
            break;
        }
    }
    if (temp == 0)
    {
        cout << "This val is not exist in tree" << endl;
        return;
    }
    else
    {
        cout << "This val is in level: " << level << endl;
    }
}

void BST::showHeight()
{
    cout << "The height of the BST is: " << height(root) << endl;
}

void BST::countLeaf()
{
    cout << "The leaves in this tree is: " << leafCount(root) << endl;
}

void BST::checkBST()
{
    int prev = INT_MIN;
    cout << "BST tree: " << isBST(root, prev) << endl;
}

int BST::leafCount(bstNode *node)
{
    if (node->lchild == 0 || node->rchild == 0)
    {
        return 1;
    }
    return leafCount(node->lchild) + leafCount(node->rchild);
}

bool BST::isBST(bstNode *node, int &prev)
{
    if (node == 0)
    {
        return true;
    }
    if (isBST(node->lchild, prev) == 0)
    {
        return false;
    }
    if (node->value <= prev)
    {
        return false;
    }
    prev = node->value;
    return isBST(node->rchild, prev);
}