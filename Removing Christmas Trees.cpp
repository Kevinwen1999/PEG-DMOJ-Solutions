#include <bits/stdc++.h>
#define MAXN 1010
#define INF 0x3f3f3f3f
using namespace std;
int N;
int ori[MAXN];
int dp[MAXN][MAXN];
int recur (int l, int r)
{
    if (l > r) return 0;
    if (l==r) return 1;
    if (~dp[l][r]) return dp[l][r];
    int ans = INF;
    for (int i = l; i < r; i++)
    {
        ans = min(ans, recur(l,i) + recur(i+1, r) - (int)(ori[i]==ori[i+1]));
    }
    for (int i = l+1; i <= r; i++)
    {
        if (ori[l] == ori[i])
            ans = min(ans, recur(l, i-1) + recur(i+1, r));
    }
    for (int i = l; i <= r-1; i++)
    {
        if (ori[r]==ori[i])
            ans = min(ans, recur(i,r-1) + recur(l,i-1));
    }
    return dp[l][r] = ans;
}
int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &ori[i]);
    }
    for (int a = 0; a < N; a++)
    {
        for (int b = 1; b+a <= N; b++)
        {
            int l = b, r = b+a;
            if (l==r)
                dp[l][r] = 1;
            else
            {
                int ans = INF;
                for (int i = l; i < r; i++)
                {
                    ans = min(ans, dp[l][i] + dp[i+1][r]-(int)(ori[i]==ori[i+1]));
                }
                for (int i = l+1; i <= r; i++)
                {
                    if (ori[l] == ori[i])
                        ans = min(ans, dp[l+1][i] + dp[i+1][r]);
                }
                for (int i = l; i < r; i++)
                {
                    if (ori[r] == ori[i])
                        ans = min(ans, dp[l][i-1] + dp[i][r-1]);
                }
                dp[l][r] = ans;
            }
        }
    }
    cout<<dp[1][N]<<"\n";
}
