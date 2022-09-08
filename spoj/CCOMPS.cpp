#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200010
bool visited[MAXN];
vector<int > adj[MAXN];
void dfs(int u){
    visited[u] = true;
    for(int i = 0 ; i < adj[u].size(); i++){
        int n = adj[u][i];
        if(!visited[n]){
            dfs(n);
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    int comp = 0;
    for(int i =0 ; i < e; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            ++comp;
        }
    }
    cout<<comp<<endl;



    return 0;
}