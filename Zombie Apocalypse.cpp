#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x, y;
} cur;
node z[3000];
int N, M, K,Q;
int xtot = 1, ytot = 1;
short g[4010][4010];
long long lx, rx, by, ty;
long long tmp;
long long getarea(int q)
{
    vector <int> xm(4010,0),ym(4010,0); map <int,int> mx, my;
    xtot = 0; ytot = 0;
    for (int i = 0; i < K; i++)
    {
        lx = max(1,z[i].x - q), rx = min(M,z[i].x+q);
        ty = min(N,z[i].y + q), by = max(1,z[i].y-q);
        mx[lx] = mx[rx+1] = 0; my[by] = my[ty+1] = 0;
    }
    for (auto& i : mx) {xtot++; i.second = xtot; xm[xtot] = i.first;}
    for (auto& i : my) {ytot++; i.second = ytot; ym[ytot] = i.first;}
    long long ans = 0;
    memset(g,0,sizeof g);
    for (int i = 0; i < K; i++)
    {
        lx = max(1,z[i].x - q), rx = min(M,z[i].x+q);
        ty = min(N,z[i].y + q), by = max(1,z[i].y-q);
        g[mx[lx]][my[by]] += 1;
        g[mx[rx+1]][my[by]] -= 1;
        g[mx[lx]][my[ty+1]] -= 1;
        g[mx[rx+1]][my[ty+1]] += 1;
    }
    for (int i = 1; i < xtot; i++)
    {
        long long l = (xm[i+1]-xm[i]), h = 0;
        for (int j = 1; j < ytot; j++)
        {
            g[i][j] += g[i-1][j];
            g[i][j] += g[i][j-1];
            g[i][j] -= g[i-1][j-1];
            if (g[i][j])
            {
                h += (ym[j+1]-ym[j]);
            }
        }
        ans += l * h;
    }
    return ans;
}
int main()
{
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < K; i++)
    {
        scanf("%d%d", &cur.y, &cur.x);
        z[i]=cur;
    }
    cin>>Q;
    if (Q==0)
    {
        cout<<K<<"\n";
        return 0;
    }
    long long ans = getarea(Q) - getarea(Q-1);
    cout<<ans<<endl;
    return 0;
}

