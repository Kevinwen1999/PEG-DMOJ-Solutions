#include <bits/stdc++.h>
using namespace std;
int N;
int p[1000010];
vector <int> adj[1000010];
long long sum = 0;
long long dp[1000010], mx[1000010];
long long dfs(int u, int pa)
{
    if (~dp[u]) return dp[u];
    dp[u] = p[u];
    for (int i : adj[u])
    {
        if (i==pa) continue;
        long long ns = dfs(i,u);
        mx[u] = max(mx[u], ns);
        dp[u] += ns;
    }
    mx[u] = max(mx[u], sum-dp[u]);
    return dp[u];
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>p[i];
        sum += p[i];
    }
    for (int i = 0, a, b; i < N-1; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dp,-1,sizeof dp);
    dfs(0,-1);
    long long maxx = 0x3f3f3f3f; int idx;
    for (int i = 0; i < N; i++)
    {
        if (mx[i] < maxx)
        {
            maxx = mx[i];
            idx = i;
        }
    }
    cout<<idx<<"\n";
}
