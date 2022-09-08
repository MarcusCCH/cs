#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
const int MAXN = 51000;
const int K = 18;
ll st[MAXN][K];
ll a[MAXN];
ll ind[MAXN];
int solve(int L, int R)
{
    int dis = R - L + 1;
    int powr = 0;
    while (dis)
    {
        dis /= 2;
        powr++;
    }
    powr -= 1;

    return max(st[L][powr], st[L + (1 << powr) - 1][powr]);
}
int main()
{

    int n;
    cin >> n;
    int q;
    cin >> q;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        st[i][0] = a[i];
        if (!ind[a[i]])
            ind[a[i]] = i;
    }
    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << (j - 1)) - 1 < n; i++)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

    for (int i = 0; i < q; i++)
    {
        ll q1, q2;
        cin >> q1 >> q2;
        ll L = ind[q1];
        ll R = ind[q2];

        if (L == R)
        {
            cnt++;
        }
        else
        {
            int maxi = solve(L, R - 1);
            if (maxi <= q1)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}