#include <bits\stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *pnext;
};

Node *MakeNode(int a)
{
    Node *tmp = new Node();
    tmp->data = a;
    tmp->pnext = NULL;
    return tmp;
}
// stack
bool empty(Node *top)
{
    return top == NULL;
}
int getSize(Node *top)
{
    int cnt = 0;
    while (top != NULL)
    {
        cnt++;
        top = top->pnext;
    }
    return cnt;
}
void push(Node *&top, int x)
{
    Node *p = MakeNode(x);
    if (top == NULL)
        top = p;
    else
    {
        p->pnext = top;
        top = p;
    }
}
void pop(Node *&top)
{
    if (top == NULL)
        return;
    top = top->pnext;
}
int getTop(Node *top)
{
    return top->data;
}
// queue
bool Empty(Node *back)
{
    return back == NULL;
}
void Push(Node *&back, int x)
{
    Node *tmp = MakeNode(x);
    tmp->pnext = back;
    back = tmp;
}
void Pop(Node *&back)
{
    Node *truoc = NULL, *sau = back;
    while (sau->pnext != NULL)
    {
        truoc = sau;
        sau = sau->pnext;
    }
    if (truoc == NULL)
        back = NULL;
    else
        truoc->pnext = NULL;
}
int front(Node *back)
{
    while (back->pnext != NULL)
    {
        back = back->pnext;
    }
    return back->data;
}
int main()
{
    Node *back = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        Push(back, x);
    }
    cout << "\nSize: " << getSize(back) << endl;
    while (!Empty(back))
    {
        cout << front(back) << " ";
        Pop(back);
    }
    cout << "\nSize: " << getSize(back);
}