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
#define MAXN 100010 
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
struct edge{
    int first, second;
};
bool operator<(const edge &a, const edge &b)
{
    return a.second > b.second;
}
int n, m;
vector<int> p;
vector<edge> adj[MAXN];
// priority_queue<pair<int, ll>, vector<pair<int, ll> >, greater<pair<int, ll> > > pq;
priority_queue<edge>pq;
vector<int> d;
void dijsktra()
{
    d.assign(n + 10, INF);
    int s = 1;
    d[s] = 0;
    p.assign(n + 10, -1);
    pq.push({s,0});
    while (!pq.empty())
    {
        int v = pq.top().first;
        int d_v = pq.top().second;
        // cout<<v<<endl;
        pq.pop();
        if(d_v != d[v])continue;
        for (auto e : adj[v])
        {
            int to = e.first;
            int len = e.second;
            if (d[to] > d[v] + len)
            {
                d[to] = d[v] + len;
                p[to] = v;
                pq.push({to, d[to]});
            }
        }
        // if(v== n)break;
    }
    // cout<<"hi"<<endl;
    if(d[n] < INF){
        vector<int> path;
        for(int i = 1 ; i <= n; i++){
            // cout<<i<<" "<<p[i]<<" "<<d[i]<<endl;
        }
        for (int i = n; i != -1; i = p[i])
        {
            // cout<<i<<endl;
            path.push_back(i);
        }

        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << " ";
    }else{
        cout<<-1<<endl;
    }
}
void solve()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        // adj[a].push_back(make_pair(b, cost));
        // adj[b].push_back(make_pair(a, cost));
        adj[a].push_back({b,cost});
        adj[b].push_back({a,cost});
    }
    dijsktra();
}
int main()
{
    IOS;
    solve();
    return 0;
}