#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int N;
vector <int> adj[200010];
int dp[200010][30];
int recur(int cur, int color)
{
    if (dp[cur][color]!=-1) return dp[cur][color];
    int sum = color, minn = INF;
    for (int i : adj[cur])
    {
        minn = INF;
        for (int j = 1; j <= 20; j++)
        {
            if (j==color) continue;
            minn = min(minn, recur(i, j));
        }
        sum +=minn;
    }
    return dp[cur][color] = sum;
}
int main()
{
    int T; cin>>T;
    for (int a = 0; a < T; a++)
    {
        cin>>N;
        for (int i = 0; i <= N; i++)
        {
            adj[i].clear();
        }
        for (int i = 1, a; i <=N; i++)
        {
            cin>>a;
            if (i==1) continue;
            adj[a].push_back(i);
        }
        memset(dp,-1,sizeof dp);
        int ans = INF;
        for (int i = 1; i <= 20; i++)
        {
            ans = min(ans, recur(1,i));
        }
        printf("Case #%d: %d\n", a+1, ans);
    }
}
