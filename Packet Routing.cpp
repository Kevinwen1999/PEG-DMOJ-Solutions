#include <bits/stdc++.h>
#define MAXN 110
using namespace std;
int N, W, P;
int start, fin, ans;
bool found;
vector < pair <int, int> > adj[MAXN];
void dfs(int cur, int pa, int dist)
{
    if (found) return;
    if (cur==fin)
    {
        ans = dist;
        found = true;
        return;
    }
    for (auto nex : adj[cur])
    {
        if (nex.first == pa) continue;
        dfs(nex.first, cur, dist + nex.second);
        if (found) break;
    }
}
int main()
{
    cin>>N>>W>>P;
    for (int i = 0,a, b, v; i < W; i++)
    {
        cin>>a>>b>>v;
        adj[a].push_back({b,v});
        adj[b].push_back({a,v});
    }
    for (int i = 0; i < P; i++)
    {
        found = false;
        cin>>start>>fin;
        dfs(start, -1, 0);
        cout<<ans<<"\n";
    }
}
