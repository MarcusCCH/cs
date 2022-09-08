#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
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
struct Edge
{
    int to;
    int cost;
};
bool operator<(const Edge &a, const Edge &b)
{
    return a.cost > b.cost;
}
int n, m, k, p[MAXN], d[MAXN];
bool inqueue[MAXN];
vector<Edge> adj[MAXN];
void bf()
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
        p[i] = -1;
    }
    priority_queue<Edge> pq;
    d[1] = 0;
    p[1] = -1;
    pq.push({1, 0});
    // inqueue[1] = true;
    while (!pq.empty())
    {
        int v = pq.top().to;
        pq.pop();
        // inqueue[v] = false;
        cout << v << endl;
        for (auto u : adj[v])
        {
            int to = u.to;
            int len = u.cost;
            cout << v << " " << to << " " << len << " " << d[v] << " " << d[to] << endl;
            if (d[to] > d[v] + len)
            {
                d[to] = d[v] + len;
                // if(!inqueue[to]){
                p[to] = v;
                // inqueue[to] = true;
                pq.push({to, d[to]});
                // }
            }
        }
    }

    if (d[n] == INF)
        cout << -1;
    else
    {

        vector<int> path;
        for (int i = n; i != -1; i = p[i])
        {
            path.push_back(i);
        }
        cout << path.size() - 1 << endl;
        // for(int i = path.size()-1 ; i >=0 ; i--)cout<<path[i]<<" ";
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << " ";
    }
}
void solve()
{
    cin >> n >> m >> k;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, 1});
        adj[b].push_back({a, 1});
    }
    while (k--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = 0; i < adj[a].size(); i++)
        {

            if (adj[a][i].to == b)
            {
                adj[a][i].cost = 10;
            }
        }
        for (int i = 0; i < adj[b].size(); i++)
        {
            if (adj[b][i].to == c)
            {
                adj[b][i].cost = 10;
            }
        }
    }
    bf();
}
int main()
{
    IOS;
    solve();
    return 0;
}