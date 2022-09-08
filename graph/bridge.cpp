#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<vector<int> >adj;
vector<int> tin,low;
vector<bool> visited;
int timer = 0;
int n;
void dfs(int u, int p = -1){
    visited[u] = true;
    low[u] = tin[u] = timer++;
    for(int i = 0 ; i < adj[u].size(); i++){
        int to  = adj[u][i];
        if(to == p){
            continue;
        }
        if(visited[to]){
            low[u] = min(low[u], tin[to]);
        }
        else{
            low[u] = min(low[u], low[to]);
            if(low[to] >  tin[u]){
                cout<<"the edge:"<<u<<"->"<<to<<" is a bridge"<<endl;
            }
        }
    }
}
void find_bridges(){
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}
int main(){





    return 0;
}