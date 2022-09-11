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
#define MAXN 300010
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
int parent[MAXN];
struct Query{
    int l, r, c;
};
void make_set(int a){
    parent[a] = a;
    
}
vector<Query> q;
int ans[MAXN];
bool painted[MAXN];
int find_set(int a){
    if(a == parent[a]){
        return a;
    }
    return parent[a]  = find_set(parent[a]);
}
int32_t main(){ 
 IOS; 
 int n,m;
 cin>>n>>m;
 for(int i = 1; i <= n+1; i++)make_set(i);
 for(int i = 0 ; i < m; i++){
    Query a;
    cin>>a.l>>a.r>>a.c;
    q.pb(a);
 }
 for(auto itr = q.begin(); itr != q.end(); itr++){
    Query a = *itr;
    // cout<<a.l<<endl;
    for(int i = find_set(a.l); i <= a.r; i = find_set(i)){
        if(i != a.c){
        ans[i] = a.c;
        // painted[i] = true;
        parent[i] = i+1;
        }else{
            i++;
        }
    }
 }
 for(int i = 1; i <= n ; i++)cout<<ans[i]<<" ";
 return 0; 
}