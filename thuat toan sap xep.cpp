#include <bits\stdc++.h>
using namespace std;
// merge sort
void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1; // số phần tử nửa bên trái
    int n2 = r - m;     // số phần tử nửa bên phải
    int L[n1];          // tạo 1 mảng chứa các phần từ bên trái là n1
    int R[n2];          // tạo 1 mảng chứa các phần tử bên phải là n2
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[l + i]; // sao chép các phần tử từ mảng a vào mảng L
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = a[m + i + 1]; // sao chép các phần tử từ a vào mảng R
    }
    int i = 0; // con trỏ duyệt mảng L
    int j = 0; // con trỏ duyệt mảng R
    int k = l; // vị trí để ghi lại vào mảng a
    // so sánh các phần  tử của 2 mảng
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) // nếu bên trái nhỏ hơn, ghi vào mảng a và tăng i, k
        {
            a[k++] = L[i++];
        }
        else
            a[k++] = R[j++]; // nếu bên trái lớn hơn, ghi vào mảng a và tăng j,k
    }
    while (i < n1) // nếu còn dư bên trái ta viết các phần tử đó vào a luôn, sau đó tăng k,i
    {
        a[k++] = L[i++];
    }
    while (j < n2) // nếu còn dư bên phải ta viết các phần tử đó vào a luôn, sau đó tăng k,j
    {
        a[k++] = R[j++];
    }
}
// hàm merge sort chính
void mergeSort(int a[], int l, int r)
{
    if (l < r) // điểu kiện dừng
    {
        int m = (l + r) / 2;    // tìm vị trí mid
        mergeSort(a, l, m);     // sắp xếp nửa trái
        mergeSort(a, m + 1, r); // sắp xếp nửa phải
        merge(a, l, m, r);      // trộn 2 nửa đã sắp xếp
    }
}

// selection sort
void selectionSort(int a[], int n)
{
    int max;
    for (int i = 0; i < n; i++)
    {
        max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[max])
                max = j;
        }
        swap(a[i], a[max]);
    }
}
// bubble sort
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}
// insertion sort
void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i], pos = i - 1;
        while (pos >= 0 && x < a[pos])
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}
// quick sort
int partition(int a[], int l, int r)
{
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            ++i;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[r]);
    return i;
}
void quickSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int p = partition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}
// heap sort
void heapify(int a[], int n, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && a[l] < a[largest])
        largest = l;
    if (r < n && a[r] < a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n)
{
    // xay dung max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // quickSort(a, 0, n - 1);
    insertionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}