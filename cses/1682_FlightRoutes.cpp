#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100100;
vector<int> adj[MAXN],adj_rev[MAXN], scc[MAXN],order, component, roots(MAXN,0), root_nodes, tin, low, comps;
vector<bool> used;
void dfs1(int v){
    used[v] = true;
    for(auto u : adj[v]){
        if(!used[u])dfs1(u);
    }
    order.push_back(v);

}
void dfs2(int v){
    used[v] = true;
    component.push_back(v);
    for(auto u : adj_rev[v]){
        if(!used[u])dfs2(u);
    }
}
/*
3 cases:
1.back edge to ancestor 
2.back edge to parent
3.tree edge;
*/
int timer = 0;
bool answer = true;
void dfs3(int v, int p = -1){
    used[v] = true;
    low[v] = tin[v] = timer++;

    for(auto to : scc[v]){
        if(to == p){
            continue;
        }
        if(used[to]){
            low[v] = min(low[v], tin[to]);
        }else{
            dfs3(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to]> tin[v]){
                cout<<"NO"<<endl;
                cout<<to<<" "<<v<<endl;
                answer = false;
                break;
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    used.assign(n+10,false);
    for(int i = 1; i <= n; i++){
        if(!used[i])dfs1(i);
    }
    used.assign(n+10,false);
    reverse(order.begin(), order.end());
    for(auto v : order){
        if(!used[v]){
            dfs2(v);
            int root = component.front();
            for(auto u : component){
                roots[u] = root;
            }
            root_nodes.push_back(root);
            component.clear();
        }
    }

    for(int v = 1; v <= n; v++){
        for(auto u : adj[v]){
            int root_v = roots[v], root_u = roots[u];
            if(root_v != root_u){
                scc[root_v].push_back(root_u);
            }
        }
    }
     used.assign(n+10,false);
    tin.assign(n, -1);
    low.assign(n, -1);
    int comp_n = 0;
    
    for(auto v : root_nodes){
        if(!used[v]){
            comp_n++;
            comps.push_back(v);
            dfs3(v);   

        }
    }
    if(comp_n > 1){
        cout<<"NO"<<endl;
        cout<<comps.front()<<" ";
        comps.erase(comps.begin());
        cout<<comps.front();
        return 0;
    }
    if(answer){

    cout<<"YES"<<endl;
    return 0;
    }
    
    //build a scc, and then find bridges; if there is, then output no, and the bridge; else, output yes
    return 0;
}