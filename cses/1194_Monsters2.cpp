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
#define MAXN 1010
#define MAXM 1010
#define K 25
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vb vector<bool>
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
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
int n,m, d[MAXN][MAXM];
char in[MAXN][MAXM];
pii p_m[MAXN][MAXM], p_t[MAXN][MAXM];
vector<pii>e;
bool visited[MAXN][MAXM];
bool check(pii p){
    return p.F < n && p.S <m  && p.F >= 0 && p.S >= 0 && in[p.F][p.S]=='.' && !visited[p.F][p.S];
}
void bfs(pii p){
    queue<pii> cur; 
    cur.push(p);
    int timer = 0, d_m = 0, d_a = 0, coorx,coory;
    bool f_m = false;
    while(!cur.empty()){
        cur.pop();
        int r = p.F, c = p.S;
        visited[r][c] = true;
        timer++;
        for(int i = 0 ; i < 4; i++){
            if(check(mp(r+ dx[i],c+dy[i]))){
                cur.push(mp(r+dx[i],c+dy[i]));
                p_t[r+dx[i]][c+dy[i]] = make_pair(r,c);
                d[r+dx[i]][r+dy[i]] = d[r][c] + 1;
                if(in[r+dx[i]][c+dy[i]] == 'M' && !f_m){
                    d_m = d[r][c] + 1;
                    f_m = true;
                }
                else if (in[r + dx[i]][c+ dy[i]] == 'A')
                {
                    d_a = d[r][c] + 1;
                    coorx = r+dx[i];
                    coory = c+dy[i];
                }
            }
        }
    }
    int sx = p_t[coorx][coory].F, sy = p_t[coorx][coory].S;
    for (int i = coorx, j = coory; i != p.F && j != p.S; i = sx, j = sy){
        p_m[i][j] = p_t[i][j];
    }
}
int32_t main(){ 
    IOS; 
    cin>>n>>m;
    for(int i= 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            char c;
            cin>>c;
            in[i][j] = c;
            if(in[i][j] == '.' && ( i == n-1 || j == m-1)){
                e.pb(mp(i, j));
            }
        }
    }
    for(auto p : e){
        bfs(p);
    }
    return 0; 
}