#include <bits/stdc++.h>
#define MAXN 2020
#define INF 0x3f3f3f3f
using namespace std;
int N;
int dp[MAXN][MAXN][2];
vector <pair <int,int> > all;
int pre[MAXN];
int ans = -INF;
void dfs(int ld, int rd, int dir)
{
    int csum = dp[ld][rd][dir] + (dir ? all[rd].second : all[ld].second);
    ans = max(ans, csum);

}
int main()
{
    cin>>N;
    for (int i = 0, a, b; i < N; i++)
    {
        cin>>a>>b;
        all.push_back({a,b});
    }
    sort(all.begin(), all.end());
    pre[0] = all[0].second;
    for (int i = 1; i < N; i++)
        pre[i] = pre[i-1] + all[i].second;
    int sid;
    for (int i = 0; i < N; i++)
    {
        if (all[i].first==0)
            sid = i;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j][0] = dp[i][j][1] = -1;
    dp[sid][sid][0] = dp[sid][sid][1] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; i+j < N; j++)
        {
            int l = j, r = i+j;
            if (~dp[l][r][0] || ~dp[l][r][1])
                ans = max(ans, pre[r] - ((l-1 >=0) ? pre[l-1] : 0));
            else continue;
             // starting at left side
            if (l!=0)
            {
                if (dp[l][r][0]!=-1 && dp[l][r][0] + all[l].second >= abs(all[l].first - all[l-1].first))
                {
                    dp[l-1][r][0] = max(dp[l-1][r][0], dp[l][r][0] + all[l].second - abs(all[l].first - all[l-1].first));
                }
                if (dp[l][r][1]!=-1 && dp[l][r][1] + all[r].second >= abs(all[r].first - all[l-1].first))
                {
                    dp[l-1][r][0] = max(dp[l-1][r][0], dp[l][r][1] + all[r].second - abs(all[r].first - all[l-1].first));

                }
            }
            if (r!=N-1)
            {
                if (dp[l][r][0]!=-1 && dp[l][r][0] + all[l].second >= abs(all[l].first - all[r+1].first))
                {
                    dp[l][r+1][1] = max(dp[l][r+1][1], dp[l][r][0] + all[l].second - abs(all[l].first - all[r+1].first));
                }

                if (dp[l][r][1]!=-1 && dp[l][r][1] + all[r].second >= abs(all[r].first - all[r+1].first))
                {
                    dp[l][r+1][1] = max(dp[l][r+1][1], dp[l][r][1] + all[r].second - abs(all[r].first - all[r+1].first));
                }

            }
        }
    }
    cout<<ans<<"\n";
}
