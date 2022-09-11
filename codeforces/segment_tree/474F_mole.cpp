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
int a[MAXN], t[4* MAXN];
int combine(int l, int lmid, int rmid, int r, int lc, int rc)
{
    int ret = 0;
    cout<<"range"<<l<<" "<<lmid<<" "<<rmid<<" "<<r<<" "<<lc<<" "<<rc<<endl;
    for (int i = l; i <= lmid; i++)
    {
        int counta = 0, countb = 0;
        for (int j = rmid; j <= r; j++)
        {
            if (a[j] >= a[i] && a[j] % a[i] == 0 )
            {
                counta++;
            }
            if (a[i] >= a[j] && a[i] % a[j] == 0)
            {
                countb++;
            }
        }
        cout<<"cmb cnt"<<counta+lc<<" "<<countb+rc<<endl;
        if(counta+lc == r-l)ret++;
        if(countb+rc == r-l) ret++;
    }
    cout<<ret<<endl;
    return ret;
}
void build(int v, int l, int r)
{
    if (l == r)
    {
        t[v] = 0;
    }
    else
    {
        int mid = (l + r) / 2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid+1, r);
        // cout<<"lr"<<l<<" "<<r<<endl;
        cout<<v<<" "<<t[v*2] <<" "<<t[v*2+1]<<endl;
        t[v] = t[v*2] + t[v*2+1] + combine(l, mid, mid+1, r, t[v*2], t[v*2+1]);
        cout<<"t[v]"<<t[v]<<endl;
    }
}
int get(int v, int tl, int tr, int l , int r){
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    int sum = 0;
    int lc =  get(v * 2, tl, tm, l, min(r, tm));
    int rc = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    sum = lc + rc;
    return sum + combine(l, min(r,tm), max(l,tm), r, lc, rc);
}
int32_t main()
{
    IOS;
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //  for(int i = 0 ; i < n ; i++){
    //     cout<<t[i]<<" ";
    //  }
    //  cout<<endl;
     build(1,0,n-1);
    cin >> q;
     rep(i,0,q){
        int l, r;
        cin>>l>>r;
        // int count = 0;
        // l--;r--;
        // int diff = r - l;
        // for(int j = l; j <= r; j++){
        //     cout<<t[j]<<" ";
        //     if(t[j] == diff)count++;
        // }
        // cout<<endl;

     }

    return 0;
}