#include <iostream>
using namespace std;
struct node
{
    int key;
    node *left, *right;
};
typedef node *tree;
void createTree(tree &t)
{
    t = NULL;
}
node *makeNode(int x)
{
    node *tmp = new node();
    if (tmp == NULL)
        return NULL;
    tmp->key = x;
    tmp->left = tmp->right = NULL;
    return tmp;
}
bool addNode(tree &t, int x)
{
    if (t != NULL)
    {
        if (t->key == x)
            return false;
        if (t->key > x)
            return addNode(t->left, x);
        else
            return addNode(t->right, x);
    }
    t = makeNode(x);
    return true;
}
// duyet truoc
void nodeLeftRight(tree &t)
{
    if (t != NULL)
    {
        cout << t->key << " ";
        nodeLeftRight(t->left);
        nodeLeftRight(t->right);
    }
}
// duyet sau
void leftRightNode(tree &t)
{
    if (t != NULL)
    {
        nodeLeftRight(t->left);
        nodeLeftRight(t->right);
        cout << t->key << " ";
    }
}
int main()
{
    tree t;
    createTree(t);
    int a[] = {12, 8, 23, 15, 2, 7, 9, 3, 25, 18};
    for (int i = 0; i < 10; i++)
    {
        addNode(t, a[i]);
    }
    cout << "Cay duyet truoc NLR: ";
    nodeLeftRight(t);
    cout << "\nCay duyet sau LRN: ";
    leftRightNode(t);
}