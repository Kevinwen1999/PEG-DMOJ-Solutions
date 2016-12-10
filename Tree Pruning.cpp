#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define B 300
using namespace std;
int N, D;
struct node
{
    int color = 0;
    int left = -1;
    int right = -1;
    int nw = 0;
    int nb = 0;
}nn;
node alln[310];
int dp[310][310+B];
void dfs(int u)
{
    if (alln[u].color)
        alln[u].nw++;
    else
        alln[u].nb++;
    if (~alln[u].left)
    {
        dfs(alln[u].left);
        alln[u].nw += alln[alln[u].left].nw;
        alln[u].nb += alln[alln[u].left].nb;
    }
    if (~alln[u].right)
    {
        dfs(alln[u].right);
        alln[u].nw += alln[alln[u].right].nw;
        alln[u].nb += alln[alln[u].right].nb;
    }
}
int mincut(int u, int rm)
{
    int diff = alln[u].nw - alln[u].nb;
    if (rm == 0) return 0;
    if (rm == diff) return 1;
    if (~dp[u][rm+B]) return dp[u][rm+B];
    int& ans = dp[u][rm+B];
    ans = INF;
    if (~alln[u].left && ~alln[u].right)
    {
        for (int i = 0; i <= abs(rm); i++)
        {
            int ls = mincut(alln[u].left, rm > 0 ? i : -i);
            int rs = mincut(alln[u].right, rm > 0 ? rm-i : rm+i);
            if (ls!=INF && rs != INF);
            ans = min(ans, ls+rs);
        }
    }
    else if (~alln[u].left)
    {
        int ls = mincut(alln[u].left, rm);
        if (ls != INF)
            ans = min(ans, ls);
    }
    else if (~alln[u].right)
    {
        int rs = mincut(alln[u].right, rm);
        if (rs != INF)
            ans = min(ans, rs);
    }
    return ans;
}
int main()
{
    cin>>N>>D;
    for (int i = 0; i < N; i++)
    {
        int id, c, nc;
        cin>>id;
        cin>>alln[id].color>>nc;
        if (nc==0)
            continue;
        else if (nc == 1)
            cin>>alln[id].left;
        else
            cin>>alln[id].left>>alln[id].right;
    }
    dfs(0);
    int curdiff = alln[0].nw - alln[0].nb;
    //cout<<curdiff;
    int rm = curdiff - D;
    memset(dp,-1,sizeof dp);
    int ans = mincut(0,rm);
    if (ans == INF)
        cout<<"-1";
    else
        cout<<ans;
}
