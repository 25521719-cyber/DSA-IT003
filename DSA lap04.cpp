#include <bits/stdc++.h>
using namespace std;
/*struct NODE
{
    int info;
    NODE *pNext;
};
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}
void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
NODE *CreateNode(int x)
{
    NODE *tmp = new NODE();
    tmp->info = x;
    tmp->pNext = NULL;
    return tmp;
}
void InsertHead(LIST &L, NODE *p)
{
    if (L.pHead == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}
void InsertTail(LIST &L, NODE *p)
{
    if (L.pTail == NULL)
    {
        L.pTail = L.pHead = p;
    }
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}
void DeleteHead(LIST &L)
{
    if (L.pHead == NULL)
        return;
    L.pHead = L.pHead->pNext;
}
void DeleteTail(LIST &L)
{
    if (L.pTail == NULL)
        return;
    NODE *truoc = NULL, *sau = L.pHead;
    while (sau->pNext != NULL)
    {
        truoc = sau;
        sau = sau->pNext;
    }
    if (truoc == NULL)
    {
        L.pTail = L.pTail = NULL;
    }
    else
    {
        truoc->pNext = NULL;
        L.pTail = truoc;
    }
}
int DemSoLuongPhanTuTrongL(LIST L)
{
    int cnt = 0;
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cnt++;
        p = p->pNext;
    }
    return cnt;
}
NODE *TimKiem1(LIST L, int k)
{
    NODE *p = L.pHead;
    for (NODE *p = L.pHead; p != NULL; p = p->pNext)
    {
        if (p->info == k)
            return p;
    }
    return NULL;
}
void TimKiem(LIST L, int k)
{
    bool found = false;
    int pos = 0;
    for (NODE *p = L.pHead; p != NULL; p = p->pNext)
    {
        if (p->info == k)
        {
            cout << pos << " ";
            found = true;
        }
        pos++;
    }
    if (!found)
        cout << "-1";
}
NODE *pos = NULL;

void InsertNode(LIST &L, NODE *k)
{
    if (pos == NULL)
    {
        InsertTail(L, k);
        return;
    }
    k->pNext = pos->pNext;
    pos->pNext = k;
}
void TimKiemVaThem(LIST &L, int k)
{
    pos = TimKiem1(L, k);
    InsertNode(L, CreateNode(1999));
    PrintList(L);
}
void DeleteNode(LIST &L, int k)
{
    NODE *truoc = NULL, *sau = L.pHead;
    if (L.pHead == NULL)
        return;
    while (sau != NULL)
    {
        if (sau->info == k)
        {
            if (truoc == NULL)
            {
                L.pHead = sau->pNext;
                sau = L.pHead;
            }
            else
            {
                truoc->pNext = sau->pNext;
                sau = truoc->pNext;
            }
        }
        else
        {
            truoc = sau;
            sau = sau->pNext;
        }
    }
}
void TimKiemVaXoa(LIST &L, int k)
{
    pos = TimKiem1(L, k);
    DeleteNode(L, k);
    if (pos == NULL)
        cout << "-1";
    else
        PrintList(L);
}
void ReverseLL(LIST &L)
{
    NODE *late = NULL;
    NODE *pres = L.pHead;
    NODE *next = NULL;
    while (pres != NULL)
    {
        next = pres->pNext;
        pres->pNext = late;
        late = pres;
        pres = next;
    }
    L.pHead = late;
}
void Noi(LIST &L1, LIST &L2)
{
    if (L1.pHead == NULL)
    {
        L1 = L2;
        return;
    }
    if (L2.pHead == NULL)
    {
        return;
    }
    L1.pTail->pNext = L2.pHead;
}
void TronDSLK(LIST &L1, LIST &L2, LIST &L3)
{
    if (L1.pHead == NULL)
    {
        L3 = L2;
        return;
    }
    if (L2.pHead == NULL)
    {
        L3 = L1;
        return;
    }
    L1.pTail->pNext = L2.pHead;
    L3 = L1;
    NODE *maxNODE = 0;
    for (NODE *p = L3.pHead; p != NULL; p = p->pNext)
    {
        maxNODE = p;
        for (NODE *k = p->pNext; k != NULL; k = k->pNext)
        {
            if (k->info < maxNODE->info)
            {
                maxNODE = k;
            }
        }
        int tmp = p->info;
        p->info = maxNODE->info;
        maxNODE->info = tmp;
    }
}
void SelectionsortData(LIST &L)
{
    NODE *maxNODE = 0;

    for (NODE *p = L.pHead; p != NULL; p = p->pNext)
    {
        maxNODE = p;
        for (NODE *k = p->pNext; k != NULL; k = k->pNext)
        {
            if (k->info < maxNODE->info)
            {
                maxNODE = k;
            }
        }
        NODE *tmp = p->pNext;
        p->pNext = maxNODE->pNext;
        maxNODE->pNext = tmp;
    }
}
void SwapPointers(LIST &L, NODE *a, NODE *b)
{
    if (a == b)
        return;
    NODE *preA = NULL, *preB = NULL, *cur = L.pHead;
    // tim pre cho 2 thang a, b. Pre la con tro truoc a, b
    while (cur->pNext != NULL && cur != NULL)
    {
        if (cur->pNext == a)
            preA = cur;
        if (cur->pNext == b)
            preB = cur;
        cur = cur->pNext;
    }
    // neu a hoac b la head, nghia la a hoac b dung dau ds
    if (a == L.pHead)
        preA = NULL;

    // xu li khi a va b canh nhau
    if (a->pNext == b)
    {
        if (preA != NULL)
            preA->pNext = b;
        else
            L.pHead = a;
        a->pNext = b->pNext;
        b->pNext = a;
    }
    // xu li khi a va b khong canh nhau
    else
    {
        if (preA != NULL)
            preA->pNext = b;
        else
            L.pHead = b;
        if (preB != NULL)
            preB->pNext = a;
        else
            L.pHead = a;
        NODE *tmp = a->pNext;
        a->pNext = b->pNext;
        b->pNext = tmp;
    }
}

void SelectionSort(LIST &L)
{
    NODE *tmp;
    NODE *p = L.pHead;
    NODE *q;
    NODE *node_min;
    while (p != NULL)
    {
        node_min = p;
        for (q = p->pNext; q != NULL; q = q->pNext)
        {
            if (q->info < node_min->info)
                node_min = q;
        }
        SwapPointers(L, p, node_min);
        p = node_min->pNext;
    }
} */

