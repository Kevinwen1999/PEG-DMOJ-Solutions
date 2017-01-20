#include <bits/stdc++.h>
#define MAXN 201
#define INF 0x3f3f3f3f
using namespace std;
int N, M, sx, sy, K, T;
char grid[MAXN][MAXN];
int ts[MAXN], te[MAXN], dir[MAXN];
int dp[201][201][201];
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int recur(int x, int y, int k)
{
//    cout<<x<<" "<<y<<"\n";
//    if (x<=0 || x>M || y<=0 || y>N) return -INF;
//    if (grid[y][x]=='x') return -INF;
    if (k == K) return 0;
    if (dp[x][y][k]!=-1) return dp[x][y][k];
    int tm = te[k]-ts[k]+1, d = dir[k];
//    cout<<tm<<"\n";
    int ans = 0, nx, ny;
    for (int i = 0; i <= tm; i++)
    {
        nx = x+i*dx[d], ny = y+i*dy[d];
//        cout<<nx<<" "<<ny<<"\n";
        if (nx<=0 || nx>N || ny<=0 || ny>M) break;
//        cout<<grid[4][1]<<"\n";
        if (grid[nx][ny]=='x') break;
        ans = max(ans, i + recur(nx, ny, k+1));
    }
//    cout<<ans<<"\n";
    return dp[x][y][k] = ans;
}
int main()
{
    cin>>N>>M>>sx>>sy>>K;
    string tmp;
    for (int i = 1; i <= N; i++)
    {
        cin>>tmp;
        for (int j = 1; j <= M; j++)
        {
            grid[i][j] = tmp[j-1];
//            cout<<grid[i][j];
        }
//        cout<<"\n";
    }
    for (int i = 0; i < K; i++)
    {
        cin>>ts[i]>>te[i]>>dir[i];
        dir[i]--;
    }
    memset(dp,-1,sizeof dp);
    cout<<recur(sx,sy,0);
}
