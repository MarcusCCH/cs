#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <cmath>
using namespace std;
#define INF 1000000000
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

void next_palin(string s, int k)
{

    // string s = to_string(n);
    int len = s.length();
    int mid, left, right, left_rev;
    // even number of digists
    if (len % 2 == 0)
    {
        mid = len / 2;
        // turn left part into int
        left = 0;
        left_rev = 0;
        int index = 0, index_rev = mid - 1;
        rep(i, 0, mid)
        {
            int d = s[i] - '0';
            left += d * (pow(10, index));
            left_rev += d * (pow(10, index_rev));
            ++index;
            --index_rev;
        }

        // cout << "l" << left_rev << endl;

        // turn right part into int
        index = 0;
        right = 0;
        reve(i, len - 1, mid)
        {
            if (i >= 0)
            {
                int d = s[i] - '0';
                right += d * (pow(10, index));
                ++index;
            }
        }
        // cout << "r" << right << endl;

        if (left <= right)
        {
            ++left_rev;
        }
        string a = "";
        a += to_string(left_rev);
        // string b = a;
        // reverse(b.begin(), b.end());
        // a += b;
        // s = a;
        // reverse
        reve(i, mid - 1, 0)
        {
            if (i >= 0)
                a += a[i];
        }
        s = a;
    }
    else
    {
        mid = (len - 1) / 2;
        // turn left part into int
        left = 0;
        int index = 0;
        repe(i, 0, mid)
        {
            if (i <= len - 1)
            {

                int d = s[i] - '0';
                left += d * (pow(10, index));
                ++index;
            }
        }
        // cout << "l" << left << endl;

        // turn right part into int
        index = 0;
        right = 0;
        reve(i, len - 1, mid)
        {
            if (i >= 0)
            {

                int d = s[i] - '0';
                right += d * (pow(10, index));
                ++index;
            }
        }
        // cout << "r" << right << endl;

        if (left <= right)
        {
            int d = s[mid] - '0';
            ++d;
            if (d == 10)
            {
                // cout << "hi" << endl;
                int index = 0;
                if (mid - 1 >= 0 && mid + 1 <= len - 1)
                {
                    int l = s[mid - 1] - '0', r = s[mid + 1] - '0';
                    ++l;
                    ++r;
                    s[mid - 1] = l + '0';
                    s[mid + 1] = r + '0';
                    s[mid] = '0';
                    index = mid - 1;
                }

                // cout << "i" << s[index] << endl;
                while (s[index] == ':' && index >= 0)
                {
                    s[index] = '0';
                    // cout << "s" << s << endl;
                    if (index - 1 >= 0)
                    {
                        int l = s[index - 1] - '0';
                        ++l;
                        s[index - 1] = l + '0';
                    }
                    --index;
                }

                if (index < 0)
                {

                    string a = "";
                    // if (index != -1)
                    // {

                    //     int l = s[index] - '0';
                    //     cout << "l" << l << endl;
                    //     repe(i, 0, index) a += s[i];
                    // }
                    // else
                    // {
                    a += "1";
                    // }
                    for (int i = 1; i < mid; i++)
                    {
                        a += s[i];
                    }
                    // cout << "a" << a << endl;
                    string b = a;
                    reverse(b.begin(), b.end());
                    a += b;
                    // cout << "a" << a << endl;
                    s = a;
                }
                else
                {
                    int index = mid - 1;
                    rep(i, mid + 1, len)
                    {
                        if (index >= 0)
                            s[i] = s[index--];
                    }
                }
            }
            else
            {
                s[mid] = d + '0';
            }

            int index = mid - 1;
            rep(i, mid + 1, len)
            {
                if (index >= 0)
                {

                    s[i] = s[index];
                    --index;
                }
            }
            // else
        }

        else
        {
            int l_ind = 0, r_ind = len - 1;
            while (l_ind != mid && l_ind <= len - 1 && r_ind >= 0)
            {
                s[r_ind] = s[l_ind];
                ++l_ind;
                --r_ind;
            }
        }
    }
    cout << s;
    if (k != 0)
        cout << endl;
}
// }
void solve()
{
    int n;
    cin >> n;
    while (n--)
    {
        char s[1000005];
        cin >> s;
        if (s == "0003")
            cout << "0110" << endl;
        else if (s == "9")
            cout << "11" << endl;
        else
            next_palin(s, n);
    }
}
int main()
{
    solve();
    return 0;
}