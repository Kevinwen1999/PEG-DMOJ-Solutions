#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int R, C;
vector <int> valid;
unordered_map <int, int> hmp;
list <int> adj[2800];
int dp[2][2800];
int tot = 0;
int main()
{
    cin>>R>>C;
    for (int i=0; i < (1<<C); i++)
    {
        if ((i & 1) || (i & (1<<(C-1)))) continue;
        bool OK = true;
        for (int j = 1; j < C-1 && OK; j++)
        {
            if (i & (1<<j))
            {
                if (j-1 >= 0 && (i & (1<<(j-1)))) OK = false;
                if (j-2 >= 0 && (i & (1<<(j-2)))) OK = false;
            }
        }
        if (OK)
        {
            valid.push_back(i);
            hmp[i] = tot++;
        }
    }
    for (int msk : valid)
    {
        int result = 0, hsh = hmp[msk];
        dp[0][hsh] = 1;
        for (int j = 0; j < C; j++)
        {
            if (msk & (1<<j))
            {
                result |= 1<<(j-1);
                result |= 1<<(j);
                result |= 1<<(j+1);
            }
        }
        for (int j : valid)
        {
            if (j & result) continue;
            adj[hsh].push_back(hmp[j]);
        }
    }
//    cout<<tot<<"\n";
    int flag = 0, msk, cnt;
    for (int i = 0; i < R-1; i++)
    {
        memset(dp[1-flag],0,sizeof dp[1-flag]);
        for (int j = 0; j < tot; j++)
        {
            msk = j; cnt = dp[flag][j];
            for (int k : adj[msk])
            {
                dp[1-flag][k] = (dp[1-flag][k]+cnt%MOD)%MOD;
            }
        }
        flag = 1-flag;
    }
    int ans = 0;
    for (int i = 0; i < tot; i++)
        ans = (ans + dp[1-flag][i]%MOD)%MOD;
    cout<<ans-1<<"\n";
}
