#include <iostream>
using namespace std;
void countsort(int a[], int n, int exp)
{
    int count[10] = {0};
    int output[n];
    for (int i = 0; i < n; i++)
    {
        count[(a[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}
void radixsort(int a[], int n, int mx)
{
    for (int exp = 1; mx / exp > 0; exp *= 10)
    {
        countsort(a, n, exp);
    }
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int a[10];
int main()
{
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > mx)
        {
            mx = a[i];
        }
    }
    radixsort(a, n, mx);
    print(a, n);

    return 0;
}