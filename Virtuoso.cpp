#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 100002
using namespace std;
int N;
int a[MAXN];
int dp[MAXN][7][3], dp2[MAXN][7][3];
void dfs(int cur, int note, int dir)
{
    if (cur == N)
    {
        dp[cur][note][dir] = dp2[cur][note][dir] = 0;
        return;
    }
    if (dp[cur][note][dir]!=-1) return;
    int ans = INF, ans2 = INF;
    for (int i = 0; i < 7; i++)
    {
        if (!(a[cur] & (1<<i))) continue;
        int ndir = dir;
        if (i > note) ndir = 0;
        if (i == note) ndir = 1;
        if (i < note) ndir = 2;
        dfs(cur+1, i, ndir);
        // when starting from beginning, current node does not have a direction
        int ndist = abs(i-note) + dp[cur+1][i][ndir], nchange = dp2[cur+1][i][ndir] + ((ndir==dir || cur==1) ? 0 : 1);
        if (ndist < ans)
        {
            ans = ndist;
            ans2 = nchange;
        }
        else if (ndist == ans && nchange < ans2)
        {
            ans2 = nchange;
        }
    }
    dp[cur][note][dir] = ans; dp2[cur][note][dir] = ans2;
}
int main()
{
    cin>>N;
    for (int i = 0,c,v; i < N; i++)
    {
        cin>>c;
        for (int j = 0; j < c; j++)
        {
            cin>>v; v--;
            a[i] |= (1<<v);
        }
    }
    memset(dp,-1,sizeof dp);
    int m1 = INF, m2 = INF;
    for (int i = 0; i < 7; i++)
    {
        if (a[0]&(1<<i))
        {
            dfs(0,i,0); dfs(0,i,1); dfs(0,i,2);
            if (m1 > dp[0][i][0])
            {
                m1 = dp[0][i][0];
                m2 = dp2[0][i][0];
            }
            else if (m1 == dp[0][i][0] && m2 > dp2[0][i][0])
                m2 = dp2[0][i][0];

            if (m1 > dp[0][i][1])
            {
                m1 = dp[0][i][1];
                m2 = dp2[0][i][1];
            }
            else if (m1 == dp[0][i][1] && m2 > dp2[0][i][1])
                m2 = dp2[0][i][1];

            if (m1 > dp[0][i][2])
            {
                m1 = dp[0][i][2];
                m2 = dp2[0][i][2];
            }
            else if (m1 == dp[0][i][2] && m2 > dp2[0][i][2])
                m2 = dp2[0][i][2];
        }
    }
    cout<<m1<<" "<<m2<<"\n";
}
