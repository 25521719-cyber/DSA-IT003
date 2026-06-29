#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
typedef struct Node *node;
// cap phat dong mot node moi voi du lieu la so nguyen x
node makeNode(int x)
{
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL; // nullptr;
    return tmp;
}
// kiem tra rong
bool empty(node a)
{
    return a == NULL;
}
// dem so phan tu trong danh sach
int size(node a)
{
    int cnt = 0;
    while (a != NULL)
    {
        cnt++;
        a = a->next; // gan dia chi cua node tiep theo cho node hien tai, cho node hien tai nhay sang node tiep theo
    }
    return cnt;
}
// them 1 phan tu vao dau danh sach
void insertFirst(node &a, int x)
{
    node tmp = makeNode(x);
    if (a == NULL)
        a = tmp;
    else
    {
        tmp->next = a;
        a = tmp;
    }
}
// them 1 phan tu vao cuoi danh sach
void insertLast(node &a, int x)
{
    node tmp = makeNode(x);
    tmp->data=x;
    tmp->next=NULL;
    if(a=NULL)
    a=tmp;
    node q=a;
    while(q->next!=NULL)
    q=q->next;
    q->next=tmp;
}
// them 1 phan tu vao giua
void insertMiddle(node &a, int pos, int x)
{
    if(pos==0){
    insertFirst(a,x);
    return;
    }
    node q=a;
    for(int i=0;i<pos-1;i++){
        q=q->next;
    }
    node p=makeNode(x);
    p->data=x;
    p->next=q->next;
    q->next=p;

}
// xoa phan tu dau
void deleteFirst(node &a)
{
    if (a == NULL)
        return;
    a = a->next;
}
// xoa phan tu cuoi
void deleteLast(node &a)
{
    node truoc = NULL, sau = a;
    if (a == NULL)
        return;
    while (sau->next != NULL)
    {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL)
    {
        a = NULL;
    }
    else
    {
        truoc->next = NULL;
    }
}
// xoa phan tu o giua
void deleteMiddle(node &a)
{
    if (a == NULL)
        return;
    if(a->next==NULL)
        a=a->next;
    node slow=a;
    node fast=a;
    node pre=NULL;
    while(fast!=NULL&&fast->next!=NULL){
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    pre->next=slow->next;
}
void in(node a)
{
    cout << "---------------------------";
    while (a != NULL)
    {
        cout << a->data << " ";
        a = a->next;
    }
}
class A
{
public:
    A()
    {
        cout << "Tao la A\n";
    }
    ~A()
    {
        cout << "Tao khong phai la A\n";
    }
    void xinchao()
    {
        cout << "Xin chao A\n";
    }
};
class B
{
public:
    B()
    {
        cout << "Tao la B\n";
    }
    ~B()
    {
        cout << "Tao khong phai la B\n";
    }
    void xinchao()
    {
        cout << "Xin chao B\n";
    }
};
class C : public A, public B
{
public:
    C()
    {
        cout << "Tao la C\n";
    }
    ~C()
    {
        cout << "Tao khong phai la C\n";
    }
};

int main()
{
    C c;
    c.A::xinchao();
}