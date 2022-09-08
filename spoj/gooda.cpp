#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1000100;
int n, m, s, e, h[MAXN];
vector<int> adj[MAXN], adj_rev[MAXN], scc[MAXN], order, component, roots(MAXN, 0), root_nodes, answer;
vector<bool> used;

void dfs1(int v)
{
    used[v] = true;
    for (auto u : adj[v])
    {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}
void dfs2(int v)
{
    used[v] = true;
    component.push_back(v);
    for (auto u : adj_rev[v])
    {
        if (!used[u])
            dfs2(u);
    }
}

void dfs3(int v, int sum = h[s])
{
    // cout<<"v"<<v<<" "<<sum<<endl;
    if (v == e)
    {
        answer.push_back(sum);
        return;
    }
    else
    {

        used[v] = true;
    }
    for (auto to : scc[v])
    {
        if (!used[to])
        {
            // cout<<"to "<<to<<" "<<h[to]<<endl;
            int sum_d = sum;
            sum_d += h[to];
            dfs3(to, sum_d);
        }
    }
}
int main()
{
    cin >> n >> m >> s >> e;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    used.assign(n + 10, false);
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
            dfs1(i);
    }
    used.assign(n + 10, false);
    reverse(order.begin(), order.end());
    for (auto v : order)
    {
        if (!used[v])
        {
            dfs2(v);
            int root = component.front();
            // cout<<"root"<<root<<endl;
            for (auto u : component)
            {
                // cout<<u<<endl;
                roots[u] = root;
                if (u != root)
                    h[root] += h[u];
            }
            root_nodes.push_back(root);
            component.clear();
        }
    }
    // cout<<roots[4]<<endl;
    // if start and end are in the same component
    if (roots[s] == roots[e])
    {
        cout << h[s] << endl;
        return 0;
    }

    // else
    for (int v = 1; v <= n; v++)
    {
        for (auto u : adj[v])
        {
            int root_v = roots[v], root_u = roots[u];
            if (root_v != root_u)
            {
                scc[root_v].push_back(root_u);
            }
        }
    }
    used.assign(n + 10, false);
    dfs3(s);
    int max = -100;
    for (auto a : answer)
    {

        if (a > max)
            max = a;
    }
    cout << max << endl;
    // build a scc, and then find bridges; if there is, then output no, and the bridge; else, output yes
    return 0;
}