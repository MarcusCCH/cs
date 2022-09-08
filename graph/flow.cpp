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
#define INF 1000000000
#define MAXN 100000
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
int new_flow, cap[MAXN][MAXN],t;
vector<int> adj[MAXN];
int bfs(int v){
    queue<pii> q;
    p[v] = -2;
    q.push({v,INF});
    while(!q.empty()){
        int cur = q.F;
        int flow = q.S;
        for(auto u : adj[cur]){
            if(p[u] == -1){
                p[u] = cur;
                int new_flow = min(flow, cap[cur][u]);
                if(u == t){
                    return new_flow;
                }
                q.push({u,new_flow})
            }
        }
    }
}
void some(){
    int s;
    int flow = 0;
    while(new_flow = bfs(s)){
        flow+= new_flow;    
        int cur = t;
        while(cur != s){
            cap[p[cur]][cur] -= new_flow;
            cap[cur][p[cur]] += new_flow;
            cur = p[cur];
            
        }
    }
    return flow;

}
void solve(){
}
int main(){ 
 solve(); 
 return 0; 
}