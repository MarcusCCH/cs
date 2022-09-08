#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <cmath>
#include <set>
#include <string.h>
using namespace std;
#define INF 1000000000
#define MAXN 100000
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
#define reve(i, a, b) for (int i = a; i >= b; --i)
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
int n;
vector<int> l, r;
void solve()
{
}
int main()
{
    cin >> n;
    int sum = (1 + n) * n / 2;
    if (sum % 2 == 0)
    {
        cout << "YES" << endl;
        int k = 1;
        int suml = 0, sumr = 0;
        while (k < n)
        {
            l.push_back(k);
            suml += k;
            r.push_back(k + 1);
            sumr += k + 1;
            k += 2;
        }
        if (n % 2 != 0)
        {
            l.push_back(n);
            suml += n;
        }
        int diff = abs(suml - sumr);

        if (n % 2 == 0)
        {
            for (int i = 0; i < diff / 2; i++)
            {
                int d = r[i];
                r[i] = l[i];
                l[i] = d;
            }
        }
        else
        {
            for (int i = 0; i < diff / 2; i++)
            {
                int d = r[i];
                r[i] = l[i + 1];
                l[i + 1] = d;
            }
        }

        cout << l.size() << endl;
        for (int i = 0; i < l.size(); i++)
        {
            cout << l[i] << " ";
        }
        cout << endl;
        cout << r.size() << endl;
        for (int i = 0; i < r.size(); i++)
        {
            cout << r[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}