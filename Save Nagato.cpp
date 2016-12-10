#include <bits/stdc++.h>
using namespace std;
int N;
vector <int> adj[500001];
int maxpath[500001], secondmaxpath[500001], maxpathindex[500001];
int dp[500001];
void dfs(int cur, int par)
{
    for (int i = 0 ; i < adj[cur].size(); i++)
    {
        int next = adj[cur][i];
        if (next==par) continue;
        dfs(next, cur);
        if (maxpath[next] + 1 > maxpath[cur])
        {
            secondmaxpath[cur] = maxpath[cur];
            maxpath[cur] = maxpath[next] + 1;
            maxpathindex[cur] = next;
        }
        else if (maxpath[next] + 1 > secondmaxpath[cur])
        {
            secondmaxpath[cur] = maxpath[next] + 1;
        }
    }
}
void dpdfs(int cur, int par, int parmax)
{
    dp[cur] = max(parmax, maxpath[cur]);
    for (int i = 0; i < adj[cur].size(); i++)
    {
        int next = adj[cur][i];
        if (next==par) continue;
        if (next == maxpathindex[cur])
        {
            dpdfs(next, cur, max(parmax + 1 , secondmaxpath[cur] + 1));
        }
        else
        {
            dpdfs(next, cur, max(parmax + 1 , maxpath[cur] + 1));
        }
    }
}
int main()
{
    cin>>N;
    for (int i = 0 ; i < N-1; i++)
    {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    dpdfs(1, -1, 0);
    for (int i = 1 ; i <= N; i++)
        cout<<dp[i]+1<<"\n";
}
