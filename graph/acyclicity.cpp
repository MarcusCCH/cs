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
#define MAXN 300005
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
vector<int> adj[MAXN];
int p[MAXN];
int color[MAXN];
int n,m;
//directed
// void dfs(int s){
    
//     color[s] = 1;
//     for(auto u : adj[s]){
//         p[u] = s;
//         if(color[u] == 0){ //havent visited
//             dfs(u);
//         }
//         else if(color[u] == 1){ // 3, 1, 2
//             // repe(i,1,n)cout<<p[i]<<" ";
//             // cout<<endl;
//             // cout<<u<<" "<<s<<endl;
//             int original = p[u];
//             vector<int> cycle;
//             while(original != u){
//                 cycle.push_back(original);
//                 original = p[original];
//             }
//             cycle.push_back(u);
//             reve(i, cycle.size()-1, 0){
//                 cout<<cycle[i]<<" ";
//             }
//             cout<<endl;
//         }
//     }       
//     color[s] = 2;

// }
//undirected
bool visited[MAXN];

vector<int> c;
bool dfs(int v, int par){
    visited[v] = true;
    for(auto u : adj[v]){
        if(u == par) continue;
        p[u] = v;
        if(visited[u]){
            //cycle exist;
            // cout<<u<<" "<<v<<endl;
            // for(int i = 0; i <= n; i++)cout<<p[i]<<" ";
            // cout<<endl;
            // int k = u;
            // int original = p[u];
            // cout<<"3"<<p[3]<<endl;
            int original = v;
            // cout<<original<<endl;
            c.push_back(u);
            while(original != u){
                c.push_back(original);
                // if(original!=0)
                // cout<<original<<endl;
                original = p[original];
            }
            c.push_back(u);
            cout<<c.size()<<endl;
            reverse(c.begin(), c.end());
            for(int i = 0 ; i < c.size(); i++){
                cout<<c[i]<<" ";
            }
           
            exit(0);
        }
    
        if(dfs(u, v)){
            return true;
        }
    }
    return false;
}
int main(){ 

    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < MAXN; i++){
        visited[i] = false;
        // color[i] = 0;
    }
    // memset(color, 0, MAXN);
    for(int i = 1; i <= n; i++){
        // if(color[i] != 2){
            if(!visited[i]){
                if(dfs(i,-1)){
                    continue;
                };

            }
        // }
    }
    cout << "IMPOSSIBLE";
        return 0;
}