#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[15];
int partition(int n[], int p, int r)
{
    int x = n[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (n[j] <= x)
        {
            i += 1;
            swap(n[i], n[j]);
        }
    }
    swap(n[i + 1], n[r]);
    return i + 1;
}
void quickSort(int n[], int p, int r)
{
    if (p < r)
    {
        int piv = partition(n, p, r);
        quickSort(n, p, piv - 1);
        quickSort(n, piv + 1, r);
    }
    // for (int i = 0; i <= 10; i++)
    // {
    //     cout << n[i];
    // }
}

int main()
{

    // int x;
    // cin >> x;
    // for (int i = 0; i < x; i++)
    // {
    //     cin >> a[i];
    // }
    // quickSort(a, 0, x - 1);
    // for (int i = 0; i < x; i++)
    // {
    //     cout << a[i];
    // }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                count += 1;
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    cout << count << endl;
    return 0;
}