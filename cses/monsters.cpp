#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
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
int n,m,sx,sy;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
char dir[] = {'R','U','L','D'};
struct Edge{
    int px; int py; char dir;
};
char adj[MAXN][MAXN];
bool u[MAXN][MAXN];
// pii p[MAXN][MAXN];
Edge p[MAXN][MAXN];
bool check(int ux, int uy){
    return ux > 0 && uy > 0 && ux < n && uy && m && adj[ux][uy] =='.';
}
bool bfs(int x, int y){
    
    queue<pii> q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int vx = q.front().F, vy = q.front().S;
        u[vx][vy] = true;
        q.pop();
        for(int k = 0 ; k < 4; k++){
            int ux = vx + dx[k], uy = vy + dy[k];
            //exit
            if((ux == n || uy == m) && adj[ux][uy] == '.'){
                int curx=ux,cury=uy;
                vector<char>path;
                while(curx!= sx && cury!=sy){
                    Edge e = p[ux][uy];
                    curx = e.px;
                    cury = e.py;
                    path.push_back(e.dir);
                }
                cout<<"YES"<<endl;
                cout<<path.size()<<endl;
                reverse(path.begin(), path.end());
                rep(i,0,path.size()){
                    cout<<path[i];
                }
                exit(0);
            }
            //normal condition to find the path
            if(check(ux,uy) && !u[ux][uy]){
                p[ux][uy] = {vx,vy, dir[k]};
                q.push(make_pair(ux,uy));
            }
        }
    }
    return false;
}
int main(){ 
    cin>>n>>m;
 for(int i = 0 ; i < n; i++){
    for(int j = 0 ; j < m; j++){
        cin>>adj[i][j];
        u[i][j] = false;
        if(adj[i][j] == 'M'){
            adj[i][j] = '#';
        }
        if(adj[i][j] == 'A'){
            sx = i, sy=j;
        }
    }
 }   
 return 0; 
}