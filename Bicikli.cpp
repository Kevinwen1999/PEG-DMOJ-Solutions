#include <bits/stdc++.h>
#define MAXN 10010
#define MOD 10000000000
using namespace std;
int N, M;
vector <int> adj[MAXN];
bool useful[MAXN];
int indegree[MAXN];
unsigned long long dp[MAXN];
int state[MAXN];
void dfs1(int cur)
{
    state[cur] = 1;
    if (cur==2)
        useful[cur] = true;
    for (auto i : adj[cur])
    {
        if (!state[i])
        {
            dfs1(i);
            if (useful[i]) useful[cur] = true;
        }
        else if (state[i]==2)
        {
            if (useful[i]) useful[cur] = true;
        }
    }
    state[cur] = 2;
}
bool hasTopo = true;
vector <int> topo;
void dfs2(int cur)
{
    state[cur] = 1;
    for (auto i : adj[cur])
    {
        if (!useful[i]) continue;
        if (!state[i])
            dfs2(i);
        else if (state[i]==1)
        {
            hasTopo = false;
        }
    }
    state[cur] = 2;
    topo.push_back(cur);
}
bool shit;
int main()
{
    cin>>N>>M;
    for (int i = 0, a, b; i < M; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    dfs1(1);
    memset(state,0,sizeof state);
    dfs2(1);
    if (!hasTopo)
    {
        cout<<"inf\n"; return 0;
    }
    reverse(topo.begin(), topo.end());
    dp[1] = 1;
    for (int i : topo)
    {
        for (auto j : adj[i])
        {
            if(dp[j] + dp[i] >= 1000000000) shit = true;
            dp[j] = (dp[i]%MOD + dp[j]%MOD)%MOD;
        }

    }
    if (shit)
    {
        printf("%09llu", dp[2]%1000000000);
    }
    else
        printf("%llu", dp[2]);
}