struct NGAY
{
    int Ngay, Thang, Nam;
};
struct SINHVIEN
{
    string MASV;
    string HoTen;
    NGAY NgaySinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
struct NODE
{
    SINHVIEN key;
    NODE *pNext;
};
struct LIST
{
    NODE *pHead, *pTail;
};

void NhapNgay(NGAY &a);
void XuatNgay(NGAY a);
void NhapSinhVien(SINHVIEN &a);
void XuatSinhVien(SINHVIEN a);
    NODE *CreateNode(SINHVIEN x)
    {

        NODE *tmp = new NODE();
        tmp->key = x;
        tmp->pNext = NULL;
        return tmp;
    }
    void CreateEmptyList(LIST &L)
    {
        L.pHead = NULL;
        L.pTail = NULL;
    }

    void AddTail(LIST &l, NODE *p)
    {
        if (l.pHead == NULL)
        {
            l.pHead = l.pTail = p;
        }
        else
        {
            l.pTail->pNext = p;
            l.pTail = p;
        }
    }
    void XuatDS(LIST L)
    {
        for (NODE *p = L.pHead; p != NULL; p = p->pNext)
        {
            XuatSinhVien(p->key);
            cout << endl;
        }
    }
    void NhapDS(LIST &L, int n)
    {
        CreateEmptyList(L);
        for (int i = 0; i < n; i++)
        {
            SINHVIEN x;
            NhapSinhVien(x);
            NODE *p = CreateNode(x);
            AddTail(L, p);
        }
        if (n == 0)
            cout << "Empty List.";
        return;
    }
    void Tim_SinhVien_TheoNamSinh(LIST L, int x)
    {
        for (NODE *p = L.pHead; p != NULL; p = p->pNext)
        {
            if (p->key.NgaySinh.Nam == x)
            {
                XuatSinhVien(p->key);
                cout << endl;
            }
        }
        if (x != L.pHead->key.NgaySinh.Nam)
        {
            cout << "Not found in list.";
            return;
        }
    }
    void SapXep(LIST &L)
    {
        for (NODE *p = L.pHead; p != NULL; p = p->pNext)
        {
            for (NODE *q = p->pNext; q != NULL; q = q->pNext)
            {
                if (stoi(p->key.MASV) < stoi(q->key.MASV))
                {
                    swap(p->key, q->key);
                }
            }
        }
    }
    void chenDau(LIST &L, SINHVIEN p)
    {
        NODE *tmp = CreateNode(p);
        if (L.pHead == NULL)
        {
            L.pHead = L.pTail = tmp;
        }
        else
        {
            tmp->pNext = L.pHead;
            L.pHead = tmp;
        }
    }
    void ChenGiam(LIST &L, SINHVIEN x)
    {
        chenDau(L, x);
        for (NODE *p = L.pHead; p != NULL; p = p->pNext)
        {
            for (NODE *q = p->pNext; q != NULL; q = q->pNext)
            {
                if (stoi(p->key.MASV) < stoi(q->key.MASV))
                {
                    swap(p->key, q->key);
                }
            }
        }
    }

    bool Xoa_TheoHoTen(LIST &L, string a)
    {

        NODE *truoc = NULL, *sau = L.pHead;
        bool found = false;
        while (sau != NULL)
        {
            if (sau->key.HoTen == a)
            {
                if (truoc == NULL)
                    L.pHead = sau->pNext;

                else
                    truoc->pNext = sau->pNext;
                sau = sau->pNext;
                found = true;
            }
            else
            {
                truoc = sau;
                sau = sau->pNext;
            }
        }
        return found;
    }
int main()
{
    LIST L;
    int n;
    string hoten;

    getline(cin, hoten);
    cin >> n;

    NhapDS(L, n);

    Xoa_TheoHoTen(L, hoten);

    XuatDS(L);

    return 0;
}
void NhapNgay(NGAY &a)
{
    cin >> a.Ngay >> a.Thang >> a.Nam;
}
void XuatNgay(NGAY a)
{
    cout << a.Ngay << "/" << a.Thang << "/" << a.Nam;
}
void NhapSinhVien(SINHVIEN &a)
{
    cin >> ws;
    getline(cin, a.MASV);
    getline(cin, a.HoTen);
    NhapNgay(a.NgaySinh);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}
void XuatSinhVien(SINHVIEN a)
{
    cout << a.MASV;
    cout << "\t";
    cout << a.HoTen;
    cout << "\t";
    XuatNgay(a.NgaySinh);
    cout << "\t";
    cout << a.GioiTinh;
    cout << "\t";
    cout << a.DiemToan;
    cout << "\t";
    cout << a.DiemLy;
    cout << "\t";
    cout << a.DiemHoa;
    cout << "\t";
    cout << setprecision(3);
    cout << a.DTB;
}