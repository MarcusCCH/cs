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
#define MAXN 300000
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
int n, q;
int parent[MAXN], r[MAXN];
struct Query{
    int l; int r; int c;
};
vector<Query> query;
void make_set(int n){
    parent[n] = n;
    r[n] = 1;
}
int find_set(int n){
    if(n == parent[n]){
        return n;
    }
    return parent[n] = find_set(parent[n]);
}
void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(r[a] < r[b]){
            swap(a,b);
        }
        parent[b] = a;
        if(r[a] == r[b]){
            r[a]++;
        }
    }

}
int ans[MAXN];
void solve(){

    for(int i = q-1; i >= 0 ; i--){
        int l = query[i].l;
        int r = query[i].r;
        int c = query[i].c;
         for (int j = find_set(l); j <= r; j = find_set(j))
        {
                ans[j] = c;
                parent[j] = j+1;
                // cout<<l<<" "<<j<<" "<<parent[j]<<endl;
            }
        }
    
    for(int i = 1 ; i <= n; i++)cout<<ans[i]<<endl;
}
int32_t main(){ 
    IOS; 
    cin>>n>>q;
    repe(i, 1, n+1){
        make_set(i);
    }
    rep(i, 0, q){
        Query a;
        cin>>a.l>>a.r>>a.c;
        query.pb(a);
    }
    solve();
    return 0; 
}