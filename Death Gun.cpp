#include <bits/stdc++.h>
#define MAXN 911
using namespace std;
int M, V;
unordered_map<string, int> S;
unordered_map<int, string> SS;
vector <int> adj[MAXN];
bool visited[MAXN],dfsnum[MAXN], stac[MAXN];
int state[MAXN];
bool dfs(int cur)
{
    if (state[cur]!=-1) return state[cur];
    if (!visited[cur])
    {
        visited[cur] = true;
        stac[cur] = true;
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int v = adj[cur][i];
            if (!visited[v] && !dfs(v))
                return state[cur] = false;
            else if (stac[v])
                return state[cur] = false;
        }
    }
    stac[cur] = false;
    return state[cur] = true;
}
vector <int> ts;
void dfs2(int cur)
{
    dfsnum[cur] = true;
    for (int i = 0; i < adj[cur].size(); i++)
        if (state[adj[cur][i]] && !dfsnum[adj[cur][i]])
            dfs2(adj[cur][i]);
    ts.push_back(cur);
}
/*void dfs2(int cur)
{
    dfsnum[cur] = true;
    cout<<SS[cur]<<"\n";
    for (int i = 0; i < adj[cur].size(); i++)
        if (state[adj[cur][i]] && !dfsnum[adj[cur][i]])
            dfs2(adj[cur][i]);
}*/
int main()
{
    cin>>M;
    for (int i = 0; i < M; i++)
    {
        string a, b;
        cin>>a>>b;
        if (S.count(a)==0) S[a] = V, SS[V++] = a;
        if (S.count(b)==0) S[b] = V, SS[V++] = b;
        adj[S[b]].push_back(S[a]);
    }
    for (int i = 0; i < V; i++)
        sort(adj[i].begin(), adj[i].end());
    memset(state,-1,sizeof state);
    for (int i = 0; i < V; i++)
        if (state[i] == -1)
            dfs(i);
    for (int i = 0; i < V; i++)
        if (!dfsnum[i]&&state[i])
            dfs2(i);
    for (int i = ts.size()-1; i >=0; i--)
        cout<<SS[ts[i]]<<"\n";
}
