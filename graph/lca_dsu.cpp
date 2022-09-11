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
#define INF 1000000010
#define MAXN 100010
#define K 25
#define pb push_back
#define F first
#define S second
#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define repe(i, a, b) for (int i = a; i <= b; ++i)
#define reve(i, a, b) for (int i = a; i >= b; --i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

vector<int> adj[MAXN];
vector<int> queries[MAXN];
vector<int> ancestor;
vector<bool> visited;
int parent[100], ra[100];
int find_set(int v)
{
    if (v == parent[v])
        return v;
    // return parent[v] = find_set(parent[v]);
    return find_set(parent[v]);
}
void make_set(int i)
{
    parent[i] = i;
    ra[i] = 0;
}
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (ra[a] < ra[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        if (ra[a] == ra[b])
        {
            ra[a]++;
        }
    }
}


void dfs(int v)
{
    visited[v] = true;
    ancestor[v] = v;
    for (int u : adj[v])
    {
        if (!visited[u])
        {
            dfs(u);
            union_sets(v, u);
            ancestor[find_set(v)] = v;
        }
    }
    // for(int i = 1 ; i <= 7; i++)cout<<find_set(i)<<" ";
    // cout<<endl;
    for (int other_node : queries[v])
    {
        if (visited[other_node]){
            cout<<other_node<<endl;
            cout << "LCA of " << v << " and " << other_node
                 << " is " << ancestor[find_set(other_node)] << ".\n";
        }
    }
    // for(int i = 1; i <= 7; i++)cout<<ancestor[i]<<" ";
    cout<<endl;
}

int32_t main()
{

    // compute_LCAs();
    int n, m, q;
    cin >> n >> m >> q;
    repe(i,1,n){
        make_set(i);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        queries[u].push_back(v);
        queries[v].push_back(u);
    }

    ancestor.resize(n);
    visited.assign(n, false);
    dfs(1);
    return 0;
}