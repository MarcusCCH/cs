#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <cstdio>
#include <cstring>
#include <string.h>
using namespace std;
#define INF 1000000005
#define MAXN 100000
#define pb push_back
#define F first
#define S second
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
int d[505][505], c[505][505];
int n;
int a[505];

ll ans[505];

int main(){ 
    IOS;
//  solve();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        // d[i][i] = 0;
        for (int j = 1; j <= n; j++)
        {
            cin >> d[i][j];
        }
    }
    repe(i, 1, n)
    {
        cin >> a[n - i + 1];
    }
    repe(k, 1, n)
    {
        // d[k][k] = 0;
        repe(i, 1, n)
        {
            repe(j, 1, n)
            {
                // if(d[a[i]][a[k]] < INF && d[a[k]][a[j]] < INF)
                // d[a[i]][a[j]] = min(d[a[i]][a[j]], d[a[i]][a[k]] + d[a[k]][a[j]]);
                if (d[a[i]][a[j]] > d[a[i]][a[k]] + d[a[k]][a[j]])
                    d[a[i]][a[j]] = d[a[i]][a[k]] + d[a[k]][a[j]];
                cout<<d[a[i]][a[j]]<<" ";
            }
            cout<<endl;
        }
    
        // cout<<endl;
        for(int i = 1; i <= k; i++)
            for(int j = 1; j <=k;j++)
            {
                ans[k] += d[a[i]][a[j]];
            }
            // cout<<endl;    
        // cout<<endl;
    }
    reve(i, n, 1)
    {
        cout << ans[i] << " ";
    }
 return 0; 
}