#include <bits/stdc++.h>
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
        if (t->key < x)
            return addNode(t->right, x);
    }
    t = makeNode(x);
    return true;
}
int countDegree(tree t, int k)
{
    if (t == NULL)
        return 0;
    int degree = 0;
    if (t->left)
        degree++;
    if (t->right)
        degree++;
    int res = (degree == k);
    return res + countDegree(t->left, k) + countDegree(t->right, k);
}
int heightOfBST(tree t)
{
    if (t == NULL)
        return -1;
    return 1 + max(heightOfBST(t->left), heightOfBST(t->right));
}
int levelOfTree(tree t, int k)
{
    int level = 0;
    while (t != NULL)
    {
        if (t->key == k)
            return level;
        if (t->key > k)
            t = t->left;
        else
            t = t->right;
        level++;
    }
    return -1;
}
int degreeOfNode(tree t, int x)
{
    int count = 0;
    node *tmp = t;
    while (tmp != NULL)
    {
        if (tmp->key == x)
        {
            if (tmp->left)
                count++;
            if (tmp->right)
                count++;
            return count;
        }
        if (tmp->key < x)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return -1;
}
void leftNodeRight(tree &t)
{
    if (t != NULL)
    {
        leftNodeRight(t->left);
        cout << t->key << " ";
        leftNodeRight(t->right);
    }
}
int nodeAtLevelK(tree t, int k)
{
    if (t == NULL)
        return 0;
    if (k == 0)
        return 1;
    return nodeAtLevelK(t->left, k - 1) + nodeAtLevelK(t->right, k - 1);
}
int countleaf(tree t)
{
    if (t == NULL)
        return 0;
    if (t->left == NULL && t->right == NULL)
        return 1;
    return countleaf(t->left) + countleaf(t->right);
}
int maxDegree(tree t)
{
    if (t == NULL)
        return 0;
    int maxdegree = 0;
    queue<node *> q;
    q.push(t);
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        int degree = 0;
        if (p->left != NULL)
        {
            degree++;
            q.push(p->left);
        }
        if (p->right != NULL)
        {
            degree++;
            q.push(p->right);
        }
        if (degree > maxdegree)
            maxdegree = degree;
    }
    return maxdegree;
}
tree findKey(tree t, int x)
{
    while (t != NULL)
    {
        if (t->key == x)
            return t;
        if (t->key < x)
            t = t->right;
        else
            t = t->left;
    }
    return NULL;
}
bool isSibling(tree t, int x, int y)
{
    if (t == NULL)
        return false;
    if (t->left && t->right)
    {
        int leftKey = t->left->key;
        int rightKey = t->right->key;
        if (leftKey == x && rightKey == y || leftKey == y && rightKey == x)
            return true;
    }
    return isSibling(t->left, x, y) || isSibling(t->right, x, y);
}
int countNode(tree t)
{
    int count = 0;
    queue<node *> q;
    q.push(t);
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        count++;
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return count;
}
int countLeaf(tree t)
{
    int count = 0;
    queue<node *> q;
    q.push(t);
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        if (p->right == NULL && p->left == NULL)
            count++;
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return count;
}
int countNodeHas1Child(tree t)
{
    int count = 0;
    queue<node *> q;
    q.push(t);
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        if ((p->left == NULL && p->right != NULL) || (p->left != NULL && p->right == NULL))
            count++;
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return count;
}
int countNodeHas2Child(tree t)
{
    int count = 0;
    queue<node *> q;
    q.push(t);
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        if (p->left != NULL && p->right != NULL)
            count++;
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return count;
}
int countNodeEven(tree t)
{
    int count = 0;
    queue<node *> q;
    q.push(t);
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        if (p->key % 2 == 0)
            count++;
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return count;
}
int countNodeLeafEven(tree t)
{
    int count = 0;
    queue<node *> q;
    q.push(t);
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        if (p->left == NULL && p->right == NULL)
        {
            if (p->key % 2 == 0)
                count++;
        }
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return count;
}
int sumNode(tree t)
{
    int sum = 0;
    queue<node *> q;
    q.push(t);
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        sum += p->key;
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return sum;
}
int sumNodeHas1Child(tree t)
{
    int sum = 0;
    queue<node *> q;
    q.push(t);
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        if ((p->left == NULL && p->right != NULL) || (p->left != NULL && p->right == NULL))
            sum += p->key;
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return sum;
}
bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int sumNodeHas1ChildPrime(tree t)
{
    int sum = 0;
    queue<node *> q;
    q.push(t);
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        if ((p->left == NULL && p->right != NULL) || (p->left != NULL && p->right == NULL))
        {
            if (isPrime(p->key))
                sum += p->key;
        }
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return sum;
}
int heightOfTree(tree t)
{
    queue<node *> q;
    q.push(t);
    int height = -1;
    while (!q.empty())
    {
        int size = q.size();
        height++;
        for (int i = 0; i < size; i++)
        {
            node *p = q.front();
            q.pop();
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
    }
    return height;
}
void deleteNode(tree &t, int x)
{
    if (t == NULL)
    {
        cout << "Khong co node can xoa";
        return;
    }
    if (t->key > x)
        deleteNode(t->left, x);
    else if (t->key < x)
        deleteNode(t->right, x);
    else
    {
        node *p = t;
        if (t->left == NULL && t->right == NULL)
            t = NULL;
        else if (t->left == NULL)
            t = t->right;
        else if (t->right == NULL)
            t = t->left;
        else
        {
            node *q = t->left;
            while (q->right != NULL)
                q = q->right;
            t->key = q->key;
            deleteNode(t->left, q->key);
            return;
        }
    }
}
bool isSameTree(tree t, tree k)
{
    if (t == NULL && k == NULL)
        return true;
    if (t == NULL || k == NULL)
        return false;
    if (t->key != k->key)
        return false;
    return isSameTree(t->left, k->left) && isSameTree(t->right, k->right);
}
// 3  5  2  20  11  30  9  18  4
int main()
{
    int n, k;
    cin >> n >> k;
    node *Tree = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        addNode(Tree, x);
    }
    deleteNode(Tree, k);
    leftNodeRight(Tree);
}