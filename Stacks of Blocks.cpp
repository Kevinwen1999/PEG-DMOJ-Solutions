#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 110
using namespace std;
int H, S;
int dp[MAXN];
int s[11];
int main()
{
    cin>>H>>S;
    for (int i = 0; i < S; i++)
    {
        cin>>s[i];
    }
    memset(dp,0x3f,sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < S; i++)
    {
        for (int h = H; h >=1; h--)
        {
            if (h < s[i]) break;
            if (dp[h-s[i]]!=INF)
                dp[h] = min(dp[h], 1+dp[h-s[i]]);
        }
    }
    if (dp[H]==INF) cout<<"0\n";
    else cout<<dp[H]<<"\n";
}
