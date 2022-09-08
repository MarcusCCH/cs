#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <cmath>
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
    int a, b, cost;
};
const int INFI = 1e9;
vector<edge> e;
vector<int> d, p;
vector<pii> adj[MAXN];
int m, n, t;
queue<pii> inqueue;
void bellman_ford(int s, int t)
{
    d[s] = 0;
    p.assign(n, -1);
    int x = -1;
    for (int i = 0; i < n; i++)
    {
        x = -1;
        for (int i = 0; i < m; i++)
        {
            if (d[e[i].a] < INF)
                if (d[e[i].b] > d[e[i].a] + e[i].cost)
                {
                    d[e[i].b] = max(-INF, d[e[i].a] + e[i].cost);
                    p[e[i].b] = e[i].a;
                    x = e[i].b;
                }
        }
    }
    if (x == -1)
    {
        cout << "no negative cycles" << endl;
    }
    else
    {
        int y = x;
        for (int i = 0; i < n; i++)
            y = p[y];
        vector<int> path;
        for (int cur = y;; y = p[y])
        {
            path.push_back(cur);
            if (cur == y && path.size() > 1)
            {

                break;
            }
        }
        reverse(path.begin(), path.end());
        cout << "negative cycle exists:" << endl;
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << " ";
    }
    if (d[t] == INF)
    {
        cout << "no path to: " << t;
    }
    else
    {
        vector<int> path;
        for (int i = t; i != -1; i = p[t])
        {
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
    }
}
bool shortest_path(int s)
{
    vector<bool> inqueue(n, false);
    vector<int> cnt(n, 0);
    queue<int> q;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty())
    {
        int v = inqueue.front();
        inqueue[s] = false;
        q.pop();
        for (auto e : adj[v])
        {
            int to = e.first;
            int len = e.second;

            if (d[to] > d[v] + len)
            {
                d[to] = d[v] + len;
                if (!inqueue[to])
                {
                    cnt[to]++;
                    if (cnt[to] > n)
                    {
                        return false;
                    }
                    q.push(to);
                    inqueue[to] = true;
                }
            }
        }
    }
    return true;
}
int main()
{
    d.assign(n + 10, INF);
    // bellman_ford(s, t);
    return 0;
}