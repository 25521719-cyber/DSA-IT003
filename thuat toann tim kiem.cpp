#include <bits/stdc++.h>
using namespace std;
void nhapds(vector<int> &A)
{
    int tmp;
    cout << "Nhap danh sach" << endl;
    cin >> tmp;
    while (tmp > 0)
    {
        A.push_back(tmp);
        cin >> tmp;
    }
}

void inds(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
}

void top5(vector<int> A)
{
    sort(A.begin(), A.end());
    if (A.size() < 5)
    {
        cout << "Danh sach khong du 5 phan tu";
        return;
    }

    for (int i = A.size() - 1; i >= A.size() - 5; i--)
        cout << A[i] << " ";
}

int timKiem(vector<int> A, int k)
{
    vector<int>::iterator i;
    i = find(A.begin(), A.end(), k);

    if (i != A.end())
        return i - A.begin();

    return -1;
}
// binary search
int binarySearch(int a[], int n, int x)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
            return m;
        if (a[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}
// tìm kiếm tuyến tính
int search1(int arr[], int N, int x, int &dem)
{
    dem = 0;
    for (int i = 0; i < N; i++)
    {
        dem++;
        if (x == arr[i])
        {
            return i;
        }
    }

    return -1;
}
int search2(int arr[], int N, int x, int &dem)
{
    dem = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        dem++;
        if (x == arr[i])
        {
            return N - 1 - i;
        }
    }
    return -1;
}
void timViTri(int arr[], int N, int x)
{
    int dem1 = 0, dem2 = 0;
    int demV2 = 0;
    int pos = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == x)
        {
            demV2++;
        }
    }
    cout << demV2 << endl;
    for (int i = 0; i < N; i++)
    {
        dem1++;
        if (arr[i] == x)
        {
            cout << i << " " << dem1 << endl;
            pos = i;
            break;
        }
    }
    for (int i = 0; i < N; i++)
    {
        dem2++;
        if (arr[i] == x && i == pos)
            continue;
        if (arr[i] == x)
        {
            cout << i << " " << dem2;
        }
    }
}
int myBinarySearch(int a[], int n, int x, int &dem)
{
    dem = 0;
    int l = 0, r = n - 1;
    while (l <= r)
    {
        dem++;
        int m = (l + r) / 2;
        if (a[m] == x)
            return m;
        if (a[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}
int searchTu(string a[], string s, int n, int &dem)
{
    dem = 0;
    int l = 0, r = n - 1;
    while (l <= r)
    {
        dem++;
        int m = (l + r) / 2;
        if (a[m] == s)
            return m;
        if (a[m] > s)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}
void mex(vector<int> &a, int n)
{
    vector<int> freq(n + 1, 0);
    int Mex = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= n)
            freq[a[i]]++;
        while (freq[Mex] > 0)
            Mex++;
        cout << Mex << " ";
    }
}
// truy vấn cùi bắp
int truyVan(int a[], int n, int x, int type)
{
    if (type == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == x)
            {
                return i;
            }
        }
    }
    if (type == 2)
    {
        for (int i = n; i >= 1; i--)
        {
            if (a[i] == x)
            {

                return i;
            }
        }
    }
    return -1;
}
// truy vẫns pro max
void nhapMang(unordered_map<int, vector<int>> &pos, int n)
{
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }
}
int truyVan(unordered_map<int, vector<int>> &pos, int type, int x)
{
    if (!pos.count(x))
        return -1;
    if (type == 1)
        return pos[x].front();
    else
        return pos[x].back();
}
// The messy bookshell
bool findBook(string a[], string s, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == s)
            return true;
    }
    return false;
}
string absentStudent(vector<string> &name, vector<string> &type, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (type[i] == "A")
        {
            return name[i];
        }
    }
    return "All Present";
}
// Pharmacy Stock Alert
string pharmacy(vector<string> &Pharmacy, vector<int> &price, int n)
{
    int min = 999999;
    for (int i = 0; i < n; i++)
    {
        if (price[i] < min)
            min = price[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (price[i] == min)
        {
            return Pharmacy[i];
        }
    }
}
bool isSpam(string email, vector<string> &spam)
{
    stringstream ss(email);
    string word;
    while (ss >> word)
    {
        for (string s : spam)
        {
            if (word == s)
                return true;
        }
    }
    return false;
}
void emailSpamDetector(vector<string> &email, vector<string> &spam)
{
    bool found = false;
    for (int i = 0; i < email.size(); i++)
    {
        if (isSpam(email[i], spam))
        {
            cout << i + 1;
            found = true;
        }
    }
    if (!found)
        cout << "No spam found";
}
// ER triage Priority
string patients(vector<string> &name, vector<int> &mark, vector<int> &seen, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] > max)
        {
            max = mark[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (mark[i] = max && seen[i] == 0)
        {
            return name[i];
        }
    }
    return "All patients seen";
}
// Dictionary Word Lookup
int dictionary(vector<string> &book, string x)
{
    int l = 0, r = book.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (book[mid] == x)
            return mid + 1;
        if (book[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
// Detective's Suspect Filter
void detective(vector<string> &supspect, vector<int> &height, vector<string> &colour, string hair, int min_h, int max_h, int n)
{
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (min_h <= height[i] && height[i] <= max_h && colour[i] == hair)
        {
            cout << supspect[i] << "\n";
            found = true;
        }
    }
    if (!found)
        cout << "No suspects found";
}
// Flight Departure Board
string flightDeparture(vector<string> &flight, vector<string> &num, string name)
{
    int l = 0, r = flight.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (flight[mid] == name)
            return num[mid];
        if (flight[mid] > name)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return "Not Found";
}
// Gradebook Pass Check
bool gradebook(vector<int> &a, int x)
{
    int l = 0, r = a.size() - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
            return true;
        if (a[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }
    return false;
}
//	Rotated Student Register
bool searchRotated(vector<int> &a, int x)
{
    int l = 0, r = a.size() - 1;

    while (l <= r)
    {
        int m = (l + r) / 2;

        if (a[m] == x)
            return true;

        // left part sorted
        if (a[l] <= a[m])
        {
            if (a[l] <= x && x < a[m])
                r = m - 1;
            else
                l = m + 1;
        }
        else
        {
            // right part sorted
            if (a[m] < x && x <= a[r])
                l = m + 1;
            else
                r = m - 1;
        }
    }

    return false;
}
// Mountain Hike Peak
int findPeak(vector<int> &a)
{
    int l = 0, r = a.size() - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (a[mid] < a[mid + 1])
            l = mid + 1;
        else
            r = mid;
    }
    return a[l];
}
// Museum Directory
int findID(vector<int> &a, vector<int> &b, int x)
{
    int l = 0, r = a.size() - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
            return b[m];
        if (a[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }
    return 1;
}
