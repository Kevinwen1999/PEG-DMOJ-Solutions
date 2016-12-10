#include <iostream>
using namespace std;
int T, N, v[1001], h[1001], dp[1001][1001];

inline int max(int a, int b) { return (a > b) ? a : b; }

int main()
{
    cin>> N >> T;
    for (int i = 1 ; i <= N; i++)
        cin >> v[i] >> h[i];
    memset(dp,0,sizeof dp);
    for (int i = 1 ; i <= N; i++ )
    {
        for ( int j = 0 ; j <= T; j++)
        {
            if (j < h[i])
            {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-h[i]]+v[i]);
            }
        }
    }
    int maxx = 0;
    for (int k = 0 ;k <= T; k++ )
    {
        maxx = max(maxx,dp[N][k]);
    }
    cout<<maxx;
    return 0;
}
