#include <bits/stdc++.h>
#include<iostream>
using namespace std;
struct Container
{
    string id;
    float weight;
    string type;
};
struct Node
{
    Container data;
    Node *next;
};
struct Stack
{
    Node *top;
};
typedef struct Node *node;
node creatNode(Container x)
{
    node p = new Node();
    p->data = x;
    p->next = NULL;
    return p;
}
void infi(Stack &s)
{
    s.top = NULL;
}
void Push(Stack &s, Container x)
{
    node p = creatNode(x);
    p->next = s.top;
    s.top = p;
}
void input(Stack &s, int n)
{
    Container x;
    for (int i = 1; i <= n; i++)
    {
        cout << "\nContainer thu " << i << endl;
        cout << "\nNhap ma: ";
        getline(cin, x.id);
        cout << "\nNhap trong luong: ";
        cin >> x.weight;
        cin.ignore();
        cout << "\nNhap loai hang hoa: ";
        getline(cin, x.type);
        Push(s, x);
    }
}
void Pop(Stack &s)
{
    if (s.top == NULL)
    {
        cout << "\nNgan xep rong";
        return;
    }
    Node *p = s.top; // de luu dia chi va thong tin node top
    s.top = s.top->next;
    cout << "\nContainer vua lay ra la: ";
    cout << "\nMa: " << p->data.id;
    cout << "\nTrong luong: " << p->data.weight;
    cout << "\nLoai hang hoa: " << p->data.type;
    delete p;
}
void remainContainer(Stack s, int n)
{
    if (s.top == NULL)
    {
        cout << "\nNgan xep rong";
        return;
    }
    Node *p = s.top;
    while (p != NULL)
    {
        cout << "\nMa container: " << p->data.id;
        cout << "\nTrong luong: " << p->data.weight;
        cout << "\nLoai hang hoa: " << p->data.type;
        p = p->next;
    }
}
int main()
{
    int n;
    cout << "Nhap so container: ";
    cin >> n;
    cin.ignore();
    Stack s;
    infi(s);
    input(s, n);
    Pop(s);
    remainContainer(s, n);
}
