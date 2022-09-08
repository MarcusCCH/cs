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
deque<pii> q;
bool u[2005][2005];
pii dist[2005][2005];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int row, col, s_x, s_y, l_m, r_m;

bool check(int x, int y)
{
    return x > 0 && y > 0 && x <= row && y <= col;
}
void solve()
{

    cin >> row >> col >> s_x >> s_y >> l_m >> r_m;
    memset(u, 0, sizeof(u));
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] == '*')
                u[i][j] = true;
        }

    dist[s_x][s_y] = make_pair(0, 0);
    u[s_x][s_y] = true;
    q.push_back(make_pair(s_x, s_y));
    int path = 1;
    while (!q.empty())
    {
        auto v = q.front();
        int vx = v.first, vy = v.second;
        q.pop_front();
        for (int k = 0; k < 4; k++)
        {
            int ux = dx[k] + vx, uy = dy[k] + vy;
            int l = dist[vx][vy].first - min(0, dy[k]);
            int r = dist[vx][vy].second + max(0, dy[k]);
            if (check(ux, uy) && !u[ux][uy] && l <= l_m && r <= r_m)
            {
                path++;
                u[ux][uy] = true;
                dist[ux][uy] = make_pair(l, r);
                (dx[k] == -1 || dx[k] == 1) ? q.push_front(make_pair(ux, uy)) : q.push_back(make_pair(ux, uy));
                // q.push_front(make_pair(ux, uy));
            }
        }
    }
    cout << path << endl;
}
int main()
{
    IOS;
    solve();
    return 0;
}