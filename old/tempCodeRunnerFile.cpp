#include <iostream>
#include <algorithm>
using namespace std;
int a[105];
int main()
{
    int n, y;
    cin >> n >> y;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max = 0, counter = n - 1;
    int maxi;
    for (int i = 0; i < y; i++)
    {
        max = 0;
        for (int j = 0; j < n - i; j++)
        {
            if (a[j] >= max)
            {
                max = a[j];
                maxi = j;
            }
        }
        // if (a[maxi] != a[counter])
        // {
        swap(a[maxi], a[counter]);
        counter -= 1;
        // }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}