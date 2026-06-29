#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n)
{
    cout << "Mang truoc khi sap xep:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n\nSap xep:\n";

    for (int i = 0; i < n - 1; i++)
    {
        cout << "i = " << i << "\n";

        cout << "Mang truoc khi swap: ";
        for (int k = 0; k < n; k++)
            cout << a[k] << " ";
        cout << "\n";

        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }

        cout << "Phan tu nho nhat trong doan [" << i + 1 << ", " << n - 1 << "]: " << a[minIndex] << "\n";

        cout << "Swap " << a[i] << " va " << a[minIndex] << "\n";
        swap(a[i], a[minIndex]);

        cout << "Mang sau khi swap: ";
        for (int k = 0; k < n; k++)
            cout << a[k] << " ";
        cout << "\n\n";
    }
    cout << "Mang sau khi sap xep:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}
void insertionSort(int a[], int n)
{
    cout << "Mang truoc khi sap xep:\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n\nSap xep:\n";
    for (int i = 1; i < n; i++)
    {
        int x = a[i], k = i - 1;
        cout << "i = " << i << endl;
        cout << "Mang truoc khi xu ly: ";
        for (int h = 0; h < n; h++)
        {
            cout << a[h] << " ";
        }
        cout << "\nPhan tu dang xet " << "A[" << i << "]" << " = " << a[i];
        while (k >= 0 && x < a[k])
        {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = x;
        cout << "\nChen " << x << " vao vi tri " << "k" << " = " << k + 1 << endl;
        cout << "Mang sau khi xu ly: ";
        for (int j = 0; j < n; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl
             << endl;
    }
    cout << "\nMang sau khi sap xep: \n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int partition(int a[], int l, int r, int n)
{
    int mid = (l + r) / 2;
    int pivot = a[mid];

    int i = l;
    int j = r;

    while (i <= j)
    {
        while (a[i] < pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    return i;
}

void quickSort(int a[], int l, int r, int n)
{
    if (l >= r)
        return;

    int p = partition(a, l, r, n);

    if (l < p - 1)
        quickSort(a, l, p - 1, n);

    if (p < r)
        quickSort(a, p, r, n);
}
#include <bits/stdc++.h>
using namespace std;

struct node
{
    string eng;
    string vie;

    node *left, *right;
};

typedef node *tree;

void createTree(tree &t)
{
    t = NULL;
}

node *makeNode(string eng, string vie)
{
    node *tmp = new node();

    tmp->eng = eng;
    tmp->vie = vie;

    tmp->left = tmp->right = NULL;

    return tmp;
}

// thêm từ
bool addWord(tree &t, string eng, string vie)
{
    if (t == NULL)
    {
        t = makeNode(eng, vie);
        return true;
    }

    if (eng == t->eng)
        return false;

    if (eng < t->eng)
        return addWord(t->left, eng, vie);

    return addWord(t->right, eng, vie);
}

// tra cứu
node *searchWord(tree t, string eng)
{
    while (t != NULL)
    {
        if (eng == t->eng)
            return t;

        if (eng < t->eng)
            t = t->left;
        else
            t = t->right;
    }

    return NULL;
}

// sửa nghĩa
bool editWord(tree t, string eng, string newVie)
{
    node *p = searchWord(t, eng);

    if (p == NULL)
        return false;

    p->vie = newVie;

    return true;
}

// duyệt từ điển tăng dần
void LNR(tree t)
{
    if (t != NULL)
    {
        LNR(t->left);

        cout << t->eng << " : "
             << t->vie << endl;

        LNR(t->right);
    }
}

int main()
{
    tree dict;
    createTree(dict);

    int choice;

    do
    {
        cout << "\n===== TU DIEN ANH VIET =====";
        cout << "\n1. Them tu";
        cout << "\n2. Tra cuu";
        cout << "\n3. Sua nghia";
        cout << "\n4. Xuat tu dien";
        cout << "\n0. Thoat";

        cout << "\nNhap lua chon: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            string eng, vie;

            cout << "Nhap tu tieng Anh: ";
            getline(cin, eng);

            cout << "Nhap nghia tieng Viet: ";
            getline(cin, vie);

            if (addWord(dict, eng, vie))
                cout << "Them thanh cong!";
            else
                cout << "Tu da ton tai!";
        }

        else if (choice == 2)
        {
            string eng;

            cout << "Nhap tu can tra: ";
            getline(cin, eng);

            node *p = searchWord(dict, eng);

            if (p == NULL)
                cout << "Khong tim thay!";
            else
                cout << "Nghia: " << p->vie;
        }

        else if (choice == 3)
        {
            string eng, newVie;

            cout << "Nhap tu can sua: ";
            getline(cin, eng);

            cout << "Nhap nghia moi: ";
            getline(cin, newVie);

            if (editWord(dict, eng, newVie))
                cout << "Sua thanh cong!";
            else
                cout << "Khong tim thay tu!";
        }

        else if (choice == 4)
        {
            cout << "\n===== TU DIEN =====\n";
            LNR(dict);
        }

    } while (choice != 0);

    return 0;
}