#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
char grid[110][110];
int N, M;
int dp[110][110],dp1[110][110],dp2[110][110],dp3[110][110];
int pg[110][110];
int main()
{
    while (cin>>N>>M && (N||M))
    {
        for (int i = 0; i < N; i++)
        {
            cin>>grid[i];
        }
        memset(dp,-1,sizeof dp);
        memset(dp1,-1,sizeof dp1);
        memset(dp2,-1,sizeof dp2);
        memset(dp3,-1,sizeof dp3);
        memset(pg,0,sizeof pg);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j]=='*')
                    pg[i][j] = -1;
                else if (grid[i][j]!='.')
                    pg[i][j] = grid[i][j] - '0';
            }
        }
        dp[N-1][0] = pg[N-1][0];
        for (int i = N-1-1; i >= 0; i--)
        {
            if (pg[i][0] == -1) break;
            dp[i][0] = dp[i+1][0] + pg[i][0];
        }
        for (int j = 1; j < M; j++)
        {
            for (int i = 0; i < N; i++)
            {
                if (pg[i][j]==-1) continue;
                if (dp[i][j-1]!=-1)
                {
                    dp1[i][j] = max(dp1[i][j], dp[i][j-1] + pg[i][j]);
                }
            }
            for (int i = N-1; i >= 0; i--)
            {
                if (pg[i][j]==-1) continue;
                dp2[i][j] = dp1[i][j];
                if (i<N-1 && dp2[i+1][j]!=-1)
                {
                    dp2[i][j] = max(dp1[i][j], dp2[i+1][j] + pg[i][j]);
                }
            }
            for (int i = 0; i < N; i++)
            {
                if (pg[i][j]==-1) continue;
                dp3[i][j] = dp1[i][j];
                if (i>0 && dp3[i-1][j]!=-1)
                {
                    dp3[i][j] = max(dp1[i][j], dp3[i-1][j] + pg[i][j]);
                }
            }
            for (int i = 0; i < N; i++)
            {
                dp[i][j] = max(dp1[i][j], max(dp2[i][j], dp3[i][j]));
            }
        }
        cout<<dp[N-1][M-1]<<"\n";
    }
}
