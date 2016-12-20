#include <bits/stdc++.h>
using namespace std;
int N;
int slow, maxx;
int tot=0;
map <string, int> M;
vector <int> adj[10010];
int dist[10010];
void bfs(int root)
{
    queue <int> buff;
    memset(dist, -1, sizeof dist);
    dist[root] = 0;
    buff.push(root);
    while (!buff.empty())
    {
        int cur = buff.front();
        buff.pop();
        for (int i : adj[cur])
        {
            if (dist[i]==-1)
            {
                dist[i] = dist[cur] + 1;
                maxx = max(maxx, dist[i]);
                buff.push(i);
            }
        }
    }
}
int main()
{
    int T; cin>>T;
    while (T--)
    {
        cin>>N;
        slow = N*10;
        tot = 0, maxx = -1;
        M.clear();
        for (int i = 0; i < N; i++)
        {
            adj[i].clear();
        }
        int root;
        for (int i = 0; i < N/2; i++)
        {
            string u, v; cin>>u>>v;
            if (!M.count(u)) M[u] = tot++;
            if (!M.count(v)) M[v] = tot++;
            adj[M[u]].push_back(M[v]);
            adj[M[v]].push_back(M[u]);
            if (i==(N/2)-1) root = M[v];
        }
        bfs(root);
        cout<<slow - 2*10*maxx<<"\n";
    }
}
