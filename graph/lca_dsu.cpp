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
#define mp make_pair
#define F first
#define S second
#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vb vector<bool>
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
int parent[MAXN], ra[MAXN];
bool visited[MAXN];
vector<int> adj[MAXN];
void make_set(int n){
    parent[n] = n;
    ra[n] = 1;
}
int find_set(int n){
    if(n == parent[n]){
        return n;
    }
    return parent[n] = find_set(parent[n]);
}
void union_sets(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if(u != v){
        if(ra[u] < ra[v]){
            swap(u,v);
        }
        parent[v] = u;
    }
}
void dfs (int v){
    visited[v] = true;
    for(auto u : adj[v]){
        if(!visited[u]){

            dfs(u);
            union_sets(u,v);
            parent[find_set(v)] = v;
        }
    }
    for(int other_node : queries[v]){
        if(visited[other_node]){
            cout<<parent[find_set(other_node)];
        }
    }
}
int32_t main(){ 
 IOS; 
 solve();  
 return 0; 
}