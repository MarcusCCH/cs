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
#include <string_view>
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
string s;
int len;
map<char, int> m;
void reverse(string str)
{
    for (int i = str.length() - 1; i >= 0; i--)
        cout << str[i];
}

void solve()
{
    string front, middle;
    int count = 0;
    for (const auto &n : m)
    {
        if (n.second % 2 == 0)
        {
            for (int i = 0; i < n.second / 2; i++)
            {
                front += n.first;
            }
        }
        else
        {
            count++;
            for (int i = 0; i < n.second; i++)
            {
                middle += n.first;
            }
        }
    }
    if (count > 1)
    {
        cout << "NO SOLUTION" << endl;
    }
    else
    {

        cout << front << middle;
        reverse(front);
    }
}

int main()
{
    cin >> s;
    len = s.length();
    for (int i = 0; i < s.length(); i++)
    {
        if (!m[s[i]])
            m[s[i]] = 1;
        else
        {
            m[s[i]] = m[s[i]] + 1;
        }
    }
    solve();
    return 0;
}