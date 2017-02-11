#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int N, K;
long long dp[2][10010];
int main()
{
    cin>>N>>K;
    dp[1][0] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            dp[i%2][j] = dp[(i-1)%2][j]%MOD;
            if (j > 0) dp[i%2][j] = (dp[i%2][j] + dp[i%2][j-1])%MOD;
            if (j >= i) dp[i%2][j] = (dp[i%2][j] - dp[(i-1)%2][j-i] + MOD)%MOD;
        }
    }
    cout<<dp[N%2][K]<<"\n";
}
