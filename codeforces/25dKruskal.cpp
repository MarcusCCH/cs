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
#define MAXN 2000
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
struct Edge {
    int a; int b; 
};
int parent[MAXN], ra[MAXN], leaf[MAXN];
void make_set(int i){
    parent[i] = i;
    ra[i] = 0;
    leaf[i] = i;
}
int find_set(int v){
    if(v == parent[v])return v;
    // return parent[v] = find_set(parent[v]);   
    return find_set(parent[v]);
}
void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!= b){
        if(ra[a] < ra[b]){
            swap(a,b);
        }
        parent[b] = a;
        leaf[a] = b;
        if(ra[a] == ra[b]){
            ra[a]++;
        }
    }
}
vector<Edge> e, removal;
set<int, greater<int> > roots;
void solve(){
}
int32_t main(){ 
 IOS; 
 int n;
 cin>>n;
 repe(i,1, n){
    make_set(i);
 }
 for(int i = 0 ; i < n-1; i++){
    Edge k;
    cin>>k.a>>k.b;
    e.pb(k);
 }
//  cout<<endl;
 for (int i = 0; i < n - 1; i++)
 {
    Edge cur = e[i];
    if(find_set(cur.a) != find_set(cur.b)){
        union_sets(cur.a, cur.b);
        // cout<<find_set(cur.a)<<" "<<find_set(cur.b)<<endl;
        // cout<<leaf[cur.a]<<endl;
    }else{
        Edge k;
        k.a = cur.a;
        k.b = cur.b;
        removal.pb(k);
        // cout<<"cur"<<cur.a<<" "<<cur.b<<endl;
    }
 }
//  cout<<removal.size()<<endl;
 if(removal.size()){

    for(int i = 1; i <= n; i++){
        int a = find_set(i);
        roots.insert(a);
        // cout<<a<<endl;
    }
    set<int, greater<int> >::iterator itr;
    vector<int> ans;
    for (itr = roots.begin(); itr != roots.end(); itr++)
    {
        ans.push_back(*itr);
    }
    cout<<ans.size() -1<<endl;
    int ptr = 0;
    for(int i = 0 ; i < ans.size() - 1; i++){
        cout << removal[i].a<< " "<< removal[i].b<<" "<< ans[i] << " "<<ans[i+1]<<endl;
    }
 }else{
    cout<<0<<endl;
 }
 return 0; 
}