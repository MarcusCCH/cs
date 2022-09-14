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
int n;
vi a; 
vi combine(vi left, vi right){
    vi ret;
    for(int i = 0; i < left.size(); i++)ret.pb(left[i]);
    for(int j = 0; j < right.size(); j++)ret.pb(right[j]);
    return ret;
}
vi quicksort(vi v){
    if(v.size() == 1){
        return v;
    }
    int pivot = v[0];
    vi left, right;
    for(int i = 0 ; i < v.size(); i++){
        if(v[i] >= pivot){
            right.pb(v[i]);
        }else{
            left.pb(v[i]);
        }
    }
    return combine(quicksort(left), quicksort(right));

}


int32_t main(){ 
 IOS;
 cin>>n;
 for(int i = 0 ; i < n; i++){
    int x;
    cin>>x;
    a.pb(x);
 }
 vi ans = quicksort(a);
 for(int i = 0 ; i < ans.size(); i++)cout<<ans[i]<<" ";
 cout<<endl;
 return 0;
}
