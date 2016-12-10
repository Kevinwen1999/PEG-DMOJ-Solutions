#include <bits/stdc++.h>
#define MAXN 510
#define INF 0x3f3f3f3f
using namespace std;
int N, K;
int x[MAXN], y[MAXN];
int dist[MAXN][MAXN];
int d(int i, int j)
{
    return abs(x[i]-x[j]) + abs(y[i]-y[j]);
}
int dp[MAXN][MAXN];
int DP (int i, int cnt)
{
    if (i >= N-1 ) return 0;
    if (dp[i][cnt]!=-1) return dp[i][cnt];
    int& ans = dp[i][cnt];
    ans = dist[i][i+1] + DP(i+1, cnt);
    for (int j = 2; j-1<=cnt && i+j < N; j++)
    {
        ans = min(ans, DP(i+j,cnt-j+1) + dist[i][i+j]);
    }
    return ans;
}
int main()
{
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for (int i = 0 ; i < N; i++)
    {
        cin>>x[i]>>y[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dist[i][j] = d(i,j);
        }
    }
    memset(dp,-1,sizeof dp);
    cout<<DP(0,K);
}
