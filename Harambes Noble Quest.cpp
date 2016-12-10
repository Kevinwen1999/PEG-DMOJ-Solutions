#include <bits/stdc++.h>
#define MAXN 4010
#define D 2000
#define INF 0x3f3f3f3f
using namespace std;
int v[MAXN][MAXN], h[MAXN][MAXN];
int dp[MAXN][MAXN];
bool done[MAXN][MAXN];
int T;
int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
inline bool valid (int ox, int oy, int cx, int cy)
{
    return (abs(ox-D) >= abs(cx-D) && abs(oy-D) >= abs(cy-D));
}
void spfa(int xh, int yh)
{
    queue <pair <int,int> > buff;
    buff.push({xh,yh});
    done[xh][yh] = true;
    dp[xh][yh] = 0;
    while(!buff.empty())
    {
        int x = buff.front().first, y = buff.front().second;
        buff.pop();
        done[x][y] = false;
        for (int i = 0; i < 4; i++)
        {
            int cx = x + di[i], cy = y + dj[i];
            if (!valid(x,y,cx,cy)) continue;
            int nl = dp[x][y] + (i < 2 ? h[cx][cy] : v[cx][cy]);
            if (nl< dp[cx][cy])
            {
                dp[cx][cy] = nl;
                if (!done[cx][cy])
                {
                    done[cx][cy] = true;
                    buff.push({cx,cy});
                }
            }
        }
    }
}
/*int dfs (int x, int y)
{
    if (x==D&&y==D) return g[x][y];
    if (dp[x][y]!=-1) return dp[x][y];
    int add = INF;
    for (int i = 0; i < 4; i++)
    {
        int cx = x + di[i], cy = y + dj[i];
        if (!valid(x,y,cx,cy)) continue;
        add = min(add, dfs(cx,cy));
    }
    return dp[x][y] = g[x][y] + add;
}*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int xh, yh;
    cin>>xh>>yh; xh += D; yh += D;
    cin>>T;
    for (int i = 0; i < T; i++)
    {
        int x,y,L;
        cin>>x>>y;
        x+=D; y+=D;
        cin>>L;
        //if (x >= xh && y >= yh) continue;
        int up = min(y+L, 4000), r = min(x+L, 4000), l = max(0,x-L), down = max(0,y-L);
        for (int j = l; j <= r; j++)
        {
            if (yh >= up) h[j][up] += 1;
            else if (yh <= down) h[j][down] += 1;
            /*else
            {
                h[j][up] += 1;
                h[j][down] += 1;
            }*/
        }
        for (int j = down; j <= up; j++)
        {
            if (xh <= l) v[l][j] += 1;
            else if (xh >= r) v[r][j] += 1;
            /*else
            {
                v[l][j] += 1;
                v[r][j] += 1;
            }*/
        }
    }
    memset(dp,63,sizeof dp);
    spfa(xh,yh);
    cout<<dp[2000][2000];
    /*for (int i = 0; i < 4; i++)
        cout<<valid(5+D,2+D,5+D+di[i], 2+D+dj[i]);*/
    /*for (int x = 0; x < MAXN; x++)
        for (int y = 0; y < MAXN; y++)
            if (g[x][y]) cout<<x-D<<" "<<y-D<<"\n";*/
}
