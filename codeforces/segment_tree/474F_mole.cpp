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
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repe(i, a, b) for (int i = a; i <= b; ++i)
#define reve(i, a, b) for (int i = a; i >= b; --i)
#define rev(i, a, b) for (int i = a; i > b; --i)
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define setpr(x) cout << setprecision(x) << fixed
#define sz size()
#define seea(a, x, y)           \
    for (int i = x; i < y; i++) \
    {                           \
        cin >> a[i];            \
    }
#define seev(v, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        v.push_back(x);         \
    }
#define sees(s, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        s.insert(x);            \
    }
// 5
// 1 3 2 4 2
// 1
// 4 5

int n;
int a[MAXN];
pii t[4*MAXN];
int gcd(int a, int b){ // 5 10 
    if(a == 0)return b;
    if(a>b)gcd(b,a);
    return gcd(b%a, a);
}
void build(int v, int l, int r)
{
    if (l == r)
    {
        t[v] = make_pair(a[l],a[l]);
    }
    else
    {
        int mid = (l + r) / 2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid+1, r);
        int g = gcd(t[v*2].F, t[v*2+1].F);
        int m = min(t[v*2].S, t[v*2+1].S);
        // cout<<l<<" "<<r<<" "<<g<<" "<<m<<endl;
        t[v] = make_pair(g,m);
    }
}
pii get(int v, int tl, int tr, int l, int r)
{
    if (l > r){
        return make_pair(-1,-1);
    }
    if (l == tl && r == tr)
    {
        // cout<<l<<" "<<r<<" "<<t[v].F<<" "<<t[v].S<<endl;
        return t[v];
    }
    int tm = (tl + tr) / 2;
    pii lc = get(v * 2, tl, tm, l, min(r, tm));
    pii rc = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    if(lc.F == -1){
        lc = rc;
    }else if(rc.F == -1){
        rc = lc;
    }
    return make_pair(gcd(lc.F,rc.F), min(lc.S,rc.S));
}
int32_t main()
{
    IOS;
    int q;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0,n-1);
    cin >> q;
     rep(i,0,q){
        int l, r;
        cin>>l>>r;
        pii ans = get(1, 0, n-1, l-1, r-1);
        // cout<<ans.F<<" "<<ans.S<<endl;
        if(ans.F == ans.S){
            int cnt = 0;
            for(int i = l-1; i<=r-1; i++){
                if(a[i] == ans.F)cnt++;
            }
            cout<<r-l-cnt+1<<endl;
        }else{
            cout<<r-l+1<<endl;
        }
     }

    return 0;
}
