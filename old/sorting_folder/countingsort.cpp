#include <iostream>
using namespace std;
int a[100];
int cnt[100];
int tmp[100];
int main()
{
    int n;
    cin >> n;
    int ma = 0;
    int mi = 1000;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        if (a[i] >= ma)
        {
            ma = a[i];
        }
        if (a[i] <= mi)
        {
            mi = a[i];
        }
    }
    //attempt 1
    // for (int i = mi; i <= ma; i++)
    // {
    //     for (int j = 0; j < cnt[i]; j++)
    //     {
    //         cout << i << " ";
    //     }
    // }
    //attempt 2
    for (int i = mi; i <= ma; i++)
    {
        cnt[i] += cnt[i - 1];
        //1:1  2:1 3:1 5:2
        /*
        cnt[1] = 1;
        cnt[2] = 1+1 = 2;
        cnt[3] = 2+1 = 3;
        cnt[4] = 3+0 = 3;
        cnt[5] = 3+2 = 5;

        */
    }
    for (int i = 0; i < n; i++) // 5 3 5 1 2
    {
        tmp[--cnt[a[i]]] = a[i];
        /*
        cnt[a[0]]= cnt[5] 
        tmp[--5] = tmp[4] = 5;

        cnt[a[1]] = cnt[3];
        tmp[--3] = tmp[2] = 3;

        cnt[a[2]] = cnt[5];
        tmp[--4] = tmp[3] = 5;

        cnt[a[3]] = cnt[1] = 1;
        tmp[--1] = tmp[0] = 1;

        cnt[a[4]] = cnt[2] = 2;
        tmp[--2] = tmp[1] = 2;
        */
        // cout << a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = tmp[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}