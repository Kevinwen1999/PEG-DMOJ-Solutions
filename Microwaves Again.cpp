#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int adj[105][105];
int price[105];
int main()
{
    cin>>N>>M>>K;
    memset(adj,0x3f,sizeof adj);
    for (int i = 1; i <= N; i++)
    {
        cin>>price[i];
        adj[i][i] = 0;
    }
    for (int i = 0, u, v, w; i < M; i++)
    {
        cin>>u>>v>>w;
        adj[u][v] = adj[v][u] = w;
    }
    for (int k = 1; k <=N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                int maxx = 0;
                for (int l = 1; l <= N; l++)
                {
                    if (adj[i][l]<=K || adj[j][l]<=K || adj[k][l]<=K)
                        maxx += price[l];
                }
                ans = max(maxx, ans);
            }
        }
    }
    cout<<ans<<"\n";
}
