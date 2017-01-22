#include <bits/stdc++.h>
#define UNVISITED 0
#define MAXN 5001
using namespace std;
vector <int> buff; // for SCC
vector <int> adj[MAXN], dag[MAXN];
int dfs_num[MAXN], dfs_low[MAXN];
bool in_stack[MAXN];
int dfsnumcount;
int N, M, Q;
int nSCC = 0, group[MAXN], groupsize[MAXN];

void SCC(int cur)
{
    dfs_num[cur] = dfs_low[cur] = ++dfsnumcount;
    buff.push_back(cur); // push onto SCC stack
    in_stack[cur] = true;
    for (int i = 0; i < adj[cur].size(); i++)
    {
        int v = adj[cur][i];
        if (dfs_num[v] == UNVISITED)
            SCC(v);
        if (in_stack[v]) // condition for update
            dfs_low[cur] = min(dfs_low[cur], dfs_low[v]);
    }
    if (dfs_num[cur] == dfs_low[cur]) // if cur is the start of a SCC
    {
        while (1)
        {
            int v = buff.back(); buff.pop_back(); in_stack[v] = false;
            // do sth here
            group[v] = nSCC;
            groupsize[nSCC]++;
            if (v == cur) break;
        }
        nSCC++;
    }
}
void processDAG()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j : adj[i])
        {
            if (group[i]!=group[j])
            {
                dag[group[i]].push_back(group[j]);
            }
        }
    }
    for (int i = 0; i < nSCC; i++)
        dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
}
int dist[MAXN][MAXN];
bool done[MAXN];
void spfa(int src)
{
    for (int i = 0; i < nSCC; i++)
    {
        done[i] = false;
        dist[src][i] = -1;
    }
    queue <int> buff;
    dist[src][src] = 0;
    buff.push(src);
    done[src]=true;
    while(!buff.empty())
    {
        int cur = buff.front();
        buff.pop();
        done[cur] = false;
        for (int i : dag[cur])
        {
            if (dist[src][cur] + groupsize[i] > dist[src][i])
            {
                dist[src][i] = dist[src][cur] + groupsize[i];
                if (!done[i])
                {
                    done[i] = true;
                    buff.push(i);
                }
            }
        }
    }
}
int allpairlongest()
{
    for (int i = 0; i < nSCC; i++)
        spfa(i);
}
int main()
{
    cin>>N>>M>>Q;
    for (int i = 0,a ,b; i < M; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= N; i++)
    {
        if (dfs_num[i]==UNVISITED)
            SCC(i);
    }
    processDAG();
    allpairlongest();
    for (int i = 0, a, b; i < Q; i++)
    {
        cin>>a>>b; bool OK = true;
        if (group[a]==group[b]) OK = false;
        if (!OK)
        {
            cout<<"Indeterminate\n"; continue;
        }
        int ga= group[a], gb = group[b];
        int ans = -1;
        if (~dist[ga][gb])
        {
            ans = dist[ga][gb] - groupsize[gb];
        }
        else if (~dist[gb][ga])
        {
            ans = dist[gb][ga] - groupsize[ga];
            swap(a,b);
        }
        else
        {
            cout<<"Indeterminate\n"; continue;
        }
        cout<<a<<" "<<ans<<"\n";
    }
}
