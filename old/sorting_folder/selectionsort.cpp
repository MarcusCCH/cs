#include <iostream>
#include <algorithm>
using namespace std;
int a[105];
int main()
{
    int n, y;
    cin >> n >> y;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int mi = 101;
    int mini;
    for (int i = 1; i <= y; i++)
    {
        mi = 1000;
        for (int j = i; j <= n; j++)
        {
            if (a[j] <= mi)
            {
                mi = a[j];
                mini = j;
            }
        }
        swap(a[mini], a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}