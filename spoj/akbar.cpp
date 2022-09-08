#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
#define MAXN 1000010
vector<int> adj[MAXN];
queue<int>q;
int cnt[MAXN];
bool pushed[MAXN];
int parent[MAXN];

bool bfs(int s){
    while(!q.empty()){
        int v = q.front();//get the current element
        q.pop();
        ++cnt[v];
        // cout<<"start "<<v<<" "<<cnt[v]<<endl;
        if(cnt[v] > 1)return false;
        if(s>0){
        for(int i = 0 ; i < adj[v].size();i++){
                int n = adj[v][i];
                if(parent[v]!= n && !pushed[n]){ //if they are not in the same level, then push; 
                    q.push(n);
                    parent[n] = v;
                    pushed[n] = true;
                }
                //cnt[v]++;
        }
        }

        s--;
    }
    return true;
}  

int main(){
    int t;
    cin>>t;
    for(int i = 0 ; i < t ; i++){
        int n,r,m;
        cin>>n>>r>>m;
        q = queue<int>();
        bool answer = true;
        for(int k = 0 ; k < MAXN; k++){
            cnt[k] = 0;
            parent[k] = -1;
            pushed[k] = false;
            adj[k].clear();
        }
        for(int j = 0 ; j < r; j++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int j = 0 ; j < m; j++){
            int k,s;
            cin>>k>>s;
            cout<<k<<" "<<s<<endl;
            for(int l = 0; l < MAXN; l++){
                pushed[l] = false;
                parent[l] = -1;
            }
            q.push(k);
            if(!bfs(s))answer = false;
        }
        if(answer)cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }



    return 0;
}