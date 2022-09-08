#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <cmath>
#include <set>
#include <iomanip>
#include <string.h>
using namespace std;
#define INF 1000000010
#define MAXN 500020
#define K 30
#define pb push_back
#define F first
#define S second
#define i64 long long
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
pair<int, int> st[MAXN][K];
vector<int> a(MAXN);
ll n, lg[MAXN];
int mx_st[MAXN][K], mi_st[MAXN][K];
void build(){
    lg[1] = 0;
    for(int i = 2;i <= MAXN; i++){
        lg[i] = lg[i/2] + 1;
    }
    for(int j = 1; j <= K; j++){
        for(int i = 0; i + (1<<j) <= n; i++){
            //if(i /2 > 0)
            // st[i][j] = f(i, i + (1<<(j-1)));
            // pair<int,int> left = st[i][j-1], right = st[i + (1 << (j - 1))][j-1];
            // double diff = abs(left.S - right.S);
            if (left.S < right.S)
            {
                st[i][j].F = max(st[i][j-1].F, st[i+ (1<<(j-1))][j-1].F - (diff/2));
                st[i][j].S = st[i][j-1].S;
            }else{
                st[i][j].F = max(st[i + (1<< (j - 1))][j - 1].F, left.F - (diff / 2));
                st[i][j].S = right.S;
            }
            // st[i][j] = make_pair( max(left.F, right.F ), min(left.S, right.S));

        }
    }
}
auto mx(int l, int r)
{
    int j = lg[r - l + 1];
    return max(st[l][j].F, st[r - (1 << j) + 1][j].F);
};

auto mi(int l, int r)
{
    int j = lg[r - l + 1];
    return min(st[l][j].S, st[r - (1 << j) + 1][j].S);
};
void solve(int l, int r)
{
    int j = lg[r - l + 1];
    double x = mi(l, r);
    double y = double(mx(l, r) - mi(l, r)) / 2;
    double z = max((l ? mx(0, l - 1) : 0), (r < n - 1 ? mx(r + 1, n - 1) : 0));
    cout << fixed << setprecision(1) << x + max(y, z) << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i = 0 ; i < n; i++){
        cin>>a[i];
        st[i][0] = make_pair(a[i], a[i]);
    }
    
    build();
    int q;cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        solve(l,r);

    }

    return 0;
}