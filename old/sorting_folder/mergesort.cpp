#include <iostream>
#include <cmath>
using namespace std;

int tmp[100];
void mergeSort(int a[], int begin, int end)
{
    if (begin + 1 == end)
    {
        return;
    }
    int mid = (begin + end) / 2; // 2, 4, 3 | 7, 6, 9
    mergeSort(a, begin, mid);
    mergeSort(a, mid, end);
    int l = begin;
    int r = mid;
    for (int i = begin; i < end; i++)
    {
        if (l == mid)
        {
            tmp[i] = a[r++];
        }
        else if (r == end)
        {
            tmp[i] = a[l++];
        }
        else if (a[l] < a[r])
        {
            tmp[i] = a[l++];
        }
        else
        {
            tmp[i] = a[r++];
        }
    }
    for (int i = begin; i < end; i++)
    {
        a[i] = tmp[i];
    }
}
int a[10];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    return 0;
}