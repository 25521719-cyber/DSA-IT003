#include <bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    node *next;
};
struct Hashtable
{
    int M;
    vector<node *> table;
};
node *createNode(int x)
{
    node *tmp = new node;
    tmp->key = x;
    tmp->next = NULL;
    return tmp;
}
void initHash(Hashtable &ht, int m)
{
    ht.M = m;
    ht.table.resize(m, NULL);
}
void insertHash(Hashtable &ht, int key)
{
    int index = key % ht.M;
    node *p = createNode(key);
    if (ht.table[index] == NULL)
        ht.table[index] = p;
    else
    {
        node *tmp = ht.table[index];
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = p;
    }
}
void countSearch(Hashtable ht, int key)
{
    int index = key % ht.M;
    node *tmp = ht.table[index];
    int count = 0;
    while (tmp != NULL)
    {
        count++;
        if (tmp->key == key)
        {
            cout << count << endl;
            return;
        }
        tmp = tmp->next;
    }
    cout << "KHONG" << endl;
}
void dungDo(int n, int m)
{
    vector<int> hashTable(m, 0);
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        int idx = key % m;
        if (hashTable[idx] > 0)
            dem++;
        hashTable[idx]++;
    }
    double per = 1.0 * dem / n;
    if (per > 0.33)
        cout << "BAD";
    else
        cout << "GOOD";
}
void maxCollision(int n, int m)
{
    vector<int> hashTable(m, 0);
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        int index = key % m;
        hashTable[index]++;
    }
    int maxIndex = 0;
    for (int i = 0; i < m; i++)
    {
        if (hashTable[i] >= maxIndex)
        {
            maxIndex = hashTable[i];
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (hashTable[i] == maxIndex)
            cout << i << endl;
    }
}
void minCollision(int n, int m)
{
    vector<int> hashTable(m, 0);
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        int index = key % m;
        hashTable[index]++;
    }
    int minCollision = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        if (hashTable[i] > 0)
        {
            if (hashTable[i] <= minCollision)
                minCollision = hashTable[i];
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (hashTable[i] == minCollision)
            cout << i << " ";
    }
}
int main()
{
    int M, N;
    float LOAD;
    cin >> M >> LOAD >> N;
    Hashtable ht;
    initHash(ht, M);
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        insertHash(ht, x);
    }

    int Np;
    cin >> Np;
    for (int i = 0; i < Np; i++)
    {
        int x;
        cin >> x;

        countSearch(ht, x);
    }

    return 0;
}