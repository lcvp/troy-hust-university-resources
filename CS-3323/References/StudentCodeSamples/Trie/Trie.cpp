#include <iostream>
#include "Trie.h"
#include <iomanip>
using namespace std;

void Trie::helpDes(tnode *node)
{
    if (node != 0)
    {
        for (int i = 0; i < NUM_ALPHA; i++)
        {
            helpDes(node->child[i]);
        }
        delete node;
    }
}

void Trie::helpDisplay(int i, tnode *node, int indent)
{
    if (node != 0)
    {
        for (int i = 0; i < NUM_ALPHA; i++)
        {
            helpDisplay(i, node->child[i], indent + 6);
        }
        cout << setw(indent) << char(i + 'a') << endl;
    }
}

Trie::Trie() : root(0) {}

Trie::~Trie()
{
    helpDes(root);
}

bool Trie::search(string word)
{
    if (root == 0)
    {
        return false;
    }
    tnode *temp = root;
    int wlength = word.length();
    for (int i = 0; i < wlength; i++)
    {
        if (temp->child[word.at(i) - 'a'] == 0)
        {
            return false;
        }
        temp = temp->child[word.at(i) - 'a'];
    }
    return temp -> isword ? true : false;
}

void Trie::insert(string word)
{
    if (root == 0)
    {
        root = new tnode();
    }
    tnode *temp = root;
    int wlength = word.length();
    temp->prefix++;
    for (int i = 0; i < wlength; i++)
    {
        if (temp->child[word.at(i) - 'a'] == 0)
        {
            temp->child[word.at(i) - 'a'] = new tnode();
        }
        temp = temp->child[word.at(i) - 'a'];
        temp->prefix++;
    }
    temp->isword = true;
}

void Trie::display()
{
    if (root != 0)
    {
        for (int i = 0; i < NUM_ALPHA; i++)
        {
            helpDisplay(i, root->child[i], 0);
        }
    }
    else
        cout << "Trie empty \n";
}