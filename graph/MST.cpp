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
int n;
vector<vector<int> > adj;    // adjacency matrix of graph
bool selected[MAXN];
struct Edge
{
    int w = INF, to = -1;
};
void prim(){
    vector<Edge>min_e(n);
    int total_weight = 0;
    for(int i = 0 ; i < MAXN; i++)selected[i] = false;
    selected[0] = true;
    min_e[0].w = 0;
    for(int i = 0; i < n; i++){
        int v = -1;
        for(int j = 0 ; j < min_e.size(); j++){
            if(!selected[j] && (min_e[j].w < min_e[v].w || v== -1)){
                v = j;
            }
        }
        if(v == -1){
            cout<<"No mst"<<endl;
            exit(0);
        }
        selected[v] = true;
        total_weight += min_e[v].w;
        for(int to = 0 ; to < n; to++){
            if(adj[v][to]< min_e[v].w ){
                min_e[to] = {adj[i][to],v};
            }
        }
    }


}
int main(){ 

 return 0; 
}