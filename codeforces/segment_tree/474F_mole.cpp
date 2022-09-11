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
vector<int> t[4* MAXN];
vector<int> combine(vi lc, vi rc, int l, int lmid, int rmid, int r)
{   
    vi ret(n);
    for(int i = 0 ; i < n; i++){
        ret[i] = lc[i] + rc[i];
    }
    // for(int i = 0 ; i < n ; i++)cout<<lc[i]<<" ";
    // cout<<endl;
    // for (int i = 0; i < n; i++)
    //     cout << rc[i] << " ";
    // cout<<endl;
    // for(int i = 0 ; i < n; i++)cout<<ret[i]<<" ";
    for(int i = l; i <= lmid; i++){
        for(int j = rmid; j <= r; j++){
            if(a[j] % a[i] == 0){
                ret[i]++;
            }
            if(a[i]% a[j] == 0){
                ret[j]++;
            }
        }
    }
    return ret;
}
void build(int v, int l, int r)
{
    if (l == r)
    {
        t[v] = vector<int>(n,0);
    }
    else
    {
        int mid = (l + r) / 2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid+1, r);
        t[v] = combine(t[v * 2], t[v * 2 + 1], l, mid, mid + 1, r);
    }
}
vector<int> get(int v, int tl, int tr, int l, int r)
{
    if (l > r){
        vi k(n,0);
        return k;
    }
    if (l == tl && r == tr)
    {
        // cout<<"Lr"<<l<<" "<<r<<endl;
        // for(int i = 0 ; i < n; i++){
        //     cout<<t[v][i]<<" ";
        // }
        // cout<<endl;
        return t[v];
    }
    int tm = (tl + tr) / 2;
    int sum = 0;
    // cout<<tl<<" "<<tm<<" "<<tr<<" "<<l<<" "<<min(r,tm)<<endl;
    vi lc = get(v * 2, tl, tm, l, min(r, tm));
    vi rc = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return combine(lc, rc, l, tm, tm+1, r);
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

    //  for(int i = 0 ; i < n ; i++){
    //     cout<<t[i]<<" ";
    //  }
    //  cout<<endl;
     build(1, 0,n-1);

    cin >> q;
     rep(i,0,q){
        int l, r;
        cin>>l>>r;
        vi ans = get(1,0,n-1,l-1,r-1);
        int cnt = 0;
        for(int i = 0 ; i < n; i++){
            if(ans[i] == r-l)cnt++;
            // cout<<ans[i]<<" ";
        }
        // cout<<"cnt"<<cnt<<" "<<r-l + 1 - cnt<<endl;
        cout<<r-l+1-cnt<<endl;
        // cout<<endl;
     }

    return 0;
}

// 4 0 2 0 2 
// 0 2 4 0 2 
// 0 0 4 0 2 
// 0 0 0 0 1