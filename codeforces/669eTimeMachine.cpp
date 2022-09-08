
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
#define MAXN 10010
#define K 25
#define pb push_back
#define F first
#define S second
#define i64 long long
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
vector<vector<int> > bit;
int sum(int e, int x)
{
    int ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1){
        // cout<<bit[e][i]<<"hi"<<endl;
        ret += bit[e][i];
    }
    return ret;
}

void add(int e, int x, int delta)
{
    // cout<<"hi"<<endl;
    for (int i = x; i < 1000; i = i | (i + 1)){
        // cout<<bit[e][i]<<" "<<delta<<endl;
        bit[e][i] += delta;
        // cout<<bit[e][i]<<endl;
    }
}
int32_t main(){ 
 IOS; 
 cin>>n;
 int k = n;
 bit.assign(1000, vector<int>(1000, 0));

 while (k--)
 {
     int t, e, m;
     cin >> t >> m >> e;
     switch (t)
     { // add, delete, query
     case 1:
         add(e, m, 1);
         break;
     case 2:
         add(e, m, -1);
         break;
     case 3:
         cout << sum(e, m) << endl;
         break;
     }
    // rep(i,0,n){
    //     rep(j,0,n){
    //         cout<<bit[i][j]<<" ";
    //     }
    //     cout<<endl;
    //  }
}

 return 0; 
}