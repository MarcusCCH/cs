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
#define INF 1000000000
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
bool q[10][10];
int u[10][10];
int pc[10], pr[10];
int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {-1, 0, 1, -1, 0, 1, 1, -1};
int n, m;

bool check(int r, int c)
{
    return c >= 0 && c < n && r >= 0 && r < m;
}
void solve(int c=0, int r=0, int x= 0, int y= 0){
    if(c==0 && r == m-1){
        return;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << q[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout<<endl;
    cout<<endl;
    if(r<m){
        cout<<"r<m"<<endl;
        // cout<<"r,c:"<<r<<" "<<c<<endl;
        if(u[r][c]==0){
            q[r][c] = 1;
            pc[c] = x;
            pr[r] = y;
            u[r][c]++;
            for (int i = 0; i < 8; i++)
            {
                int dc = c, dr = r;
                while (check(dc + dx[i], dr + dy[i]))
                {
                    dc += dx[i], dr += dy[i];
                    u[dr][dc]++;
                }
            }
            // for (int i = 0; i < m; i++)
            // {
            //     for (int j = 0; j < n; j++)
            //     {
            //         cout << u[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            solve(c + 1, 0, c, r);
            
        }else{
            solve(c , r + 1, x, y);
        }
    }else{
        //out of boundary
        //find last coor
        cout<<"x y"<<x<<" "<<y<<endl;
        cout<<pc[x]<<" "<<pr[y]<<endl;
        q[y][x] = 0;
        for (int i = 0; i < 8; i++)
        {
            int dc = x, dr = y;
            u[dr][dc]--;
            while (check(dc + dx[i], dr + dy[i]))
            {
                dc += dx[i], dr += dy[i];
                u[dr][dc]--;
            }
        }
        // if(y+1 > m){
        // solve(pc[x], pc[y]+1,pc[x], pr[y]);
        // }else{
        solve(x, y+1 , pc[x], pr[y]);
        // }
    }
}
int main(){ 
    n=4,m=4;
 solve();
 for (int i = 0; i < n; i++)
 {
     for (int j = 0; j < m; j++)
     {
         cout << q[i][j] << " ";
     }
     cout << endl;
 }
 return 0; 
}