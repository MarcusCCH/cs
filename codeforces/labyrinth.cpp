#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <cmath>
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
struct edge
{
    int x, y, c_l, c_r;
    edge(int _x, int _y, int _c_l, int _c_r)
    {
        x = _x;
        y = _y;
        c_l = _c_l;
        c_r = _c_r;
    }
};
char adj[2005][2005];
deque<edge> q;
bool u[2005][2005];
pii dist[2005][2005];
pii last;
void solve()
{
    int row, c, s_x, s_y, l_m, r_m;
    cin >> row >> c >> s_x >> s_y >> l_m >> r_m;
    memset(u, 0, sizeof(u));
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= c; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] == '*')
                u[i][j] = true;
        }
    int m = 1;
    q.push_front(edge(s_x, s_y, l_m, r_m));
    // adj[s_x][s_y] = '#';
    u[s_x][s_y] = true;
    dist[s_x][s_y] = make_pair(0, 0);
    while (!q.empty())
    {

        edge s = q.front();

        int i = s.x, j = s.y, l = s.c_l, r = s.c_r;
        cout << i << " " << j << endl;
        q.pop_front();
        if (j - 1 >= 1)
        {
            if (!u[i][j - 1] && dist[i][j].first + 1 <= l_m)
            {
                // go left
                --l;
                m++;
                // cout << "l" << i << " " << j - 1 << endl;
                // adj[i][j - 1] = '#';
                dist[i][j - 1] = make_pair(dist[i][j].first + 1, dist[i][j].second);
                u[i][j - 1] = true;
                q.push_back(edge(i, j - 1, l, r));
            }
        }
        // right
        if (j + 1 <= c)
        {
            if (!u[i][j + 1] && dist[i][j].second + 1 <= r_m)
            {
                // go right
                --r;
                m++;
                // cout << "r" << i << " " << j + 1 << endl;
                u[i][j + 1] = true;
                dist[i][j + 1] = make_pair(dist[i][j].first, dist[i][j].second + 1);

                // adj[i][j + 1] = '#';
                q.push_back(edge(i, j + 1, l, r));
            }
        }

        // up
        if (i - 1 >= 1)
        {
            if (!u[i - 1][j])
            {
                // go up
                m++;
                // cout << "u" << i - 1 << " " << j << endl;
                // adj[i - 1][j] = '#';
                u[i - 1][j] = true;
                dist[i - 1][j] = dist[i][j];

                q.push_front(edge(i - 1, j, l, r));
            }
        }
        // down
        if (i + 1 <= row)
        {
            if (!u[i + 1][j])
            {
                // go down
                m++;
                // cout << "d" << i + 1 << " " << j << endl;
                u[i + 1][j] = true;
                // adj[i + 1][j] = '#';
                dist[i + 1][j] = dist[i][j];

                q.push_front(edge(i + 1, j, l, r));
            }
        }
        // if (r == 0 && l == 0)
        // {
        //     // cout << "hi" << endl;
        //     last = make_pair(i, j);
        //     cout << "last" << last.first << " " << last.second << endl;
        // }
        // if (r + l > 0)
        // {
        //     // cout << "hi" << endl;
        //     // cout << last.first << " " << last.second << endl;
        //     q.push(edge(last.first, last.second, l, r));
        // }
    }

    cout << m << endl;
}
int main()
{
    IOS;
    solve();
    return 0;
}