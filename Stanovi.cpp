#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
long long dp[310][310][(1<<4)];
inline int bitoff(int mask, int i) {mask &= ~(1<<i); return mask;}
int N, M, K;
long long recur(int R, int C, int mask)
{
    if (mask==0) return INF;
    if (~dp[R][C][mask]) return dp[R][C][mask];
    long long ans = 1LL*(R*C-K)*(R*C-K);
    for (int i = 1; R-i>0; i++)
    {
        ans = min(ans, recur(i,C, bitoff(mask,0)) + recur(R-i,C, bitoff(mask,1)));
    }
    for (int i = 1; C-i>0; i++)
    {
        ans = min(ans, recur(R,i, bitoff(mask,2)) + recur(R,C-i, bitoff(mask,3)));
    }
    return dp[R][C][mask] = ans;
}
int main()
{
    cin>>N>>M>>K;
//    memset(dp,-1,sizeof dp);
//    cout<<recur(N,M,(1<<4)-1);
    memset(dp[0],0x3f,sizeof dp[0]);
    for (int i = 0; i <= N; i++)
        memset(dp[i][0],0x3f,sizeof dp[i][0]);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            dp[i][j][0] = INF;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            for (int k = 1; k < (1<<4); k++)
            {
                dp[i][j][k] = 1LL*(i*j-K)*(i*j-K);
                for (int l = 1; i-l>0; l++)
                {
                    dp[i][j][k] = min(dp[i][j][k], dp[l][j][bitoff(k,0)]+dp[i-l][j][bitoff(k,1)]);
                }
                for (int l = 1; j-l>0; l++)
                {
                    dp[i][j][k] = min(dp[i][j][k], dp[i][l][bitoff(k,2)]+dp[i][j-l][bitoff(k,3)]);
                }
            }
        }
    }
    cout<<dp[N][M][(1<<4)-1];
}
