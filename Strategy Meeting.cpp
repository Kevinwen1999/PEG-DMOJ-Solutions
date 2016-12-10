#include <bits/stdc++.h>
using namespace std;
int adj[20][20];
int N;
int dp[20][1<<15];
int recur(int cur, int mask)
{
    if (~dp[cur][mask]) return dp[cur][mask];
    if (mask & (1<<(N-1)))
        return 1;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (mask & (1<<i)) continue;
        if (!adj[cur][i]) continue;
        ans += recur(i,mask ^ (1<<i));
    }
    return dp[cur][mask] = ans;
}
int main()
{
    int T; cin>>T;
    while (T--)
    {
        cin>>N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cin>>adj[i][j];
        }
        memset(dp,-1,sizeof dp);
        cout<<recur(0,1)<<endl;
    }
}
