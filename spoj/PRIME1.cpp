#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <cmath>
using namespace std;
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repe(i, a, b) for (int i = a; i <= b; ++i)
#define rev(i, a, b) for (int i = a; i > b; --i)
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define setpr(x) cout << setprecision(x) << fixed
#define sz size()
#define seea(a, x, y)           \
    for (int i = x; i < y; i++) \
    {                           \
        cin >> a[i];            \
    }
#define seev(v, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        v.push_back(x);         \
    }
#define sees(s, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        s.insert(x);            \
    }
vc<bool> dp, u;
bool check_prime(int n)
{
    rep(i, 2, sqrt(n))
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void sieve(int l, int h)
{
    rep(i, l, h)
    {
        if (u[i])
        {
            if (dp[i])
                cout << i << endl;
        }
        else
        {
            u[i] = true;
            dp[i] = check_prime(i);
            if (dp[i])
                cout << i << endl;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    dp.assign(n + 10, false);
    u.assign(n + 10, false);
    rep(i, 0, n)
    {
        int low, high;
        cin >> low >> high;
        sieve(low, high);
    }
}
int main()
{
    IOS;
    solve();
    return 0;
}