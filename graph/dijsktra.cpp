#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
using pii = pair<int, int>;
const int INF = 1000000000,  MAXN = 10005;
int t,n,r;
map<string, int> c_l;
vector<pair<int, int> >adj[MAXN];
vector<int>d;
// vector<bool>p;
vector<bool> u;
void dijsktra(int s, int e){
    d.assign(n+10, INF);
    u.assign(n+10, false);

    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                // p[to] = v;
                q.push(make_pair(d[to], to));
            }
        }
        // if(v== e)break;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 1 ; i <= n; i++){
            string c;
            cin>>c;//name of city
            c_l[c] = i;
            int neighbours;
            cin>>neighbours;
            for(int j = 0 ; j < neighbours; j++){
                int a,d;
                cin>>a>>d;
                adj[i].push_back(make_pair(a,d));
            }
        }
        int r;
        cin>>r;
        while(r--){
            string s,e;
            cin>>s>>e;
            int s_i = c_l[s], e_i = c_l[e];
            dijsktra(s_i, e_i);
            // for(int i = 1; i <= n ;i++)cout<<d[i]<<" ";
            cout<<d[e_i]<<endl;
        }
        for(int i = 1 ; i <= n; i++)adj[i].clear();
        c_l.clear();

    }



    return 0;
}