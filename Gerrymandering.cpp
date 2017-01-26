#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int N, P;
int ori[100011][11];
int dp[100010][5010];
int dfs(int cur, int nmerge)
{
    if (cur > N)
    {
        if (nmerge!=0) return -INF;
        else return 0;
    }
    if (N-cur+1 <= nmerge)
    {
        return -INF;
    }
    if (dp[cur][nmerge]!=-1) return dp[cur][nmerge];
    int ans = 0;
    for (int i = 0; i <= nmerge && (cur+i)<=N; i++)
    {
        int val = ori[cur+i][1] - ori[cur-1][1];
        int add = 1;
        for (int j = 2; j <= P; j++)
        {
            if (ori[cur+i][j] - ori[cur-1][j] >= val)
            {
                add = 0; break;
            }
        }
        ans = max(ans, add + dfs(cur+i+1,nmerge-i));
    }
    return dp[cur][nmerge] = ans;
}
int main()
{
    cin>>N>>P;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= P; j++)
        {
            cin>>ori[i][j];
            ori[i][j] += ori[i-1][j];
        }
    }
    memset(dp,-1,sizeof dp);
    for (int i = 0; i < N; i++)
    {
//        cout<<dfs(1, i)<<"\n";
        if (dfs(1, i) >= (N-i)/2+1)
        {
            cout<<i<<"\n"; return 0;
        }
    }

    cout<<-1<<"\n";
}
