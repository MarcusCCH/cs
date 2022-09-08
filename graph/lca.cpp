#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <string.h>
using namespace std;
#define INF 1000000000
#define MAXN 1000
#define pb push_back
#define F first
#define S second
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
int h[MAXN],height = 1, n, first[MAXN];
vector<int>adj[MAXN], euler;
bool u[MAXN], add;
void dfs(int v,  int k)
{
    u[v] = true;
    h[v] = k;
    // first.push_back(make_pair(v,h[v]));
    first[v] = euler.size();
    euler.push_back(v);
    for (auto e : adj[v])
    {
        if (!u[e])
        {
            dfs(e, k+1);
            // first.push_back(make_pair(v, h[v]));
            euler.push_back(v);
        }
    }
}
int lg[MAXN], st[MAXN][26], K = 26;
void rmq(int l, int r){
    int ind = 0, a = l, b = r;
    for (int i = a; i <= r; i++){
        // cout<<h[euler[i]]<<endl;
        st[ind][0] = h[euler[i]];
        ind++;
    }
    for(int j = 1 ; j <= K; j++){
        for(int i = 0 ; i + (1<<j)  <= (r-1+1); i++){
            st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
            // cout<<st[i][j]<<endl;
        }
    }
    int len = lg[r - l + 1];
    r = r- l + 1;
    // cout << st[l][len] << " " << st[r - (1 << len) + 1][len]<<endl;
     cout << min(st[0][len], st[r - (1 << len) ][len]);
}
// can also use segment tree or swrt decomposition 

// binary
int l;
int up[MAXN][MAXN], tin[MAXN], tout[MAXN], timer = 0;
void dfs_bin(int v){
    u[v] = true;
    up[v][0] = v;
    tin[v] = ++timer;
    rep(i,1,l){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto to : v){
        if(!u[to])dfs_bin(to);
    }
    tout[v] = ++timer;

}
bool is_ancestor(int u, int v){
    return tin[u] < tin[v] && tout[u] > tout[v];
}
int lca_bin(int u, int v){
    if(is_ancestor(u,v)){
        return u;
    }
    if(is_ancestor(v,u)){
        return v;
    }
    reve(i,l,0){
        if(is_ancestor(up[u][i],v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}


// // cartesian
// vector<int> p;
// stack<int>s;
// int A[MAXN];
// void cartesian(int s){
//     for(int i = 0; i < n; i++){
//         int last = -1;
//         while(!s.empty() && A[s.top()] >= A[i]){
//             last = s.top();
//             s.pop();
//         }
//         if(!s.empty()){
//             p[i] = last;
//         }
//         if(last >= 0){
//             p[last] = i;
//         }
//     }
//     s.push(i);
// }

//tarjan 

void solve(){
    cin>>n;
    for(int i = 0 ; i < n-1; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    repe(i,1,n){
        if(!u[i])dfs(i,1);
    }
    repe(i,2, MAXN){
        lg[i] = lg[i/2] + 1;
    }
    int ql = 6, qr = 4;
    // cout<<first[ql]<<" "<<first[qr]<<endl;
    for(int i = 0 ; i < euler.size(); i++)cout<<h[euler[i]]<<" ";
    cout<<endl;
    rmq(first[ql], first[qr]);
    // cout<<endl;
    // for(int i = 1; i <= n; i++)cout<<h[i]<<" ";
}
int main(){ 
 solve(); 
 return 0; 
}