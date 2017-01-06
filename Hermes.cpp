#include <bits/stdc++.h>
#define B 1000
#define INF 0x3f3f3f3f
using namespace std;
int N;
struct point
{
    int x, y;
};
vector <point> all;
int dp[2][2][2002];

int main()
{
    cin>>N;
    all.push_back((point){0,0});
    for (int i = 1, x, y; i <= N; i++)
    {
        cin>>x>>y; //x+=1000; y+=1000;
        all.push_back((point){x,y});
    }
    memset(dp,0x3f,sizeof dp);
    dp[0][0][1000] = dp[0][1][1000] = 0;
    int flag = 0;
    int cx, cy;
    for (int i = 0; i < N; i++)
    {
        memset(dp[1-flag], 0x3f, sizeof dp[1-flag]);
        for (int j = -1000; j <= 1000; j++)
        {
            if (dp[flag][0][j+B]!=INF) // cx = curx, cy = j
            {
                cx = all[i].x; cy = j;
                dp[(1-flag)][0][cy+B] = min(dp[(1-flag)][0][cy+B], dp[flag][0][j+B] + abs(all[i+1].x-cx));
                dp[(1-flag)][1][cx+B] = min(dp[(1-flag)][1][cx+B], dp[flag][0][j+B] + abs(all[i+1].y-cy));
            }
            if (dp[flag][1][j+B]!=INF) // cx = j, cy = cury
            {
                cx = j; cy = all[i].y;
                dp[(1-flag)][0][cy+B] = min(dp[(1-flag)][0][cy+B], dp[flag][1][j+B] + abs(all[i+1].x-cx));
                dp[(1-flag)][1][cx+B] = min(dp[(1-flag)][1][cx+B], dp[flag][1][j+B] + abs(all[i+1].y-cy));
            }
        }
        flag = 1-flag;
    }
    int ans = INF;
    for (int i = 0; i <= 2000; i++)
        ans = min(ans, min(dp[flag][0][i], dp[flag][1][i]));
    cout<<ans<<"\n";
}
