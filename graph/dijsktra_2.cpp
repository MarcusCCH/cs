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
int n;
vb visited(n,0);
vii adj[MAXN];
vi d(n,INF), p(n,-1);
void dij(int s){
    d[s] = 0;
    for(int i = 0 ; i < n; i++){
        int v= -1;
        for(int j = 0 ; j <n; j++){
            if(!visited[j] && (v==-1 || d[v] < d[j])){
                v = j;
            }
        }
        if(d[v] == INF)break;
        visited[v] = true;
        for(auto edge : adj[v]){
            int to = edge.F;
            int weight = edge.S;
            if(d[to] > d[v] + weight){
                d[to] = d[v] + weight;
                p[to] = v;  
            }
        }
    }
    
}
int32_t main(){ 
 IOS; 
 cin>>n;
 for(int i = 0; i <n; i++){
    int a,b,w;
    cin>>a>>b>>w;
    adj[a].pb(mp(b,w));
    adj[b].pb(mp(a,w));
 }
 return 0; 
}
