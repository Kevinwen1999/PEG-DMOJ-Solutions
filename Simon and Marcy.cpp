#include <iostream>
#include <cstring>
using namespace std;

const int MAXC = 1000+10, MAXM = 1000+10;
int C, M, N, K;
int dp[2][MAXM];
int main()
{
    cin>>C>>M;
    int flag = 1;
    for (int i = 0; i < C; i++)
    {
        cin>>N>>K;
        for (int j = 0; j <= M; j++)
        {
            if (i!=0) dp[flag][j] = dp[flag^1][j];
            if (j >= K)dp[flag][j] = max(dp[flag][j], dp[flag^1][j-K] + N);
        }
        flag ^= 1;
    }
    int ans = 0;
    for (int j = 0; j <= M; j++)
    {
        ans = max(ans, dp[flag^1][j]);
    }
    cout<<ans<<endl;
}
