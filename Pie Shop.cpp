#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int R, C;
int g[20][20];
list <int> adj[2600];
vector <int> valid;
int tot;
int dp1[20][2600], dp2[20][2600], weight[20][2600];
void calc_states()
{
    for (int i = 0; i < (1<<C); i++)
    {
        bool OK = true;
        for (int j = 0; j < C-1 && OK; j++)
        {
            if ((i&(1<<j))&&(i&(1<<(j+1)))) OK = false;
        }
        if (OK)
        {
            tot++;
            valid.push_back(i);
        }
    }
    for (int i = 0; i < tot; i++)
    {
        for (int j = 0; j < R; j++)
        {
            for (int k = 0; k < C; k++)
            {
                if (valid[i] & (1<<k)) weight[j][i] += g[j][k];
            }
        }
    }
    for (int i= 0; i < tot; i++)
    {
        dp1[0][i] = weight[0][i];
        dp2[0][i] = 1;
        for (int j = 0; j < tot; j++)
        {
            if (valid[i] & valid[j]) continue;
            adj[i].push_back(j);
        }
    }
}
void DP()
{
    for (int i = 0; i < R-1; i++)
    {
        for (int j = 0; j < tot; j++)
        {
            for (int k : adj[j])
            {
                int w = weight[i+1][k];
                if (dp1[i][j] + w > dp1[i+1][k])
                {
                    dp1[i+1][k] = dp1[i][j] + w;
                    dp2[i+1][k] = dp2[i][j]%MOD;
                }
                else if (dp1[i][j] + w == dp1[i+1][k])
                {
                    dp2[i+1][k] = (dp2[i][j]%MOD + dp2[i+1][k]%MOD)%MOD;
                }
            }
        }
    }
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C;
    for (int i= 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cin>>g[i][j];
    }
    calc_states();
    DP();
    int ans = -1, path = 0;
    for (int i = 0; i < tot; i++)
    {
        if (dp1[R-1][i] > ans)
        {
            ans = dp1[R-1][i]; path = dp2[R-1][i];
        }
        else if (dp1[R-1][i] == ans)
        {
            path = (path%MOD + dp2[R-1][i]%MOD)%MOD;
        }
    }
    cout<<ans<<" "<<path<<"\n";
}
